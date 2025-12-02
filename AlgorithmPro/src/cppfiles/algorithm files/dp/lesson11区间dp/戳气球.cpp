// 戳气球
// 有 n 个气球，编号为0到n-1，每个气球上都标有一个数字，这些数字存在数组nums中
// 现在要求你戳破所有的气球。戳破第 i 个气球
// 你可以获得 nums[i - 1] * nums[i] * nums[i + 1] 枚硬币
// 这里的 i - 1 和 i + 1 代表和 i 相邻的两个气球的序号
// 如果 i - 1或 i + 1 超出了数组的边界，那么就当它是一个数字为 1 的气球
// 求所能获得硬币的最大数量
// 测试链接 : https://leetcode.cn/problems/burst-balloons/

#include<vector>
namespace
{
	//记忆化搜索
	class Solution1 {
	public:
		//必须设定 nums[l-1]一定没爆！
		// 一定有 : nums[r+1]一定没爆！
		// 才能调f()，否则不能调
		// 必须得设定尝试是每个气球最后打爆
		int f(std::vector<int>& nums, int l, int r, std::vector<std::vector<int>>& dp)
		{
			if (l == r)
			{
				return nums[l] * nums[l - 1] * nums[l + 1];
			}

			if (dp[l][r] != -1)
			{
				return dp[l][r];
			}

			int twoSide = nums[l - 1] * nums[r + 1];

			int ans = std::max( nums[l] * twoSide + f(nums,l+1,r,dp),
				nums[r] * twoSide + f(nums,l,r-1,dp));

			for (int i = l + 1; i < r; i++)
			{
				ans = std::max(ans, twoSide * nums[i] + f(nums, l, i - 1, dp) + f(nums, i + 1, r, dp));
			}

			dp[l][r] = ans;
			return ans;
		}

		int maxCoins(std::vector<int>& ballons) {
			//预处理
			std::vector<int> nums(ballons.size() + 2);
			int n = nums.size();
			nums[0] = 1;
			for(int i=1;i<n-1;i++)
			{
				nums[i] = ballons[i - 1];
			}
			nums[n - 1] = 1;

			std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));
			return f(nums, 1, n - 2, dp);
		}
	};

	//动态规划
	class Solution2 {
	public:
		int maxCoins(std::vector<int>& ballons) {
			//预处理
			std::vector<int> nums(ballons.size() + 2);
			int n = nums.size();
			nums[0] = 1;
			for (int i = 1; i < n - 1; i++)
			{
				nums[i] = ballons[i - 1];
			}
			nums[n - 1] = 1;

			std::vector<std::vector<int>> dp(n, std::vector<int>(n));
			for (int i = 1; i <= n - 2; i++)
			{
				dp[i][i] = nums[i] * nums[i - 1] * nums[i + 1];
			}

			for (int l = n - 3; l >= 1; l--)
			{
				for (int r = l + 1; r < n - 1; r++)
				{
					int twoSide = nums[l - 1] * nums[r + 1];
					int ans = std::max(nums[l] * twoSide + dp[l + 1][r],
						nums[r] * twoSide + dp[l][r - 1]);

					for (int i = l + 1; i < r; i++)
					{
						ans = std::max(ans, twoSide * nums[i] + dp[l][i - 1]+dp[i + 1][r]);
					}

					dp[l][r] = ans;
				}
			}
			return dp[1][n - 2];
		}
	};
}