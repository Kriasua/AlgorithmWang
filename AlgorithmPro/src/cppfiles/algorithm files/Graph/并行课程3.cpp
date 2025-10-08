// 并行课程 III
// 给你一个整数 n ，表示有 n 节课，课程编号从 1 到 n
// 同时给你一个二维整数数组 relations ，
// 其中 relations[j] = [prevCoursej, nextCoursej]
// 表示课程 prevCoursej 必须在课程 nextCoursej 之前 完成（先修课的关系）
// 同时给你一个下标从 0 开始的整数数组 time
// 其中 time[i] 表示完成第 (i+1) 门课程需要花费的 月份 数。
// 请你根据以下规则算出完成所有课程所需要的 最少 月份数：
// 如果一门课的所有先修课都已经完成，你可以在 任意 时间开始这门课程。
// 你可以 同时 上 任意门课程 。请你返回完成所有课程所需要的 最少 月份数。
// 注意：测试数据保证一定可以完成所有课程（也就是先修课的关系构成一个有向无环图）
// 测试链接 : https://leetcode.cn/problems/parallel-courses-iii/

#include<vector>

namespace
{
	using std::vector;
	class Solution {
	public:
		int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {

			vector<vector<int>> graph;
			vector<int> queue;
			vector<int> inDegree;
			vector<int> message;
			int ans = 0;

			graph.resize(n+1);
			queue.resize(n+1);
			inDegree.resize(n+1);
			message.resize(n + 1);

			int l = 0;
			int r = 0;

			//建图
			for (auto& relation : relations)
			{
				inDegree[relation[1]]++;
				graph[relation[0]].push_back(relation[1]);
			}

			for (int i = 1; i <=n; i++)
			{
				if (inDegree[i] == 0)
				{
					queue[r++] = i;
				}

				message[i] = time[i - 1];
			}


			int cur;
			while (l < r)
			{
				cur = queue[l++];
				if (graph[cur].empty())
				{
					ans = std::max(ans, message[cur]);
				}
				else
				{
					for (int num : graph[cur])
					{
						if (--inDegree[num] == 0)
						{
							queue[r++] = num;
						}

						if ((message[cur] + time[num - 1]) > message[num])
						{
							message[num] = message[cur] + time[num - 1];
						}
					}
				}
			}

			return ans;

		}
	};
}