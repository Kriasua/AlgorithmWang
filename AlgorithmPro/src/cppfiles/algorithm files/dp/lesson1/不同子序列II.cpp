// 不同的子序列 II
// 给定一个字符串 s，计算 s 的 不同非空子序列 的个数
// 因为结果可能很大，答案对 1000000007 取模
// 字符串的 子序列 是经由原字符串删除一些（也可能不删除）
// 字符但不改变剩余字符相对位置的一个新字符串
// 例如，"ace" 是 "abcde" 的一个子序列，但 "aec" 不是
// 测试链接 : https://leetcode.cn/problems/distinct-subsequences-ii/

#include<string>
#include<vector>
namespace
{
    class Solution {
    public:
        using LL = long long int;
        int mod = 1000000007;
        int distinctSubseqII(std::string s) {
            int n = s.size();

            if (n == 1)
            {
                return 1;
            }

            std::vector<LL> dp(26);
            LL purenew;
            LL all=2;
            dp[s[0] - 'a'] = 1;
            for (int i = 1; i < n; i++)
            {
                int cur = s[i] - 'a';
                purenew = (all + mod - dp[cur]) % mod;
                dp[cur] = (dp[cur] + purenew) % mod;
                all = (all + purenew) % mod;
            }
            return (all + mod - 1) % mod;
        }
    };
}