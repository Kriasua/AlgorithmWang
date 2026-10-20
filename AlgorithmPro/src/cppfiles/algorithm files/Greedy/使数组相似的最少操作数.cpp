// 使数组相似的最少操作次数
// 给你两个正整数数组 nums 和 target ，两个数组长度相等
// 在一次操作中，你可以选择两个 不同 的下标 i 和 j
// 其中 0 <= i, j < nums.length ，并且：
// 令 nums[i] = nums[i] + 2 且
// 令 nums[j] = nums[j] - 2
// 如果两个数组中每个元素出现的频率相等，我们称两个数组是 相似 的
// 请你返回将 nums 变得与 target 相似的最少操作次数
// 测试数据保证nums一定能变得与target相似
// 测试链接 : https://leetcode.cn/problems/minimum-number-of-operations-to-make-arrays-similar/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:

		int split(std::vector<int>& nums)
		{
			int oddSize = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				if ((nums[i] & 1) != 0)
				{
					int tmp = nums[i];
					nums[i] = nums[oddSize];
					nums[oddSize] = tmp;
					oddSize++;
				}
			}
			return oddSize;
		}

		long long makeSimilar(std::vector<int>& nums, std::vector<int>& target) {
			int OddSize = split(nums);
			split(target);

			std::sort(nums.begin(), nums.begin() + OddSize);
			std::sort(nums.begin() + OddSize, nums.end());
			std::sort(target.begin(), target.begin() + OddSize);
			std::sort(target.begin() + OddSize, target.end());

			long long ans = 0;
			for (int i = 0; i < nums.size(); i++)
			{
				ans += std::abs(nums[i] - target[i]);
			}

			return ans / 4;
		}
	};
}