// 到达首都的最少油耗
// 给你一棵 n 个节点的树（一个无向、连通、无环图）
// 每个节点表示一个城市，编号从 0 到 n - 1 ，且恰好有 n - 1 条路
// 0 是首都。给你一个二维整数数组 roads
// 其中 roads[i] = [ai, bi] ，表示城市 ai 和 bi 之间有一条 双向路
// 每个城市里有一个代表，他们都要去首都参加一个会议
// 每座城市里有一辆车。给你一个整数 seats 表示每辆车里面座位的数目
// 城市里的代表可以选择乘坐所在城市的车，或者乘坐其他城市的车
// 相邻城市之间一辆车的油耗是一升汽油
// 请你返回到达首都最少需要多少升汽油
// 测试链接 : https://leetcode.cn/problems/minimum-fuel-cost-to-report-to-the-capital/


#include<vector>
namespace
{
	class Solution {
	public:
		using LL = long long;

		struct Info
		{
			LL cost;
			int people;
		};

		Info f(std::vector<std::vector<int>>& tree, std::vector<bool>& visited, int node, int seats)
		{
			if (visited[node] == true)
			{
				return { 0,0 };
			}

			visited[node] = true;
			int people = 1;
			LL cost = 0;
			for (int num : tree[node])
			{
				Info it = f(tree, visited, num, seats);
				people += it.people;
				cost += it.cost;
				cost += (it.people + seats - 1) / seats;
			}
			return { cost,people };
		}

		LL minimumFuelCost(std::vector<std::vector<int>>& roads, int seats) {
			int n = roads.size() + 1;
			std::vector<std::vector<int>> tree(n);
			std::vector<bool> visited(n,false);

			for (auto& road : roads)
			{
				tree[road[0]].push_back(road[1]);
				tree[road[1]].push_back(road[0]);
			}

			Info info = f(tree, visited, 0, seats);
			return info.cost;
		}
	};
}