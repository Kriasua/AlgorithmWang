// 喧闹和富有
// 从 0 到 n - 1 编号，其中每个人都有不同数目的钱，以及不同程度的安静值
// 给你一个数组richer，其中richer[i] = [ai, bi] 表示 
// person ai 比 person bi 更有钱
// 还有一个整数数组 quiet ，其中 quiet[i] 是 person i 的安静值
// richer 中所给出的数据 逻辑自洽
// 也就是说，在 person x 比 person y 更有钱的同时，不会出现
// person y 比 person x 更有钱的情况
// 现在，返回一个整数数组 answer 作为答案，其中 answer[x] = y 的前提是,
// 在所有拥有的钱肯定不少于 person x 的人中，
// person y 是最安静的人（也就是安静值 quiet[y] 最小的人）。
// 测试链接 : https://leetcode.cn/problems/loud-and-rich/

#include<vector>

namespace
{
	using std::vector;
	class Solution {
	public:
		vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
			int n = quiet.size();

			vector<vector<int>> graph;
			vector<int> queue;
			vector<int> inDegree;
			vector<int> ans;

			graph.resize(n);
			queue.resize(n);
			inDegree.resize(n);
			ans.resize(n);

			int l = 0;
			int r = 0;		

			//建图，入度表
			for (auto& relation : richer)
			{
				inDegree[relation[1]]++;
				graph[relation[0]].push_back(relation[1]);
			}

			//初始化答案数组
			for (int i = 0; i < n; i++)
			{
				ans[i] = i;
				if (inDegree[i] == 0)
				{
					queue[r++] = i;
				}
			}

			int cur;

			while (l < r)
			{
				cur = queue[l++];
				for (int num : graph[cur])
				{
					if (--inDegree[num] == 0)
					{
						queue[r++] = num;
					}

					if (quiet[ans[cur]] < quiet[ans[num]])
					{
						ans[num] = ans[cur];
					}
				}
			}

			return ans;
		}
	};
}