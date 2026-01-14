// 买卖股票的最佳时机 IV
// 给你一个整数数组 prices 和一个整数 k ，其中 prices[i] 是某支给定的股票在第 i 天的价格
// 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易
// 也就是说，你最多可以买 k 次，卖 k 次
// 注意：你不能同时参与多笔交易，你必须在再次购买前出售掉之前的股票
// 测试链接 : https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iv/

#include<vector>
namespace
{
	class Solution {
	public:
		int maxProfit(int k, std::vector<int>& prices) {
			int n = prices.size();
			if (n == 0)
			{
				return 0;
			}

			std::vector<std::vector<int>> dp(2 * k + 1, std::vector<int>(n + 1));
			for (int i = n - 1; i >= 0; i--)
			{
				for (int cnt = 1; cnt <= 2 * k; cnt++)
				{
					int p1 = dp[cnt][i + 1];
					int p2 = 0;
					if (cnt % 2 == 0)
					{
						p2 = dp[cnt - 1][i + 1] - prices[i];
					}
					else
					{
						p2 = dp[cnt - 1][i + 1] + prices[i];
					}
					dp[cnt][i] = std::max(p1, std::max(p2, 0));
				}
			}
			return dp[2 * k][0];
		}
	};
}