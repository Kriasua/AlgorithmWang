// 最长有效括号
// 给你一个只包含 '(' 和 ')' 的字符串
// 找出最长有效（格式正确且连续）括号子串的长度。
// 测试链接 : https://leetcode.cn/problems/longest-valid-parentheses/

#include<string>
#include<vector>
namespace
{
    //上来就动态规划了
    class Solution {
    public:
        int longestValidParentheses(std::string s) {
            int n = s.size();
            if (n == 0)
            {
                return 0;
            }

            std::vector<int> dp(n);
            dp[0] = 0;

            for (int i = 1; i < n; i++)
            {
                if (s[i] == '(')
                {
                    dp[i] = 0;
                }
                else
                {
                    //前一个是 (
                    if (s[i - 1] == '(')
                    {
                        if (i >= 2)
                        {
                            dp[i] = dp[i - 2] + 2;
                        }
                        else
                        {
                            dp[i] = 2;
                        }
                    }
                    //前一个是 )
                    else
                    {
                        //比如这种情况，i=2时 "())"
                        if (i - dp[i - 1] - 1 < 0)
                        {
                            dp[i] = 0;
                        }
                        else
                        {
                            if (s[i - dp[i - 1] - 1] == '(')
                            {
                                //如果s[i - dp[i - 1] - 1]是左括号，首先它可以和当前的s[i]右括号配对，所以答案肯定得+2
                                //但是还需要再考虑s[i - dp[i - 1] - 1]的再前一位能有多少个有效括号
                                //因为再前一位的可以一直连接到s[i]
                                //for example "()(())" 当i=5时
                                if (i - dp[i - 1] - 2 >= 0)
                                {
                                    dp[i] = dp[i - 1] + 2 + dp[i - dp[i - 1] - 2];
                                }
                                else
                                {
                                    dp[i] = dp[i - 1] + 2;
                                }
                            }
                            else
                            {
                                dp[i] = 0;
                            }
                        }
                    }
                }
            }


            int ans = 0;
            for (int num : dp)
            {
                ans = std::max(ans, num);
            }
            return ans;
        }
    };
}