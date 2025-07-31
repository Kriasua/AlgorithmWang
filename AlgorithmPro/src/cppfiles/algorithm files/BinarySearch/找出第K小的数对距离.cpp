// 找出第K小的数对距离
// 数对 (a,b) 由整数 a 和 b 组成，其数对距离定义为 a 和 b 的绝对差值。
// 给你一个整数数组 nums 和一个整数 k
// 数对由 nums[i] 和 nums[j] 组成且满足 0 <= i < j < nums.length
// 返回 所有数对距离中 第 k 小的数对距离。
// 测试链接 : https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:

		int f(std::vector<int>& nums, int limit)
		{
			int ans = 0;
			int l = 0;
			int r = 0;
			for (; r < nums.size(); r++)
			{
				while (nums[r] - nums[l] > limit)
				{
					l++;
				}
				ans += r - l;
			}

			return ans;
		}

		int smallestDistancePair(std::vector<int>& nums, int k) {

			std::sort(nums.begin(), nums.end());
			int l = 0;
			int r = nums.back() - nums.front();
			int m = 0;
			int ans = 0;
			while (l <= r)
			{
				m = l + ((r - l) >> 1);
				if (f(nums, m) >= k)
				{
					ans=m;
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}

			return ans;

		}
	};
}