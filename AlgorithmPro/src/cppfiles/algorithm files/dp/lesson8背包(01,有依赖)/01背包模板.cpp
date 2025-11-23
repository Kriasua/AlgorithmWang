// 01背包(模版)
// 给定一个正数t，表示背包的容量
// 有m个货物，每个货物可以选择一次
// 每个货物有自己的体积costs[i]和价值values[i]
// 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
// 返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1048

#include<vector>
#include<iostream>
namespace
{
	constexpr int MAXT = 1001;
	constexpr int MAXM = 101;
	int T, M;
	std::vector<int> costs;
	std::vector<int> values;
	std::vector<std::vector<int>> dp;
	
	int f(int i, int rest)
	{
		if (i == M)
		{
			return 0;
		}

		int p1 = f(i + 1, rest);
		int p2 = 0;
		if (rest >= costs[i])
		{
			p2 = values[i] + f(i + 1, rest - costs[i]);
		}
		return std::max(p1, p2);
	}

	void dpSolution()
	{
		dp.assign(M + 1, std::vector<int>(T + 1, 0));
		for (int i = M - 1; i >= 0; i--)
		{
			for (int rest = 0; rest <= T; rest++)
			{

				int p1 = dp[i + 1][rest];
				int p2 = 0;
				if (rest >= costs[i])
				{
					p2 = values[i] + dp[i + 1][rest - costs[i]];
				}
				dp[i][rest] = std::max(p1, p2);
			}
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		costs.resize(MAXM);
		values.resize(MAXM);
		dp.resize(MAXM, std::vector<int>(MAXT));
		while (std::cin >> T >> M)
		{
			for (int i = 0; i < M; i++)
			{
				std::cin >> costs[i] >> values[i];
			}

			dpSolution();
			std::cout << dp[0][T] << "\n";
		}

	}
}