// ȥ���ظ���ĸ��֤ʣ���ַ������ֵ�����С
// ����һ���ַ��� s ������ȥ���ַ������ظ�����ĸ��ʹ��ÿ����ĸֻ����һ��
// �豣֤ ���ؽ�����ֵ�����С
// Ҫ���ܴ��������ַ������λ��
// �������� : https://leetcode.cn/problems/remove-duplicate-letters/

#include<array>
#include<string>
#include<vector>
namespace
{
	class Solution {
	public:
		std::string removeDuplicateLetters(std::string s) {

			std::vector<char> stack;//creat monotonicstack
			stack.resize(s.size());
			std::array<int, 26> map;//��Ƶ��
			std::array<int, 26> contain;//ջ�����Ƿ��Ѿ�������ĳ���ַ�
			std::fill(map.begin(), map.end(), 0);
			std::fill(contain.begin(), contain.end(), 0);

			int size = 0;

			for (char c : s)
			{
				map[c - 'a']++;
			}

			for (char c : s)
			{
				map[c - 'a']--;
				if (contain[c - 'a'] == 1)
				{
					continue;
				}

				while (size > 0 && map[stack[size - 1] - 'a'] > 0 && c < stack[size - 1])
				{
					contain[stack[--size] - 'a']--;
				}

				stack[size++] = c;
				contain[c - 'a']++;
			}

			std::string ans;
			for (int i = 0; i < size; i++)
			{
				ans += stack[i];
			}

			return ans;

		}
	};

}
