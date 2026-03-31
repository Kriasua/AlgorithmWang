//和为K的子数组
//https://leetcode.cn/problems/subarray-sum-equals-k/description/?envType=study-plan-v2&envId=top-100-liked
#include<vector>
#include<unordered_map>

namespace 
{
	class Solution {
	public:
		int subarraySum(std::vector<int>& nums, int k) {
			std::unordered_map<int, int> map;
			map[0] = 1;
			int curSum = 0;
			int ans = 0;
			for (int num : nums)
			{
				curSum += num;
				int target = curSum - k;

				if (map.contains(target))
				{
					ans += map[target];
				}

				if (map.contains(curSum))
				{
					map[curSum]++;
				}
				else
				{
					map[curSum] = 1;
				}
			}

			return ans;
		}
	};
}