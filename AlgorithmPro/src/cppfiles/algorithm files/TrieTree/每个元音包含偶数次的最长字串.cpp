#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
#include<string>
#include<array>

namespace
{
    class Solution {
    public:

        int Xor(char a)
        {
            if (a == 'a')
            {
                return 1;
            }
            else if (a == 'e')
            {
                return 1 << 1;
            }
            else if (a == 'i')
            {
                return 1 << 2;
            }
            else if (a == 'o')
            {
                return 1 << 3;
            }
            else if (a == 'u')
            {
                return 1 << 4;
            }
            else
            {
                return 0;
            }
        }

        int findTheLongestSubstring(std::string s) {
            int status = 0;
            std::unordered_map<int, int> map;
            map.emplace(0, -1);
            int ans = 0;
            for (int i = 0; i < s.size(); i++)
            {
                status ^= Xor(s[i]);
                if (map.find(status) != map.end())
                {
                    ans = std::max(ans, i - map[status]);
                }

                if (map.find(status) == map.end())
                {
                    map.emplace(status, i);
                }
            }

            return ans;

        }

        //数组代替哈希表优化版，运行更快
        int findTheLongestSubstring2(std::string s) {
            int status = 0;
            std::array<int,32> map;
            std::fill(map.begin(), map.end(), -2);
            map[0] = -1;
            int ans = 0;
            for (int i = 0; i < s.size(); i++)
            {
                status ^= Xor(s[i]);
                if (map[status] != -2)
                {
                    ans = std::max(ans, i - map[status]);
                }

                if (map[status] == -2)
                {
                    map[status] = i;
                }
            }

            return ans;

        }
    };
}