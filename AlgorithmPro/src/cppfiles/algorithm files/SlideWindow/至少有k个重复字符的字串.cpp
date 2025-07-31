// 至少有K个重复字符的最长子串
// 给你一个字符串 s 和一个整数 k ，请你找出 s 中的最长子串
// 要求该子串中的每一字符出现次数都不少于 k 。返回这一子串的长度
// 如果不存在这样的子字符串，则返回 0。
// 测试链接 : https://leetcode.cn/problems/longest-substring-with-at-least-k-repeating-characters/
#include<string>
#include<vector>
namespace
{
    class Solution {
    public:
        int longestSubstring(std::string s, int k) {
            std::vector<int> map;
            map.resize(26, 0);
            int ans = 0;
            for (int require = 1; require <= 26; require++)
            {
                std::fill(map.begin(), map.end(), 0);
                for (int l = 0, r = 0, collect = 0, satisfy = 0; r < s.size(); r++)
                {
                    map[s[r] - 'a']++;
                    if (map[s[r] - 'a'] == 1)
                    {
                        collect++;
                    }
                    if (map[s[r] - 'a'] == k)
                    {
                        satisfy++;
                    }

                    while (collect > require)
                    {
                        if (map[s[l] - 'a'] == 1)
                        {
                            collect--;
                        }
                        if (map[s[l] - 'a'] == k)
                        {
                            satisfy--;
                        }

                        map[s[l++] - 'a']--;
                    }

                    if (satisfy == require)
                    {
                        ans = std::max(ans, r - l + 1);
                    }
                }
            }
            return ans;
        }
    };
}