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
		int p1 = 0;
		for (int num : nums)
		{
			p1 += num;
		}


	

	}
}