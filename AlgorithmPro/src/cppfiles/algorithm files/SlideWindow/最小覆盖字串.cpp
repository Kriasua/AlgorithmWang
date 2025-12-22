// 最小覆盖子串
// 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串
// 如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。
// 测试链接 : https://leetcode.cn/problems/minimum-window-substring/
#include<string>
#include<array>
namespace
{
    class Solution {
    public:

        std::string minWindow(std::string s, std::string t) {
            if (s.size() < t.size())
            {
                return "";
            }

            std::array<int, 256> cnts;
            std::string ans;
            std::fill(cnts.begin(), cnts.end(), 0);
            int debt = t.size();
            int start = 0;
            int length = INT_MAX;

            for (char a : t)
            {
                cnts[a]--;
            }

            for (int l = 0, r = 0; r < s.size(); r++)
            {
                if (cnts[s[r]]++ < 0)
                {  
                    debt--;
                }
                
                while (cnts[s[l]] - 1 >= 0)
                {
                    cnts[s[l]]--;
                    l++;
                }
               
                if (debt <= 0)
                {
                    if (r - l + 1 < length)
                    {
                        start = l;
                        length = r - l + 1;
                    }
                }
            }

            if (length == INT_MAX)
            {
                return "";
            }

            ans = s.substr(start, length);

            return ans;
        }
    };
}



