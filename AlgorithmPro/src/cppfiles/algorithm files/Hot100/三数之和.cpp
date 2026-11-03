//https://leetcode.cn/problems/3sum/description/?envType=study-plan-v2&envId=top-100-liked

#include<unordered_set>
#include<vector>
#include<set>
#include<algorithm>
using std::vector;
class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		std::unordered_set<int> set;
		std::set<vector<int>> help;
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < nums.size() - 2; i++)
		{
			if (nums[i] > 0)
			{
				break;
			}

			if (i > 0 && nums[i] == nums[i - 1])
			{
				continue;
			}

			int target = -nums[i];
			set.clear();
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (set.contains(target - nums[j]))
				{
					help.insert({ nums[i],nums[j],target - nums[j] });
				}
				
				set.insert(nums[j]);
			}
		}

		for (auto& it : help)
		{
			ans.push_back(it);
		}

		return ans;
	}
};
