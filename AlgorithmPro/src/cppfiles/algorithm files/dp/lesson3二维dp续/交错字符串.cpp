// 交错字符串
// 给定三个字符串 s1、s2、s3
// 请帮忙验证s3是否由s1和s2交错组成
// 测试链接 : https://leetcode.cn/problems/interleaving-string/

#include<vector>
#include<string>
namespace
{
    class Solution {
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) {
            int n1 = s1.size();
            int n2 = s2.size();
            int n3 = s3.size();
            if (n1 + n2 != n3)
            {
                return false;
            }

            std::vector<std::vector<bool>> dp(n1 + 1, std::vector<bool>(n2 + 1));
            dp[0][0] = true;
            bool ans = true;

            //填basecase
            for (int i = 1; i <= n1; i++)
            {
                //只要中间有一个位置对不上，后面就全是false
                if (s1[i - 1] != s3[i - 1])
                {
                    ans = false;
                }

                dp[i][0] = ans;
            }

            //填basecase
            ans = true;
            for (int i = 1; i <= n2; i++)
            {
                //只要中间有一个位置对不上，后面就全是false
                if (s2[i - 1] != s3[i - 1])
                {
                    ans = false;
                }

                dp[0][i] = ans;
            }


            for (int i = 1; i <= n1; i++)
            {
                for (int j = 1; j <= n2; j++)
                {
                    if (s3[i + j - 1] != s1[i - 1] && s3[i + j - 1] != s2[j - 1])
                    {
                        dp[i][j] = false;
                    }
                    else
                    {
                        if ((s3[i + j - 1] == s1[i - 1] && dp[i - 1][j])
                            ||
                            (s3[i + j - 1] == s2[j - 1] && dp[i][j - 1]))
                        {
                            dp[i][j] = true;
                        }
                        else
                        {
                            dp[i][j] = false;
                        }
                    }

                }
            }
            return dp[n1][n2];
        }
    };
}

