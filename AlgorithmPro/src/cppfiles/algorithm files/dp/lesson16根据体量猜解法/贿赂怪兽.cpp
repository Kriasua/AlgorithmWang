// 贿赂怪兽
// 开始时你的能力是0，你的目标是从0号怪兽开始，通过所有的n只怪兽
// 如果你当前的能力小于i号怪兽的能力，则必须付出b[i]的钱贿赂这个怪兽
// 然后怪兽就会加入你，他的能力a[i]直接累加到你的能力上
// 如果你当前的能力大于等于i号怪兽的能力，你可以选择直接通过，且能力不会下降
// 但你依然可以选择贿赂这个怪兽，然后怪兽的能力直接累加到你的能力上
// 返回通过所有的怪兽，需要花的最小钱数
// 测试链接 : https://www.nowcoder.com/practice/736e12861f9746ab8ae064d4aae2d5a9

#include<climits>
#include<iostream>
#include<vector>
namespace
{
	int n;
	constexpr int MAXN = 502;
	std::vector<int> abilities;
	std::vector<int> costs;
	

	//假设当abilities[i]数值很大，costs[i]数值范围不大时可以用这个尝试策略
	int compute1()
	{
		int sum = 0;
		for (int num : costs)
		{
			sum += num;
		}

		//dp[i][j] : 打通0到i号怪兽，所的钱不超过j的情况下，能获得的最大能力值
		std::vector<std::vector<int>> dp(n, std::vector<int>(sum + 1, INT_MIN));

		//dp表第一行
		for (int i = 0; i <= sum; i++)
		{
			dp[0][i] = i < costs[0] ? INT_MIN : abilities[0];
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= sum; j++)
			{
				if (dp[i - 1][j] >= abilities[i])
				{
					dp[i][j] = dp[i - 1][j];
				}

				if ((j >= costs[i]) && (dp[i - 1][j - costs[i]] != INT_MIN))
				{
					dp[i][j] = std::max(dp[i][j], dp[i - 1][j - costs[i]] + abilities[i]);
				}
			}
		}

		for (int i = 0; i <= sum; i++)
		{
			if (dp[n - 1][i] != INT_MIN)
			{
				return i;
			}
		}
		return -1;
	}

	int compute2()
	{
		int sum = 0;
		for (int num : abilities)
		{
			sum += num;
		}

		//dp[i][j] : 打通0到i号怪兽，在能力值j的情况下，所需要的最小钱数
		std::vector<std::vector<int>> dp(n, std::vector<int>(sum + 1, INT_MAX));

		//dp表第一行
		dp[0][abilities[0]] = costs[0];

		for (int i = 1; i < n; i++)
		{
			for (int j = 0; j <= sum; j++)
			{
				int p1 = INT_MAX;
				int p2 = INT_MAX;

				if (dp[i - 1][j] != INT_MAX && j >= abilities[i])
				{
					p1 = dp[i - 1][j];
				}

				if (j >= abilities[i] && dp[i - 1][j - abilities[i]] != INT_MAX)
				{
					p2 = dp[i - 1][j - abilities[i]] + costs[i];
				}

				dp[i][j] = std::min(p1, p2);

			}
		}

		int ans = INT_MAX;
		for (int i = 0; i <= sum; i++)
		{
			ans = std::min(ans, dp[n - 1][i]);
		}

		return ans;

	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		abilities.resize(MAXN);
		costs.resize(MAXN);
		while (std::cin >> n)
		{
			for (int i = 0; i < n; i++)
			{
				std::cin >> abilities[i] >> costs[i];
			}

			std::cout << compute1() << "\n";
		}
	}
}