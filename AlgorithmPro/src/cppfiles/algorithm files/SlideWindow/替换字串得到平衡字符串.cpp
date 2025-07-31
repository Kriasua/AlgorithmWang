// �滻�Ӵ��õ�ƽ���ַ���
// ��һ��ֻ���� 'Q', 'W', 'E', 'R' �����ַ����ҳ���Ϊ n ���ַ�����
// �����ڸ��ַ����У����ĸ��ַ���ǡ�ó��� n/4 �Σ���ô������һ����ƽ���ַ�������
// ����һ���������ַ��� s����ͨ�����滻һ���Ӵ����ķ�ʽ��ʹԭ�ַ��� s ���һ����ƽ���ַ�������
// ������ú͡����滻�Ӵ���������ͬ�� �κ� �����ַ���������滻��
// �뷵�ش��滻�Ӵ�����С���ܳ��ȡ�
// ���ԭ�ַ����������һ��ƽ���ַ������򷵻� 0��
// �������� : https://leetcode.cn/problems/replace-the-substring-for-balanced-string/

#include<string>
#include<array>
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
}