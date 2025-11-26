// 完全背包(模版)
// 给定一个正数t，表示背包的容量
// 有m种货物，每种货物可以选择任意个
// 每种货物都有体积costs[i]和价值values[i]
// 返回在不超过总容量的情况下，怎么挑选货物能达到价值最大
// 返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1616

#include<iostream>
#include<vector>

namespace
{
	constexpr int MAXM = 10005;
	constexpr int MAXT = 10000005;
	int m, t;
	std::vector<int> consume;
	std::vector<int> value;
	std::vector<long long int> dp;

	long long int compute()
	{
		std::fill(dp.begin(), dp.begin() + t + 1, 0);

		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= t; j++)
			{
				if (j >= consume[i])
				{
					dp[j] = std::max(dp[j], dp[j - consume[i]] + value[i]);
				}
			}
		}
		return dp[t];
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		consume.resize(MAXM);
		value.resize(MAXM);
		dp.resize(MAXT);

		while (std::cin >> t >> m)
		{
			for (int i = 1; i <= m; i++)
			{
				std::cin >> consume[i] >> value[i];
			}

			std::cout << compute() << "\n";

		}

	}
}