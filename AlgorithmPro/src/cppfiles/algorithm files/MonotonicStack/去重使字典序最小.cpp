// 去除重复字母保证剩余字符串的字典序最小
// 给你一个字符串 s ，请你去除字符串中重复的字母，使得每个字母只出现一次
// 需保证 返回结果的字典序最小
// 要求不能打乱其他字符的相对位置
// 测试链接 : https://leetcode.cn/problems/remove-duplicate-letters/

#include<array>
#include<string>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
namespace
{
	class Solution {
	public:
		std::string removeDuplicateLetters(std::string s) {

			std::vector<char> stack;//creat monotonicstack
			stack.resize(s.size());
			std::array<int, 26> map;//词频表
			std::array<int, 26> contain;//栈里面是否已经包含了某个字符
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

	class Solution2 {
	public:
		std::string removeDuplicateLetters(std::string s) {
			std::vector<int> stack(10005);
			int size = 0;
			std::string ans;
			std::unordered_map<char, int> map;
			std::unordered_set<char> set;
			for (char c : s)
			{
				if (map.contains(c))
				{
					map[c]++;
				}
				else
				{
					map.emplace(c, 1);
				}
			}


			for (int i = 0; i < s.size(); i++)
			{
				char c = s[i];
				if (set.contains(c))
				{
					map[c]--;
					continue;
				}

				while (size > 0 && c < s[stack[size - 1]])
				{
					char tmp = s[stack[size - 1]];
					if (map[tmp] == 1)
					{
						break;
					}
					map[tmp]--;
					size--;
					set.erase(tmp);
				}

				stack[size++] = i;
				set.emplace(s[i]);
			}

			for (int i = 0; i < size; i++)
			{
				ans += s[stack[i]];
			}
			return ans;
		}
	};

}
