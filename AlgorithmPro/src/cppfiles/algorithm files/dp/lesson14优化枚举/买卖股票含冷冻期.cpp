// 买卖股票的最佳时机含冷冻期
// 给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格
// 设计一个算法计算出最大利润
// 在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
// 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)
// 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/

#include<vector>
namespace
{
	class Solution {
	public:
		int maxProfit(std::vector<int>& prices) {
			int n = prices.size();
			if (n == 0)
			{
				return 0;
			}

			//三种状态 ： 0.持有股票  1.没有，不在冷冻期   2.没有，在冷冻期
			std::vector<std::vector<int>> dp(3, std::vector<int>(n));
			dp[0][n - 1] = prices[n - 1];
			dp[1][n - 1] = 0;
			dp[1][n - 1] = 0;
			for (int j = n - 2; j >= 0; j--)
			{
				dp[0][j] = std::max(dp[0][j + 1], std::max(dp[2][j + 1] + prices[j], 0));
				dp[1][j] = std::max(dp[1][j + 1], std::max(dp[0][j + 1] - prices[j], 0));
				dp[2][j] = std::max(dp[1][j + 1], 0);
			}

			return dp[1][0];
		}
	};
}