// 盈利计划(多维费用背包)
// 集团里有 n 名员工，他们可以完成各种各样的工作创造利润
// 第 i 种工作会产生 profit[i] 的利润，它要求 group[i] 名成员共同参与
// 如果成员参与了其中一项工作，就不能参与另一项工作
// 工作的任何至少产生 minProfit 利润的子集称为 盈利计划
// 并且工作的成员总数最多为 n
// 有多少种计划可以选择？因为答案很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/profitable-schemes/

#include<vector>
#include<string>
namespace
{
    //暴力递归
    class Solution1 {
    public:
        const int mod = 1000000007;

        int f(int staffs, int curProfit, int i, std::vector<int>& group, std::vector<int>& profit)
        {
            if (i < 0)
            {
                if (curProfit == 0)
                {
                    return 1;
                }

                return 0;
            }

            int p1 = f(staffs, curProfit, i - 1, group, profit);
            int p2 = 0;
            if (group[i] <= staffs)
            {
               int newProfit = curProfit - profit[i];
               if (newProfit < 0)
               {
                   newProfit = 0;
               }
               p2 = f(staffs - group[i], newProfit, i - 1, group, profit);
            }
            return (p1%mod+p2%mod)%mod;
        }

        int profitableSchemes(int n, int minProfit, std::vector<int>& group, std::vector<int>& profit) {
            
            return f(n, minProfit, group.size() - 1, group, profit);
        }
    };

    //记忆化搜索
    class Solution2 {
    public:
        const int mod = 1000000007;

        int f(int staffs, int curProfit, int i, std::vector<int>& group, std::vector<int>& profit, std::vector<std::vector<std::vector<int>>>& dp)
        {
            if (i < 0)
            {
                if (curProfit == 0)
                {
                    return 1;
                }

                return 0;
            }
            if (dp[staffs][curProfit][i] != -1)
            {
                return dp[staffs][curProfit][i];
            }


            int p1 = f(staffs, curProfit, i - 1, group, profit,dp);
            int p2 = 0;
            if (group[i] <= staffs)
            {
                int newProfit = curProfit - profit[i];
                if (newProfit < 0)
                {
                    newProfit = 0;
                }
                p2 = f(staffs - group[i], newProfit, i - 1, group, profit,dp);
            }
            int ans = (p1 % mod + p2 % mod) % mod;
            dp[staffs][curProfit][i] = ans;
            return ans;
        }

        int profitableSchemes(int n, int minProfit, std::vector<int>& group, std::vector<int>& profit) {
            std::vector<std::vector<std::vector<int>>> dp(n+1,std::vector<std::vector<int>>(minProfit+1,std::vector<int>(group.size(),-1)));
            return f(n, minProfit, group.size() - 1, group, profit,dp);
        }
    };

    //dp
    class Solution3 {
    public:
        const int mod = 1000000007;
        int profitableSchemes(int n, int minProfit, std::vector<int>& group, std::vector<int>& profit) {
            std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(minProfit + 1, std::vector<int>(group.size()+1)));
            for (int i = 0; i <= n; i++)
            {
                dp[i][0][group.size()] = 1;
            }

            for (int k = group.size() - 1; k >= 0; k--)
            {
                for (int i = 0; i <= n; i++)
                {
                    for (int j = 0; j <= minProfit; j++)
                    {
                        int p1 =dp[i][j][k+1];
                        int p2 = 0;
                        if (group[k] <= i)
                        {
                            int newProfit = j - profit[k];
                            if (newProfit < 0)
                            {
                                newProfit = 0;
                            }
                            p2 = dp[i-group[k]][newProfit][k+1];
                        }
                        int ans = (p1 % mod + p2 % mod) % mod;
                        dp[i][j][k] = ans;
                    }
                }
            }
            return dp[n][minProfit][0];
        }
    };
}