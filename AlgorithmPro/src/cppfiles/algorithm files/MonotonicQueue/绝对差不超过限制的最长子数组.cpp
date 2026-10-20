// 绝对差不超过限制的最长连续子数组
// 给你一个整数数组 nums ，和一个表示限制的整数 limit
// 请你返回最长连续子数组的长度
// 该子数组中的任意两个元素之间的绝对差必须小于或者等于 limit
// 如果不存在满足条件的子数组，则返回 0
// 测试链接 : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include<vector>

namespace
{
	class Solution {
	public:
		int longestSubarray(std::vector<int>& nums, int limit) {

			std::vector<int> maxQueue;
			std::vector<int> minQueue;
			maxQueue.resize(nums.size());
			minQueue.resize(nums.size());
			int L = 0;
			int R = 0;
			int minH = 0;
			int minT = 0;
			int maxH = 0;
			int maxT = 0;
			int ans = 0;
			for (; R < nums.size(); R++)
			{
				while (maxT > maxH && nums[R] >= nums[maxQueue[maxT - 1]])
				{
					maxT--;
				}
				maxQueue[maxT++] = R;

				while (minT > minH && nums[R] <= nums[minQueue[minT - 1]])
				{
					minT--;
				}
				minQueue[minT++] = R;


				while (L < R && (nums[maxQueue[maxH]] - nums[minQueue[minH]] > limit))
				{
					if (maxQueue[maxH] == L)
					{
						maxH++;
					}

					if (minQueue[minH] == L)
					{
						minH++;
					}
					L++;
				}

				ans = std::max(ans, R - L + 1);
			}

			return ans;

		}
	};

	class Solution2 {
	public:
		int longestSubarray(std::vector<int>& nums, int limit) {
			std::vector<int> minQ(nums.size()+1);
			std::vector<int> maxQ(nums.size()+1);
			int minL = 0;
			int minR = 0;
			int maxL = 0;
			int maxR = 0;

			int l = 0;
			int r = 0;
			int ans = 0;
			for (; r < nums.size(); r++)
			{
				while (maxL < maxR && nums[r] >= nums[maxQ[maxR - 1]])
				{
					maxR--;
				}
				while (minL < minR && nums[r] <= nums[minQ[minR - 1]])
				{
					minR--;
				}

				maxQ[maxR++] = r;
				minQ[minR++] = r;

				while (l < r && std::abs(nums[maxQ[maxL]] - nums[minQ[minL]]) > limit)
				{
					if (maxQ[maxL] == l)
					{
						maxL++;
					}
					if (minQ[minL] == l)
					{
						minL++;
					}
					l++;
				}

				ans = std::max(ans, r - l + 1);
			}
			return ans;
		}
	};
}