// 可以翻转1次的情况下子数组最大累加和
// 给定一个数组nums，
// 现在允许你随意选择数组连续一段进行翻转，也就是子数组逆序的调整
// 比如翻转[1,2,3,4,5,6]的[2~4]范围，得到的是[1,2,5,4,3,6]
// 返回必须随意翻转1次之后，子数组的最大累加和
// 对数器验证

#include<vector>
namespace
{
	int maxSumAfterReverse(std::vector<int>& nums)
	{
		int n = nums.size();
		std::vector<int> suffix(n);
		suffix[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; i--)
		{
			suffix[i] = std::max(nums[i], suffix[i + 1] + nums[i]);
		}

		int maxEnd = nums[0];
		int lastMax = nums[0];
		int ans = suffix[0];
		for (int i = 1; i < n; i++)
		{
			ans = std::max(ans, maxEnd + suffix[i]);
			lastMax = std::max(nums[i], lastMax + nums[i]);
			maxEnd = std::max(maxEnd, lastMax);
		}
		ans = std::max(ans, maxEnd);
		return ans;
	}
}