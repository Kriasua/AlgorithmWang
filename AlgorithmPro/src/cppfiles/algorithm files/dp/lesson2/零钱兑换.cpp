//给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
//计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 - 1 。
//你可以认为每种硬币的数量是无限的。
//测试链接：https://leetcode.cn/problems/coin-change/description/

#include<vector>
#include<algorithm>
#include<functional>
namespace
{
	//暴力递归
	class Solution1 {
	public:
		int f(std::vector<int>& coins, int i, int rest)
		{
			if (rest == 0)
			{
				return 0;
			}

			if (i == coins.size())
			{
				return INT_MAX;
			}

			int p1 = INT_MAX;
			if (rest - coins[i] >= 0)
			{
				p1 = f(coins, i, rest - coins[i]);
				p1 = p1 == INT_MAX ? INT_MAX : p1 + 1;
			}

			int p2 = f(coins, i + 1, rest);
			return std::min(p1, p2);
		}

		int coinChange(std::vector<int>& coins, int amount) {
			int ans = f(coins, 0, amount);
			return ans == INT_MAX ? -1 : ans;

		}
	};

	//正宗动态规划
	class Solution2 {
	public:
		int coinChange(std::vector<int>& coins, int amount) {
			std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1));
			for (int& num : dp[coins.size()])
			{
				num = INT_MAX;
			}
			dp[coins.size()][0] = 0;
			for (int i = coins.size() - 1; i >= 0; i--)
			{
				for (int j = 0; j <= amount; j++)
				{
					int p1 = INT_MAX;
					if (j - coins[i] >= 0)
					{
						p1 = dp[i][j - coins[i]];
						p1 = p1 == INT_MAX ? INT_MAX : p1 + 1;
					}

					int p2 = dp[i + 1][j];
					dp[i][j] = std::min(p1, p2);
				}
			}

			return dp[0][amount] == INT_MAX ? -1 : dp[0][amount];
		}
	};
}