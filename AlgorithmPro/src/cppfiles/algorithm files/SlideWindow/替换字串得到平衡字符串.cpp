// 替换子串得到平衡字符串
// 有一个只含有 'Q', 'W', 'E', 'R' 四种字符，且长度为 n 的字符串。
// 假如在该字符串中，这四个字符都恰好出现 n/4 次，那么它就是一个「平衡字符串」。
// 给你一个这样的字符串 s，请通过「替换一个子串」的方式，使原字符串 s 变成一个「平衡字符串」。
// 你可以用和「待替换子串」长度相同的 任何 其他字符串来完成替换。
// 请返回待替换子串的最小可能长度。
// 如果原字符串自身就是一个平衡字符串，则返回 0。
// 测试链接 : https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

#include<string>
#include<array>
#include<unordered_map>
namespace
{
    class Solution {
    public:

        int build(std::array<int, 4>& cnts, std::string& s)
        {
            for (char c : s)
            {
                if (c == 'Q')
                {
                    cnts[0]++;
                }
                else if (c == 'W')
                {
                    cnts[1]++;
                }
                else if (c == 'E')
                {
                    cnts[2]++;
                }
                else
                {
                    cnts[3]++;
                }
            }
            int debt = 0;
            for (int& num : cnts)
            {
                num -= (s.size() / 4);
                debt += num <= 0 ? 0 : num;
            }
            return debt;
        }

        int index(char c)
        {
            if (c == 'Q')
            {
                return 0;
            }
            else if (c == 'W')
            {
                return 1;
            }
            else if (c == 'E')
            {
                return 2;
            }
            else
            {
                return 3;
            }
        }

        int balancedString(std::string s) {
            std::array<int, 4> cnts;
            int debt = build(cnts, s);
            if (debt == 0)
            {
                return 0;
            }
            int left = 0; 
            int right = 0;
            int ans = INT_MAX;
            for (; right < s.size(); right++)
            {
                if (cnts[index(s[right])]-- > 0)
                {
                    debt--;
                }

                if (debt <= 0)
                {
                    while (cnts[index(s[left])]+1 <= 0)
                    {
                        cnts[index(s[left])]++;
                        left++;
                    }

                    ans = std::min(ans, right - left + 1);
                }
            }
            return ans;
        }
    };

	class Solution2 {
	public:
		int balancedString(std::string s) {
            int n = s.size() / 4;
            std::unordered_map<char, int> map;
            for (char c : s)
            {
                if (map.contains(c))
                {
                    map[c]++;
                }
                else
                {
                    map[c] = 1;
                }
            }

            int need = 0;
            for (auto& kv : map)
            {
                kv.second -= n;
                if (kv.second >= 0)
                {
                    need += kv.second;
                }
            }

            if (need == 0)
            {
                return 0;
            }

            int ans = INT_MAX;
            int l = 0; 
            int r = 0;
            for (; r < s.size(); r++)
            {
                if (map.contains(s[r]))
                {
                    map[s[r]]--;
                    if (map[s[r]] >= 0)
                    {
                        need--;
                    }
                }

                while (need == 0 && l <= r)
                {
                    ans = std::min(ans, (r - l + 1));
                    if (map.contains(s[l]))
                    {
                        map[s[l]]++;
                        if (map[s[l]] > 0)
                        {
                            need++;
                        }
                    }
                    l++;
                }
            }
            return ans;
		}
	};
}