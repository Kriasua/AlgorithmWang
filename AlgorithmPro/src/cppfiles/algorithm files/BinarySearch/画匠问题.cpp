// 分割数组的最大值(画匠问题)
// 给定一个非负整数数组 nums 和一个整数 m
// 你需要将这个数组分成 m 个非空的连续子数组。
// 设计一个算法使得这 m 个子数组各自和的最大值最小。
// 测试链接 : https://leetcode.cn/problems/split-array-largest-sum/

#include<vector>
namespace
{
	using LL = long long int;
	class Solution {

	public:
		int splitArray(std::vector<int>& nums, int k) {
			LL ans = 0;
			LL l = 0;
			LL r = 0;
			LL m;
			for (int num : nums)
			{
				r += num;
			}

			while (l <= r)
			{
				m = l + ((r - l) >> 1);
				int need = f(nums, m);
				if (need <= k)
				{
					ans = m;
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}

			return (int)ans;
		}

		int f(std::vector<int>& nums, LL limit)
		{
			LL sum = 0;
			int ans = 1;
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] > limit)
				{
					return INT_MAX;
				}
				else if ((sum + nums[i]) <= limit)
				{
					sum += nums[i];
				}
				else
				{
					sum = nums[i];
					ans++;
				}
			}

			return ans;
		}
	};

	class Solution2 {
	public:
		int splitArray(std::vector<int>& nums, int k) {
			int Min = INT_MAX;
			int Max = 0;
			LL sum = 0;
			for (int num : nums)
			{
				Min = std::min(Min, num);
				Max = std::max(Max, num);
				sum += num;
			}

			int left = Max;
			int right = sum;
			int ans = INT_MAX;
			while (left <= right)
			{
				int middle = left + (right - left) / 2;
				int curSplit = f(middle, nums);
				if (curSplit <= k)
				{
					ans = middle;
					right = middle - 1;
				}
				else
				{
					left = middle + 1;
				}
			}

			return ans;

		}

		int f(LL limit, std::vector<int>& nums)
		{
			int ans = 0;
			int curSum = 0;
			for (int num : nums)
			{
				if (curSum + num <= limit)
				{
					curSum += num;
				}
				else
				{
					ans++;
					curSum = num;
				}
			}

			if (curSum != 0)
			{
				ans++;
			}

			return ans;
		}
	};
}