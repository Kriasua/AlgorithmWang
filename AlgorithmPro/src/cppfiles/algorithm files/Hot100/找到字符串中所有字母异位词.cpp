//找到字符串中所有字母异位词
//https://leetcode.cn/problems/find-all-anagrams-in-a-string/description/?envType=study-plan-v2&envId=top-100-liked
#include<string>
#include<vector>

namespace
{
	class Solution {
	public:
		std::vector<int> findAnagrams(std::string s, std::string p) {
			std::vector<int> ans;
			std::vector<int> map(26);
			int m = s.size();
			int n = p.size();

			if (m < n)
			{
				return ans;
			}

			for (char c : p)
			{
				map[c - 'a']--;
			}

			int debt = 0;
			for (int num : map)
			{
				if (num != 0)
				{
					debt++;
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (map[s[i] - 'a'] == 0)
				{
					debt++;
				}

				else if (map[s[i] - 'a'] == -1)
				{
					debt--;
				}

				map[s[i] - 'a']++;
			}

			if (debt == 0)
			{
				ans.push_back(0);
			}

			for (int i = n; i <= m - 1; i++)
			{
				int index = s[i] - 'a';
				if (map[index] == -1)
				{
					debt--;
				}
				else if (map[index] == 0)
				{
					debt++;
				}
				map[index]++;


				index = s[i - n] - 'a';
				if (map[index] == 1)
				{
					debt--;
				}
				else if (map[index] == 0)
				{
					debt++;
				}
				map[index]--;

				if (debt == 0)
				{
					ans.push_back(i - n + 1);
				}
			}

			return ans;


		}
	};
}