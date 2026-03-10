//https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked
#include<vector>
#include<unordered_map>

namespace
{
	class Solution {
	public:
		std::vector<int> twoSum(std::vector<int>& nums, int target) {
			std::unordered_map<int, int> map;
			int n = nums.size();

			for (int i = 0; i < n; i++)
			{
				if (map.contains(target - nums[i]))
				{
					return { i,map[target - nums[i]] };
				}
				else
				{
					map[nums[i]] = i;
				}
			}
			return { 0,0 };
		}
	};
}