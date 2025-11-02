// 解码方法 II
// 一条包含字母 A-Z 的消息通过以下的方式进行了 编码 ：
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// 要 解码 一条已编码的消息，所有的数字都必须分组
// 然后按原来的编码方案反向映射回字母（可能存在多种方式）
// 例如，"11106" 可以映射为："AAJF"、"KJF"
// 注意，像 (1 11 06) 这样的分组是无效的，"06"不可以映射为'F'
// 除了上面描述的数字字母映射方案，编码消息中可能包含 '*' 字符
// 可以表示从 '1' 到 '9' 的任一数字（不包括 '0'）
// 例如，"1*" 可以表示 "11"、"12"、"13"、"14"、"15"、"16"、"17"、"18" 或 "19"
// 对 "1*" 进行解码，相当于解码该字符串可以表示的任何编码消息
// 给你一个字符串 s ，由数字和 '*' 字符组成，返回 解码 该字符串的方法 数目
// 由于答案数目可能非常大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/decode-ways-ii/

#include<vector>
#include<string>
namespace
{
    //暴力递归
    class Solution1 {
    public:
        const int mod = 1000000007;
        using LL = long long int;
        LL f(std::string s, int i)
        {
            if (i == s.size())
            {
                return 1;
            }

            LL ans;
            if (s[i] == '0')
            {
                ans = 0;
            }
            else if (s[i] == '*')
            {
                //1~9都可以，所以直接乘9
                ans = (f(s, i + 1) % mod * 9) % mod;
                if (i + 1 < s.size())
                {
                    if (s[i + 1] != '*')
                    {
                        // 把s[i]当成‘1’
                        ans += f(s, i + 2) % mod; 
                        // 把s[i]当成‘2’
                        if (s[i + 1] >= '0' && s[i + 1] <= '6')
                        {
                            ans += f(s, i + 2) % mod;
                        }
                    }
                    else
                    {
                        // 把s[i]和s[i+1]拼成的11 ~ 19  21~26 都行
                        ans += (f(s, i + 2) % mod * 15) % mod;
                    }
                     
                    
                }
            }
            else
            {
                ans = f(s, i + 1);
                if (i + 1 < s.size())
                {
                    if (s[i + 1] != '*')
                    {
                        if (s[i] == '1')
                        {
                            ans += f(s, i + 2) % mod;
                        }
                        else if (s[i] == '2')
                        {
                            if (s[i + 1] >= '0' && s[i + 1] <= '6')
                            {
                                ans += f(s, i + 2) % mod;
                            }
                        }
                    }
                    else
                    {
                        if (s[i] == '1')
                        {
                            //11 ~ 19都行，所以乘9
                            ans += (f(s, i + 2) % mod * 9) % mod;
                        }
                        else if (s[i] == '2')
                        {
                            //21 ~ 26都行，所以乘6
                            ans += (f(s, i + 2) % mod * 6) % mod;
                            
                        }
                    }
                }
            }
            return ans % mod;
        }

        int numDecodings(std::string s) {
            return  f(s, 0);
        }
    };


    //记忆化搜索
    class Solution2 {
    public:
        const int mod = 1000000007;
        using LL = long long int;
        LL f(std::string& s, int i ,std::vector<int>& dp)
        {
            if (i == s.size())
            {
                return 1;
            }

            if (dp[i] != -1)
            {
                return dp[i];
            }

            LL ans;
            if (s[i] == '0')
            {
                ans = 0;
            }
            else if (s[i] == '*')
            {
                //1~9都可以，所以直接乘9
                ans = (f(s, i + 1,dp) % mod * 9) % mod;
                if (i + 1 < s.size())
                {
                    if (s[i + 1] != '*')
                    {
                        // 把s[i]当成‘1’
                        ans += f(s, i + 2, dp) % mod;
                        // 把s[i]当成‘2’
                        if (s[i + 1] >= '0' && s[i + 1] <= '6')
                        {
                            ans += f(s, i + 2, dp) % mod;
                        }
                    }
                    else
                    {
                        // 把s[i]和s[i+1]拼成的11 ~ 19  21~26 都行
                        ans += (f(s, i + 2, dp) % mod * 15) % mod;
                    }


                }
            }
            else
            {
                ans = f(s, i + 1, dp);
                if (i + 1 < s.size())
                {
                    if (s[i + 1] != '*')
                    {
                        if (s[i] == '1')
                        {
                            ans += f(s, i + 2, dp) % mod;
                        }
                        else if (s[i] == '2')
                        {
                            if (s[i + 1] >= '0' && s[i + 1] <= '6')
                            {
                                ans += f(s, i + 2, dp) % mod;
                            }
                        }
                    }
                    else
                    {
                        if (s[i] == '1')
                        {
                            //11 ~ 19都行，所以乘9
                            ans += (f(s, i + 2, dp) % mod * 9) % mod;
                        }
                        else if (s[i] == '2')
                        {
                            //21 ~ 26都行，所以乘6
                            ans += (f(s, i + 2, dp) % mod * 6) % mod;

                        }
                    }
                }
            }
            dp[i] = ans % mod;
            return dp[i];
        }

        int numDecodings(std::string s) {
            std::vector<int> dp(s.size(), -1);
            return  f(s, 0 , dp);
        }
    };

    //正宗动态规划
    class Solution3 {
    public:
        const int mod = 1000000007;
        using LL = long long int;
        int numDecodings(std::string s) {
            int n = s.size();
            std::vector<LL> dp(n+1);
            dp[n] = 1;
            for (int i = n - 1; i >= 0; i--)
            {
                LL ans;
                if (s[i] == '0')
                {
                    ans = 0;
                }
                else if (s[i] == '*')
                {
                    //1~9都可以，所以直接乘9
                    ans = (dp[i+1] % mod * 9) % mod;
                    if (i + 1 < s.size())
                    {
                        if (s[i + 1] != '*')
                        {
                            // 把s[i]当成‘1’
                            ans += dp[i + 2] % mod;
                            // 把s[i]当成‘2’
                            if (s[i + 1] >= '0' && s[i + 1] <= '6')
                            {
                                ans += dp[i + 2] % mod;
                            }
                        }
                        else
                        {
                            // 把s[i]和s[i+1]拼成的11 ~ 19  21~26 都行
                            ans += (dp[i + 2] % mod * 15) % mod;
                        }


                    }
                }
                else
                {
                    ans = dp[i + 1];
                    if (i + 1 < s.size())
                    {
                        if (s[i + 1] != '*')
                        {
                            if (s[i] == '1')
                            {
                                ans += dp[i + 2] % mod;
                            }
                            else if (s[i] == '2')
                            {
                                if (s[i + 1] >= '0' && s[i + 1] <= '6')
                                {
                                    ans += dp[i + 2] % mod;
                                }
                            }
                        }
                        else
                        {
                            if (s[i] == '1')
                            {
                                //11 ~ 19都行，所以乘9
                                ans += (dp[i + 2] % mod * 9) % mod;
                            }
                            else if (s[i] == '2')
                            {
                                //21 ~ 26都行，所以乘6
                                ans += (dp[i + 2] % mod * 6) % mod;

                            }
                        }
                    }
                }
                dp[i] = ans % mod;
            }
            return  dp[0];
        }
    };
}