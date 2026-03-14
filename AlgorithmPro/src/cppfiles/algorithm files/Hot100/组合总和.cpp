//组合总和
//https://leetcode.cn/problems/combination-sum/description/?envType=study-plan-v2&envId=top-100-liked
#include<vector>

namespace
{
	class Solution {
	public:

		void f(std::vector<int>& nums, std::vector<std::vector<int>>& ans, std::vector<int>& combination, int i, int sum, int target)
		{
			if (sum == target)
			{
				ans.push_back(combination);
				return;
			}

			if (i == nums.size() || sum > target)
			{
				return;
			}

			f(nums, ans, combination, i + 1, sum, target);
			combination.push_back(nums[i]);
			f(nums, ans, combination, i, sum + nums[i], target);
			combination.pop_back();
		}

		std::vector<std::vector<int>> combinationSum(std::vector<int>& nums, int target) {
			std::vector<std::vector<int>> ans;
			std::vector<int> combination;
			f(nums, ans, combination, 0, 0, target);
			return ans;
		}
	};
}
