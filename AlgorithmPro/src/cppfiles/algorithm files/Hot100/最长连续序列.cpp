//https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-100-liked
//最长连续序列
#include<vector>
#include<unordered_map>

namespace
{
	class Solution {
	public:
		int longestConsecutive(std::vector<int>& nums) {
			int ans = 0;
			std::unordered_map<int, int> map;
			int n = nums.size();
			for (int i = 0; i < n; i++)
			{
				if (map.contains(nums[i]))
				{
					continue;
				}
				else if (!map.contains(nums[i]) && !map.contains(nums[i] + 1) && !map.contains(nums[i] - 1))
				{
					map[nums[i]] = 1;
					ans = std::max(ans, 1);
				}
				else if (!map.contains(nums[i]) && !map.contains(nums[i] + 1) && map.contains(nums[i] - 1))
				{
					int left = nums[i] - map[nums[i] - 1];
					map[left]++;
					map[nums[i]] = map[left];
					ans = std::max(ans, map[left]);
				}
				else if (!map.contains(nums[i]) && map.contains(nums[i] + 1) && !map.contains(nums[i] - 1))
				{
					int right = nums[i] + map[nums[i] + 1];
					map[right]++;
					map[nums[i]] = map[right];
					ans = std::max(ans, map[right]);
				}
				else if (!map.contains(nums[i]) && map.contains(nums[i] + 1) && map.contains(nums[i] - 1))
				{
					int left = nums[i] - map[nums[i] - 1];
					int right = nums[i] + map[nums[i] + 1];
					int sum = map[left] + map[right] + 1;
					map[left] = sum;
					map[right] = sum;
					map[nums[i]] = sum;
					ans = std::max(ans, sum);
				}
				else
				{

				}
			}

			return ans;
		}
	};
}