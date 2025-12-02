// 切棍子的最小成本
// 有一根长度为n个单位的木棍，棍上从0到n标记了若干位置
// 给你一个整数数组cuts，其中cuts[i]表示你需要将棍子切开的位置
// 你可以按顺序完成切割，也可以根据需要更改切割的顺序
// 每次切割的成本都是当前要切割的棍子的长度，切棍子的总成本是历次切割成本的总和
// 对棍子进行切割将会把一根木棍分成两根较小的木棍
// 这两根木棍的长度和就是切割前木棍的长度
// 返回切棍子的最小总成本
// 测试链接 : https://leetcode.cn/problems/minimum-cost-to-cut-a-stick/

#include<vector>
#include<algorithm>
namespace
{
	using std::vector;
	//暴力递归
	class Solution1 {
	public:
		int f(int n, vector<int>& nums, int l, int r, vector<vector<int>>& dp)
		{

			int curCost = nums[r + 1] - nums[l - 1];


			if (l > r)
			{
				return 0;
			}

			if (l == r)
			{
				return curCost;
			}

			if (dp[l][r] != -1)
			{
				return dp[l][r];
			}

			int ans = INT_MAX;

			for (int i = l; i <= r; i++)
			{
				ans = std::min(ans, curCost + f(n, nums, l, i - 1, dp) + f(n, nums, i + 1, r, dp));
			}

			dp[l][r] = ans;

			return ans;
		}

		int minCost1(int n, vector<int>& cuts) {
			if (cuts.size() == 1)
			{
				return n;
			}
			std::sort(cuts.begin(), cuts.end());
			vector<int> nums(cuts.size() + 2);
			nums[0] = 0;
			for (int i = 1; i <= cuts.size(); i++)
			{
				nums[i] = cuts[i - 1];
			}
			nums.back() = n;
			vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
			return f(n, nums, 1, cuts.size(), dp);

		}

	};

	//动态规划
	class Solution2
	{
	public:
		int minCost(int n, vector<int>& cuts) {
			if (cuts.size() == 1)
			{
				return n;
			}
			std::sort(cuts.begin(), cuts.end());
			vector<int> nums(cuts.size() + 2);
			nums[0] = 0;
			for (int i = 1; i <= cuts.size(); i++)
			{
				nums[i] = cuts[i - 1];
			}
			nums.back() = n;
			vector<vector<int>> dp(nums.size(), vector<int>(nums.size()));
			for (int l = 1; l < nums.size() - 1; l++)
			{
				dp[l][l] = nums[l + 1] - nums[l - 1];
			}

			for (int l = nums.size() - 3; l >= 1; l--)
			{
				for (int r = l + 1; r < nums.size() - 1; r++)
				{
					int curCost = nums[r + 1] - nums[l - 1];
					int ans = INT_MAX;

					for (int k = l; k <= r; k++)
					{
						ans = std::min(ans, curCost + dp[l][k - 1] + dp[k + 1][r]);
					}

					dp[l][r] = ans;
				}
			}
			return dp[1][nums.size() - 2];

		}
	};
}