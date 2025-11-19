// 最长递增子序列和最长不下降子序列
// 给定一个整数数组nums
// 找到其中最长严格递增子序列长度、最长不下降子序列长度
// 测试链接 : https://leetcode.cn/problems/longest-increasing-subsequence/

#include<vector>
namespace
{
	//垃圾解法，复杂度O(n^2)
	class Solution1 {
	public:
		int lengthOfLIS(std::vector<int>& nums) {
			int n = nums.size();
			if (n == 1)
			{
				return 1;
			}

			std::vector<int> dp(n);
			dp[0] = 1;
			int ans = 1;
			for (int i = 1; i < n; i++)
			{
				int max = 0;
				for (int j = i-1; j >= 0; j--)
				{
					if (nums[j] < nums[i])
					{
						max = std::max(max, dp[j]);
					}
				}
				dp[i] = max + 1;
				ans = std::max(ans, dp[i]);
			}
			return ans;
		}
	};

	//贪心 + 二分优化，复杂度O(n*logn)
	class Solution2 {
	public:
		int lengthOfLIS(std::vector<int>& nums) {
			int n = nums.size();
			if (n == 1)
			{
				return 1;
			}
			std::vector<int> ends(n);
			int endsSize = 1;
			ends[0] = nums[0];
			int l, r;
			for (int i = 1; i < n; i++)
			{
				l = 0;
				r = endsSize-1;
				int pos = endsSize - 1;
				if (nums[i] > ends[endsSize - 1])
				{
					ends[endsSize++] = nums[i];
				}
				else
				{
					//二分
					while (l <= r)
					{
						int middle = l + ((r - l) >> 1);
						if (ends[middle] >= nums[i])
						{
							r = middle - 1;
							pos = middle;
						}
						else
						{
							l = middle + 1;
						}
					}
					ends[pos] = nums[i];
				}
			}
			return endsSize;
		}
	};


	//拓展：最长不下降子序列
	class Solution3 {
	public:
		int lengthOfLIS(std::vector<int>& nums) {
			int n = nums.size();
			if (n == 1)
			{
				return 1;
			}
			std::vector<int> ends(n);
			int endsSize = 1;
			ends[0] = nums[0];
			int l, r;
			for (int i = 1; i < n; i++)
			{
				l = 0;
				r = endsSize - 1;
				int pos = endsSize - 1;
				if (nums[i] >= ends[endsSize - 1])
				{
					ends[endsSize++] = nums[i];
				}
				else
				{
					//二分
					while (l <= r)
					{
						int middle = l + ((r - l) >> 1);
						if (ends[middle] > nums[i])
						{
							r = middle - 1;
							pos = middle;
						}
						else
						{
							l = middle + 1;
						}
					}
					ends[pos] = nums[i];
				}
			}
			return endsSize;
		}
	};
}