//课程表
//https://leetcode.cn/problems/course-schedule/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	class Solution {
	public:
		bool canFinish(int n, std::vector<std::vector<int>>& prerequisites) {
			std::vector<std::vector<int>> graph;
			std::vector<int> indegree;
			std::vector<int> queue;
			graph.resize(n);
			indegree.resize(n);
			queue.resize(n);
			int left = 0;
			int right = 0;

			//建图
			for (auto& pre : prerequisites)
			{
				graph[pre[1]].push_back(pre[0]);
			}

			//建入度表
			for (int i = 0; i < n; i++)
			{
				for (int num : graph[i])
				{
					indegree[num]++;
				}
			}

			//入度为0的进队列
			for (int i = 0; i < n; i++)
			{
				if (indegree[i] == 0)
				{
					queue[right++] = i;
				}
			}

			while (left < right)
			{
				int temp = queue[left++];
				for (int num : graph[temp])
				{
					indegree[num]--;
					if (indegree[num] == 0)
					{
						queue[right++] = num;
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (indegree[i] != 0)
				{
					return false;
				}
			}

			return true;

		}
	};
}