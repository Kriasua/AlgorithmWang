// 目标和
// 给你一个非负整数数组 nums 和一个整数 target 。
// 向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数
// 可以构造一个表达式
// 例如nums=[2, 1]，可以在2之前添加'+' ，在1之前添加'-'
// 然后串联起来得到表达式 "+2-1" 。
// 返回可以通过上述方法构造的，运算结果等于 target 的不同表达式的数目
// 测试链接 : https://leetcode.cn/problems/target-sum/

#include<vector>
#include<unordered_map>
namespace
{
	//暴力递归
	class Solution1 {
	public:
		int f(std::vector<int>& nums, int target, int i, int sum)
		{
			if (i == nums.size())
			{
				return sum == target ? 1 : 0;
			}

			return f(nums, target, i + 1, sum + nums[i]) + f(nums, target, i + 1, sum - nums[i]);
		}

		int findTargetSumWays(std::vector<int>& nums, int target) {
			return f(nums, target, 0, 0);
		}
	};

	//记忆化搜索，用哈希表
	class Solution1 {
	public:
		int f(std::vector<int>& nums, int target, int i, int sum, std::unordered_map<int, std::unordered_map<int, int>>& dp)
		{
			if (i == nums.size())
			{
				return sum == target ? 1 : 0;
			}
	
			auto it1 = dp.find(i);
			if (it1 != dp.end())
			{
				auto& map = it1->second;
				auto it2 = map.find(sum);
				if (it2 != map.end())
				{
					return it2->second;
				}
			}

			int ans = f(nums, target, i + 1, sum + nums[i], dp) + f(nums, target, i + 1, sum - nums[i], dp);
			dp[i][sum] = ans;
			return ans;
		}

		int findTargetSumWays(std::vector<int>& nums, int target) {
			std::unordered_map<int, std::unordered_map<int, int>> dp; 
			return f(nums, target, 0, 0, dp);
		}
	};

	//转化01背包问题，然后用动态规划（优雅！）
	class Solution3 {
	public:
		int findTargetSumWays(std::vector<int>& nums, int target) {
			int n = nums.size();
			int allSum = 0;
			for (int num : nums)
			{
				allSum += num;
			}

			if ((target + allSum) % 2 != 0 || std::abs(target) > allSum)
			{
				return 0;
			}

			int p = (target + allSum) / 2;
			std::vector<std::vector<int>> dp(p+1, std::vector<int>(n+1));
			dp[0][0] = 1;
			for (int i = 1; i <= n; i++)
			{
				for (int sum = 0; sum <= p; sum++)
				{
					dp[sum][i] = dp[sum][i - 1];
					if (sum >= nums[i - 1])
					{
						dp[sum][i] += dp[sum - nums[i-1]][i - 1];
					}
				}
			}
			return dp[p][n];

		}
	};

	
}