// 解码方法
// 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
// 'A' -> "1"
// 'B' -> "2"
// ...
// 'Z' -> "26"
// 要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）
// 例如，"11106" 可以映射为："AAJF"、"KJF"
// 注意，消息不能分组为(1 11 06)，因为 "06" 不能映射为 "F"
// 这是由于 "6" 和 "06" 在映射中并不等价
// 给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数
// 题目数据保证答案肯定是一个 32位 的整数
// 测试链接 : https://leetcode.cn/problems/decode-ways/

#include<vector>
#include<string>

namespace
{
    //暴力递归
    class Solution1 {
    public:
        int f(std::string s, int i)
        {
            if (i == s.size())
            {
                return 1;
            }

            int ans;

            //如果当前是‘0’，那对不起，根本编码不了，直接返回0
            if (s[i] == '0')
            {
                ans = 0;
            }
            else
            {
                //s[i]自己只要不是'0'就一定可以编码成功，跳到i+1
                ans = f(s, i + 1);

                //以下的情况就是在算s[i]和s[i+1]拼起来能不能编码成功
                //如果可以，ans就追加，然后跳到i+2
                if (i + 1 < s.size()) 
                {
                    std::string str; 
                    str.push_back(s[i]); 
                    str.push_back(s[i+1]);
                    if (str >= "10" && str <= "26")
                    {
                        ans += f(s, i + 2);
                    }
                }
            }
            return ans;
        }

        int numDecodings(std::string s) {

            return  f(s, 0);
        }
    };

    //记忆化搜索
    class Solution2 {
    public:
        int f(std::string s, int i, std::vector<int>& dp)
        {
            if (i == s.size())
            {
                return 1;
            }

            if (dp[i] != -1)
            {
                return dp[i];
            }

            int ans;
            if (s[i] == '0')
            {
                ans = 0;
            }
            else
            {
                ans = f(s, i + 1,dp);
                if (i + 1 < s.size())
                {
                    if (s[i] == '1')
                    {
                        ans += f(s, i + 2, dp);
                    }
                    else if (s[i] == '2')
                    {
                        if (s[i + 1] >= '0' && s[i + 1] <= '6')
                        {
                            ans += f(s, i + 2, dp);
                        }
                    }
                }
            }
            dp[i] = ans;
            return ans;
        }

        int numDecodings(std::string s) {
            std::vector<int> dp(s.size(), -1);
            return  f(s, 0 , dp);
        }
    };


    //正宗动态规划
    class Solution3 {
    public:
        int numDecodings(std::string s) {
            int n = s.size();
            std::vector<int> dp(n + 1);
            dp[n] = 1;
            int ans;
            for (int i = n - 1; i >= 0; i--)
            {
                if (s[i] == '0')
                {
                    ans = 0;
                }
                else
                {
                    ans = dp[i+1];
                    if (i + 1 < s.size())
                    {
                        if (s[i] == '1')
                        {
                            ans += dp[i+2];
                        }
                        else if (s[i] == '2' && s[i + 1] <= '6')
                        {                       
                            ans += dp[i + 2];                         
                        }
                    }
                }
                dp[i] = ans;
            }
            return dp[0];
        }
    };
}