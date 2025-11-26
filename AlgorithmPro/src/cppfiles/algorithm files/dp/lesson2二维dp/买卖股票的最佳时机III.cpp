//给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
//设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
//注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
//测试链接：https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/description/

#include<vector>
namespace
{
    //分割dp解法
    class Solution1 {
    public:
        int maxProfit(std::vector<int>& prices) {
            int n = prices.size();
            if (n == 0)
            {
                return 0;
            }

            //第一种情况，只进行一笔交易
            std::vector<std::vector<int>> prefix(3, std::vector<int>(n + 1));
            for (int i = n - 1; i >= 0; i--)
            {
                for (int cnt = 1; cnt <= 2; cnt++)
                {
                    int p1 = prefix[cnt][i + 1];
                    int p2 = 0;
                    if (cnt == 2)
                    {
                        p2 = prefix[cnt - 1][i + 1] - prices[i];
                    }
                    else
                    {
                        p2 = prefix[cnt - 1][i + 1] + prices[i];
                    }
                    prefix[cnt][i] = std::max(p1, std::max(p2, 0));
                }
            }
            int po1 = prefix[2][0];

            //第二种情况，必须进行两笔交易
            int po2 = 0;
            std::vector<std::vector<int>> suffix(3, std::vector<int>(n + 1));
            suffix[1][0] = INT_MIN / 2; 
            suffix[2][0] = 0;
            for (int i = 1; i <= n; i++)
            {       
                {
                    int p1 = suffix[1][i - 1]; 
                    int p2 = 0 - prices[i - 1]; 

                    suffix[1][i] = std::max(p1, p2); 
                }

                {
                    int p1 = suffix[2][i - 1]; 
                    int p2 = suffix[1][i - 1] + prices[i - 1]; 

              
                    suffix[2][i] = std::max(p1, p2); 
                }
            }

            for (int i = 0; i <= n - 2; i++)
            {
                int sum = suffix[2][i] + prefix[2][i];
                po2 = std::max(po2, sum);
            }

            return std::max(po1, po2);

        }
    };

    //状态机dp解法
    class Solution2 {
    public:
        int maxProfit(std::vector<int>& prices) {
            int n = prices.size();
            if (n == 0)
            {
                return 0;
            }

            //第一种情况，只进行一笔交易
            std::vector<std::vector<int>> dp(5, std::vector<int>(n + 1));
            for (int i = n - 1; i >= 0; i--)
            {
                for (int cnt = 1; cnt <= 4; cnt++)
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
            return dp[4][0];
        }
    };


}