// 子序列累加和必须被7整除的最大累加和
// 给定一个非负数组nums，
// 可以任意选择数字组成子序列，但是子序列的累加和必须被7整除
// 返回最大累加和
// 对数器验证

#include<vector>
namespace
{
	//暴力递归
	class Solution1
	{
	public:
		int f(std::vector<int>& nums, int i, int yu)
		{
			if (i == nums.size())
			{
				if (0 == yu)
				{
					return 0;
				}
				else
				{
					return INT_MIN;
				}
			}

			int need = (yu + 7 - (nums[i] + 7) % 7) % 7;
			int p1 = f(nums, i + 1, yu);
			int p2 = nums[i] + f(nums, i + 1, need);
			return std::max(p1, p2);
		}

		int maxModSeven(std::vector<int>& nums)
		{
			return f(nums, 0, 0);
		}
	};

	//dp
	class Solution2
	{
	public:
		int maxModSeven(std::vector<int>& nums)
		{
			int n = nums.size();
			std::vector<std::vector<int>> dp(7, std::vector<int>(n + 1));

			for (int i = 1; i <= 6; i++)
			{
				dp[i][n] = INT_MIN;
			}

			for (int i = n - 1; i >= 0; i--)
			{
				for (int j = 0; j < 7; j++)
				{
					int need = (j + 7 - (nums[i] + 7) % 7) % 7;
					int p1 = dp[j][i+1];
					int p2 = nums[i] + dp[need][i+1];
					dp[j][i] = std::max(p1, p2);
				}
			}
			return dp[0][0];
		}
	};

}