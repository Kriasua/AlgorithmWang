// 两个0和1数量相等区间的最大长度
// 给出一个长度为n的01串，现在请你找到两个区间
// 使得这两个区间中，1的个数相等，0的个数也相等
// 这两个区间可以相交，但是不可以完全重叠，即两个区间的左右端点不可以完全一样
// 现在请你找到两个最长的区间，满足以上要求
// 返回区间最大长度
// 来自真实大厂笔试，没有在线测试，对数器验证

#include<vector>
namespace
{
	int maxLength(std::vector<int>& arr)
	{
		
		int left1 = -1;
		int left0 = -1;
		int right1 = -1;
		int right0 = -1;

		int n = arr.size();
		if (n < 2) return 0;

		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 0)
			{
				left0 = i;
				break;
			}
		}

		for (int i = 0; i < n; i++)
		{
			if (arr[i] == 1)
			{
				left1 = i;
				break;
			}
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (arr[i] == 0)
			{
				right0 = i;
				break;
			}
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (arr[i] == 1)
			{
				right1 = i;
				break;
			}
		}

		int ans1 = right0 - left0;
		int ans2 = right1 - left1;
		return ans1 >= ans2 ? ans1 : ans2;
	}
}