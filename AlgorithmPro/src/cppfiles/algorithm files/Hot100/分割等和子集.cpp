//分割等和子集
//https://leetcode.cn/problems/partition-equal-subset-sum/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	class Solution {
	public:
		bool canPartition(std::vector<int>& nums) {
			int n = nums.size();
			int sum = 0;
			for (int i = 0; i < n; i++)
			{
				sum += nums[i];
			}

			if ((sum & 1) == 1)
			{
				return false;
			}
			int halfSum = sum / 2;

			std::vector<std::vector<int>> dp(n+1,std::vector<int>(halfSum+1));
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= halfSum; j++)
				{
					int p1 = dp[i - 1][j];
					int p2 = 0;
					if (j >= nums[i - 1])
					{
						p2 = dp[i - 1][j - nums[i - 1]] + nums[i-1];
					}
					dp[i][j] = std::max(p1, p2);
				}
			}

			return dp[n][halfSum] == halfSum;
		}
	};
}