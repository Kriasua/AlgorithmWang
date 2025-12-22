// 划分为k个相等的子集
// 给定一个整数数组  nums 和一个正整数 k，
// 找出是否有可能把这个数组分成 k 个非空子集，其总和都相等。
// 测试链接 : https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/

#include<vector>
namespace
{
	class Solution {
	public:
		bool f(std::vector<int>& nums, int edge, int n, int rest, int cnts, int status, std::vector<std::vector<int>>& dp)
		{
			if (rest < 0)
			{
				return false;
			}

			if (rest == 0)
			{
				if (cnts != 0)
				{
					return f(nums, edge, n, edge, cnts - 1, status, dp);
				}
				else
				{
					return true;
				}
			}

			if (dp[cnts][status] != -1)
			{
				return dp[cnts][status] == 1;
			}

			bool ans = false;
			for (int i = 0; i < n; i++)
			{
				if (((1 << i) & status) != 0)
				{
					if (f(nums, edge, n, rest - nums[i], cnts, status ^ (1 << i), dp))
					{
						ans = true;
						break;
					}
				}
			}
			dp[cnts][status] = ans == true ? 1 : 0;
			return ans;
		}

		bool canPartitionKSubsets(std::vector<int>& nums, int k) {
			int n = nums.size();
			int sum = 0;
			int max = 0;
			for (int num : nums)
			{
				sum += num;
				max = std::max(max, num);
			}

			if (sum % k != 0)
			{
				return false;
			}

			int edge = sum / k;
			int status = (1 << n) - 1;
			if (max > edge)
			{
				return false;
			}

			std::vector<std::vector<int>> dp(k+1, std::vector<int>(1 << n, -1));
			return f(nums, edge, n, edge, k-1, status, dp);
		}
	};
}