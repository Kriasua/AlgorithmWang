//https://leetcode.cn/problems/group-anagrams/?envType=study-plan-v2&envId=top-100-liked
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

class Solution {
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
		std::unordered_map<std::string, std::vector<int>> map;
		std::vector<std::string> copy = strs;

		for (auto& str : copy)
		{
			std::sort(str.begin(), str.end());
		}

		for (int i = 0; i < copy.size(); i++)
		{
			if (map.contains(copy[i]))
			{
				map[copy[i]].push_back(i);
			}
			else
			{
				map.emplace(copy[i], std::vector<int>{i});
			}
		}

		std::vector<std::vector<std::string>> ans;
		for (auto& it : map)
		{
			std::vector<std::string> tmp;
			for (int num : it.second)
			{
				tmp.push_back(strs[num]);
			}
			ans.push_back(tmp);
		}

		return ans;
	}
};