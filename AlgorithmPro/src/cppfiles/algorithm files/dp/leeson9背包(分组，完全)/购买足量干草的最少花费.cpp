// 购买足量干草的最小花费
// 有n个提供干草的公司，每个公司都有两个信息
// cost[i]代表购买1次产品需要花的钱
// val[i]代表购买1次产品所获得的干草数量
// 每个公司的产品都可以购买任意次
// 你一定要至少购买h数量的干草，返回最少要花多少钱
// 测试链接 : https://www.luogu.com.cn/problem/P2918


#include<iostream>
#include<vector>
#include <algorithm>
#include <climits>
namespace
{
	constexpr int MAXH = 55005;
	constexpr int MAXN = 101;
	int H, N;
	std::vector<int> cost;
	std::vector<int> weight;
	std::vector<std::vector<int>> dp;

	int compute()
	{
		//因为单次购买最多能获得5000个干草，所以超出的部分在5000以内
		//basecase,没有产品可供购买，但又要严格凑齐j数量的干草，无解，只能是整型最大值
		for (int j = 1; j <= H + 5001; j++)
		{
			dp[0][j] = INT_MAX;
		}


		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= H + 5001; j++)
			{
				int p1 = dp[i - 1][j];
				int p2 = INT_MAX;
				if (j >= weight[i])
				{
					p2 = dp[i][j - weight[i]] == INT_MAX ? INT_MAX: dp[i][j - weight[i]] + cost[i];
				}
				dp[i][j] = std::min(p1, p2);
			}
		}

		int ans = INT_MAX;
		//在所有符合条件的格子中(j >= H)找最小值
		for (int i = H; i <= H + 5001; i++)
		{
			ans = std::min(ans, dp[N][i]);
		}
		return ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		cost.resize(MAXN);
		weight.resize(MAXN);
		dp.resize(MAXN, std::vector<int>(MAXH));
		while (std::cin >> N >> H)
		{
			for (int i = 1; i <= N; i++)
			{
				std::cin >> weight[i] >> cost[i];
			}

			std::cout << compute() << "\n";
		}
	}
}