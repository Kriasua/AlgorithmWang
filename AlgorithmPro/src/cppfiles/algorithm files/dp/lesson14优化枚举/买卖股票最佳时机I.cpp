//给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
//你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
//返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。
//测试链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/description/

#include<vector>
namespace
{
    //暴力递归
	class Solution1
	{
	public:
        int f(std::vector<int>& prices, int days, int i, int cnt)
        {
            if (i == days)
            {
                return 0;
            }

            if (cnt == 0)
            {
                return 0;
            }

            int p1 = f(prices, days, i + 1, cnt);
            int p2 = 0;
            if (cnt == 2)
            {
                p2 = f(prices, days, i + 1, cnt - 1) - prices[i];
            }
            else
            {
                p2 = f(prices, days, i + 1, cnt - 1) + prices[i];
            }

            return std::max(p1, std::max(p2, 0));
        }

        int maxProfit(std::vector<int>& prices) {
            int n = prices.size();
            return f(prices, n, 0, 2);
        }
	};

    //动态规划
    class Solution2
    {
    public:
        int maxProfit(std::vector<int>& prices) {
            int n = prices.size();
            std::vector<std::vector<int>> dp(3, std::vector<int>(n + 1));
            for (int i = n-1; i >=0; i--)
            {
                for (int cnt = 1; cnt <= 2; cnt++)
                {
                    int p1 =dp[cnt][i+1];
                    int p2 = 0;
                    if (cnt == 2)
                    {
                        p2 = dp[cnt - 1][i+1] - prices[i];
                    }
                    else
                    {
                        p2 = dp[cnt - 1][i+1] + prices[i];
                    }
                    dp[cnt][i] = std::max(p1, std::max(p2, 0));
                }
            }
            return dp[2][0];
        }
    };
}