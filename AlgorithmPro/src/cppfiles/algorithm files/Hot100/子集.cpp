//×Ó¼¯
//https://leetcode.cn/problems/subsets/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>

namespace
{
	class Solution {
	public:

		void f(std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& subset, int i)
		{
			if (i == nums.size())
			{
				ans.push_back(subset);
				return;
			}

			f(nums, ans, subset, i + 1);
			subset.push_back(nums[i]);
			f(nums, ans, subset, i + 1);
			subset.pop_back();
		}

		std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
			std::vector<std::vector<int>> ans;
			std::vector<int> subset;
			f(nums, ans, subset, 0);
			return ans;
		}
	};
}