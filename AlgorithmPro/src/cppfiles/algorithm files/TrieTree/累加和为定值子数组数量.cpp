#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
namespace
{
	using std::vector;
	
	class Solution {
	public:
		int subarraySum(vector<int>& nums, int k) {
			std::unordered_map<int, int> map;
			map.emplace(0, 1);
			int ans = 0;
			size_t N = nums.size();
			for (int i = 0, sum = 0; i < N; i++)
			{
				sum += nums[i];		
				if (map.find(sum - k) != map.end())
				{
					ans += map[sum - k];
				}

				if (map.find(sum) == map.end())
				{
					map.emplace(sum, 1);
				}
				else
				{
					map[sum]++;
				}

			}
			return ans;
		}
	};

}

