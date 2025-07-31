// 滑动窗口最大值（单调队列经典用法模版）
// 给你一个整数数组 nums，有一个大小为 k 的滑动窗口从数组的最左侧移动到数组的最右侧
// 你只可以看到在滑动窗口内的 k 个数字。滑动窗口每次只向右移动一位。
// 返回 滑动窗口中的最大值 。
// 测试链接 : https://leetcode.cn/problems/sliding-window-maximum/
#include<vector>
namespace
{
	class Solution {
	public:
		std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
			std::vector<int> ans;
			if (nums.size() == 0)
			{
				return ans;
			}
			std::vector<int> queue;
			int qL = 0;
			int qR = 0;
			queue.resize(nums.size());
			int wL = 0;
			int wR = 0;
			queue[0] = 0;
			for (; wR < k; wR++)
			{
				while (qR > qL && nums[wR] >= nums[queue[qR - 1]])
				{
					qR--;
				}
				queue[qR++] = wR;
			}
			ans.push_back(nums[queue[qL]]);
			for (; wR < nums.size(); wR++, wL++)
			{
				while (qR > qL && nums[wR] >= nums[queue[qR - 1]])
				{
					qR--;
				}
				queue[qR++] = wR;
				if (queue[qL] == wL)
				{
					qL++;
				}
				ans.push_back(nums[queue[qL]]);
			}
			return ans;
		}
	};
}

