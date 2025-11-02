// 环绕字符串中唯一的子字符串
// 定义字符串 base 为一个 "abcdefghijklmnopqrstuvwxyz" 无限环绕的字符串
// 所以 base 看起来是这样的：
// "..zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd.."
// 给你一个字符串 s ，请你统计并返回 s 中有多少 不同非空子串 也在 base 中出现
// 测试链接 : https://leetcode.cn/problems/unique-substrings-in-wraparound-string/

#include<string>
#include<vector>
namespace
{
    class Solution {
    public:
        int findSubstringInWraproundString(std::string s) {
            int n = s.size();
            if (n == 1)
            {
                return 1;
            }

            std::vector<int> dp(26);
            for (int l = 0, r = 1; l < n; l++)
            {
                int curletter = s[l] - 'a';
                if (l == r)
                {
                    r++;
                }

                while (r < n &&
                    (s[r] == s[r - 1] + 1 || (s[r] == 'a' && s[r - 1] == 'z'))
                    )
                {
                    r++;
                }
                dp[curletter] = std::max(dp[curletter], r - l);
            }

            int ans = 0;
            for (int num : dp)
            {
                ans += num;
            }
            return ans;
        }
    };
}