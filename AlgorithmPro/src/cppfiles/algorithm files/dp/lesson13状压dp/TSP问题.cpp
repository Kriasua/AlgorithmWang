// 售货员的难题 - TSP问题
// 某乡有n个村庄(1<=n<=20)，有一个售货员，他要到各个村庄去售货
// 各村庄之间的路程s(1<=s<=1000)是已知的
// 且A村到B村的路程，与B到A的路大多不同(有向带权图)
// 为了提高效率，他从商店出发到每个村庄一次，然后返回商店所在的村，
// 假设商店所在的村庄为1
// 他不知道选择什么样的路线才能使所走的路程最短
// 请你帮他选择一条最短的路
// 测试链接 : https://www.luogu.com.cn/problem/P1171

#include<iostream>
#include<vector>
#include <climits>
namespace
{
	int n, status;
	constexpr int MAXN = 20;
	std::vector<std::vector<int>> graph;
	std::vector<std::vector<int>> dp;

	int compute(int status, int pos)
	{
		//所有的路都走完了
		if (status == (1 << n) - 1)
		{
			return graph[pos][0];
		}

		if (dp[pos][status] != -1)
		{
			return dp[pos][status];
		}
		int ans = INT_MAX;

		for (int i = 0; i < n; i++)
		{
			if (((1 << i) & status) == 0)
			{
				ans = std::min(ans,graph[pos][i] + compute(status | (1 << i), i));
			}
		}
		dp[pos][status] = ans;
		return ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		graph.resize(MAXN, std::vector<int>(MAXN));
		dp.resize(MAXN, std::vector<int>((1 << MAXN) - 1,-1));
		while (std::cin >> n)
		{
			dp.assign(MAXN, std::vector<int>((1 << MAXN) - 1, -1));
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{
					std::cin >> graph[i][j];
				}
			}
			status = 1;
			std::cout << compute(status,0) << "\n";
		}
	}
}