// 魔法卷轴
// 给定一个数组nums，其中可能有正、负、0
// 每个魔法卷轴可以把nums中连续的一段全变成0
// 你希望数组整体的累加和尽可能大
// 卷轴使不使用、使用多少随意，但一共只有2个魔法卷轴
// 请返回数组尽可能大的累加和
// 对数器验证

#include<vector>
namespace
{
	int magicRoll(std::vector<int>& nums)
	{
		int n = nums.size();
		if (n == 0)
		{
			return 0;
		}
		if (n == 1)
		{
			return std::max(nums[0], 0);
		}
		//第一种情况，不用卷轴
		int p1 = 0;
		for (int num : nums)
		{
			p1 += num;
		}

		//第二种情况，只用一个卷轴
		int maxPre = nums[0];
		std::vector<int> preFix(n);
		maxPre = std::max(maxPre, 0);
		int sum = nums[0];
		for (int i = 1; i < n; i++)
		{
			sum += nums[i];
			maxPre = std::max(sum, maxPre);
			preFix[i] = std::max(preFix[i - 1] + nums[i], maxPre);
		}
		int p2 = preFix[n - 1];

		//第三种情况，用两个卷轴
		std::vector<int> sufFix(n);
		sum = nums[n-1];
		int maxSur = std::max(0, nums[n - 1]);
		for (int i = n - 2; i >= 0; i--)
		{
			sum += nums[i];
			maxSur = std::max(sum, maxSur);
			sufFix[i] = std::max(sufFix[i + 1] + nums[i], maxSur);
		}
		
		int p3 = INT_MIN;
		for (int i = 0; i <= n - 2; i++)
		{
			p3 = std::max(p3, preFix[i] + sufFix[i + 1]);
		}

		return std::max(p1, std::max(p2, p3));

	}
}