// 不同的子序列
// 给你两个字符串s和t ，统计并返回在s的子序列中t出现的个数
// 答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/distinct-subsequences/

#include<vector>
#include<string>
namespace
{
    class Solution {
    public:
        int numDistinct(std::string s, std::string t) {
            int n = s.size();
            int m = t.size();

            std::vector<std::vector<long long int>> dp(n + 1, std::vector<long long int>(m + 1));
            for (int i = 0; i <= n; i++)
            {
                dp[i][0] = 1;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    dp[i][j] = dp[i - 1][j];
                    if (s[i - 1] == t[j - 1])
                    {
                        dp[i][j] =( (dp[i][j] % INT_MAX) + (dp[i - 1][j - 1] % INT_MAX)) % INT_MAX;
                    }
                }
            }

            return dp[n][m];
        }
    };
}