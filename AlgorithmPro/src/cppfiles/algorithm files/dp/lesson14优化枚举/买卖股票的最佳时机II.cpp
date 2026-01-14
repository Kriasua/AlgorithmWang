// 买卖股票的最佳时机 II
// 给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格
// 在每一天，你可以决定是否购买和/或出售股票
// 你在任何时候 最多 只能持有 一股 股票
// 你也可以先购买，然后在 同一天 出售
// 返回 你能获得的 最大 利润
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/

#include<vector>
namespace
{
	class Solution1 {
	public:
		int maxProfit(std::vector<int>& prices) {
			int n = prices.size();
			if (n == 0)
			{
				return 0;
			}

			//只有两种状态，持有股票和不持有，所以是2
			std::vector<std::vector<int>> dp(2, std::vector<int>(n));
			dp[0][n - 1] = prices[n - 1];
			dp[1][n - 1] = 0;
			for (int j = n - 2; j >= 0; j--)
			{
				dp[0][j] = std::max(dp[0][j + 1], std::max(dp[1][j + 1] + prices[j], 0));
				dp[1][j] = std::max(dp[1][j + 1], std::max(dp[0][j + 1] - prices[j], 0));
			}

			return dp[1][0];
		}
	};

}