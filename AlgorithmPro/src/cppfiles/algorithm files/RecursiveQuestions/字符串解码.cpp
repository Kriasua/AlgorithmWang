//https://leetcode.cn/problems/decode-string/description/
/*给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 
正好重复 k 次。注意 k 保证为正整数。你可以认为输入字符串总是有效的；
输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，
例如不会出现像 3a 或 2[4] 的输入。*/

#include<string>
#include "pch.h"
namespace welly
{
    class Solution {
    public:
        int where;
        std::string f(std::string& s, int i)
        {
            std::string path;
            int cnt = 0;
            while (i < s.size() && s[i] != ']')
            {
                if (s[i] >= 'a' && s[i] <= 'z')
                {
                    path.push_back(s[i++]);
                }

                else if (s[i] >= '0' && s[i] <= '9')
                {
                    cnt = cnt * 10 + (s[i++] - '0');
                }
                
                else
                {
                    std::string str = f(s, i + 1);

                    for (int i = 0; i < cnt; i++)
                    {
                        path += str;
                    }

                    cnt = 0;
                    i = where + 1;
                }
            }

            where = i;
            return path;
        }

        std::string decodeString(std::string s) {
            where = 0;
            return f(s, 0);
        }
    };
}