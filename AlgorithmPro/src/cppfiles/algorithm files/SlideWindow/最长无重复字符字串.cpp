// 无重复字符的最长子串
// 给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
// 测试链接 : https://leetcode.cn/problems/longest-substring-without-repeating-characters/
#include<string>
#include<unordered_map>
#include<array>
namespace
{
    class Solution {
    public:
        int lengthOfLongestSubstring(std::string s) {
            std::unordered_map<char, int> map;
            int ans = 0;
            int l = 0;
            int r = 0;
            for (; r < s.size(); r++)
            {          
                auto it = map.find(s[r]);
                if (it != map.end())
                {
                    l = std::max(l, it->second + 1);
                }
                ans = std::max(ans, r - l + 1);
                map[s[r]] = r;
            }

            return ans;
        }

        //用数组代替哈希表优化
        int lengthOfLongestSubstring2(std::string s) {
            std::array<int, 256> map;
            int ans = 0;
            int l = 0;
            int r = 0;
            std::fill(map.begin(), map.end(), -1);
            for (; r < s.size(); r++)
            {
                l = std::max(l, map[s[r]] + 1);
                ans = std::max(ans, r - l + 1);
                map[s[r]] = r;
            }
            return ans;
        }
    };
}