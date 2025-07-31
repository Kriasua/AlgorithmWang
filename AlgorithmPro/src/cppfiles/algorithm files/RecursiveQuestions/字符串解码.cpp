//https://leetcode.cn/problems/decode-string/description/
/*����һ������������ַ������������������ַ�����
�������Ϊ: k[encoded_string]����ʾ���з������ڲ��� encoded_string 
�����ظ� k �Ρ�ע�� k ��֤Ϊ���������������Ϊ�����ַ���������Ч�ģ�
�����ַ�����û�ж���Ŀո�������ķ��������Ƿ��ϸ�ʽҪ��ġ�
�������Ϊԭʼ���ݲ��������֣����е�����ֻ��ʾ�ظ��Ĵ��� k ��
���粻������� 3a �� 2[4] �����롣*/

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