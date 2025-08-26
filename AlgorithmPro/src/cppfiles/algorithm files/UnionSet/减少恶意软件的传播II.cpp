// 尽量减少恶意软件的传播 II
// 给定一个由 n 个节点组成的网络，用 n x n 个邻接矩阵 graph 表示
// 在节点网络中，只有当 graph[i][j] = 1 时，节点 i 能够直接连接到另一个节点 j。
// 一些节点 initial 最初被恶意软件感染。只要两个节点直接连接，
// 且其中至少一个节点受到恶意软件的感染，那么两个节点都将被恶意软件感染。
// 这种恶意软件的传播将继续，直到没有更多的节点可以被这种方式感染。
// 假设 M(initial) 是在恶意软件停止传播之后，整个网络中感染恶意软件的最终节点数。
// 我们可以从 initial 中删除一个节点，
// 并完全移除该节点以及从该节点到任何其他节点的任何连接。
// 请返回移除后能够使 M(initial) 最小化的节点。
// 如果有多个节点满足条件，返回索引 最小的节点 。
// initial 中每个整数都不同
// 测试链接 : https://leetcode.cn/problems/minimize-malware-spread-ii/

#include<vector>
#include<unordered_set>
#include<algorithm>
namespace
{
	using std::vector;
	class Solution {
	public:
		int n;
		vector<int> father;
		vector<int> size;
		vector<int> origin;
		vector<int> cnts;
		std::unordered_set<int> set;
		int find(int num)
		{
			if (num == father[num])
			{
				return num;
			}

			int result = find(father[num]);
			father[num] = result;
			return result;
		}

		void Union(int a, int b)
		{
			int fa = find(a);
			int fb = find(b);

			if (fa == fb)
			{
				return;
			}

			father[fa] = fb;
			size[fb] += size[fa];
		}

		int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
			std::sort(initial.begin(), initial.end());
			n = graph.size();
			father.resize(n);
			size.resize(n,1);
			origin.resize(n,-1);
			cnts.resize(initial.size());

			//把感染节点加入哈希表
			for (int num : initial)
			{
				set.emplace(num);
			}

			//初始化并查集
			for (int i = 0; i < n; i++)
			{
				father[i] = i;
			}

			//第一步，先把非initial节点合并
			for (int i = 0; i < n; i++)
			{
				if (set.find(i) != set.end())
				{
					continue;
				}

				for (int j = 0; j <= i; j++)
				{
					if (graph[i][j] == 1 && set.find(j) == set.end())
					{
						Union(i,j);
					}
				}
			}


			//对于每一个initial节点，处理与它连接的集合，标记源头，如果发现有两处及以上源头，记为-2
			for (int num : initial)
			{
				for (int i = 0; i < n; i++)
				{
					if (graph[num][i] == 1 && set.find(i) == set.end())
					{
						int root = find(i);
						if (origin[root] == -1)
						{
							origin[root] = num;
						}
						else if(origin[root] != num)
						{
							origin[root] = -2;
						}
					}
				}
			}

			//统计每一个initial节点最终对答案的贡献
			for (int j = 0;j<initial.size();j++)
			{
				std::unordered_set<int> roots;
				for (int i = 0; i < n; i++)
				{
					if (graph[initial[j]][i] == 1 && set.find(i) == set.end())
					{
						int root = find(i);
						if (origin[root] != -2 && roots.find(root) == roots.end())
						{
							cnts[j] += size[root];
							roots.emplace(root);
						}
					}
				}
			}

			int ans = initial.size() - 1;
			for (int i = initial.size() - 1; i >= 0; i--)
			{
				if (cnts[i] >= cnts[ans])
				{
					ans = i;
				}
			}

			return initial[ans];
			
		}
	};
}