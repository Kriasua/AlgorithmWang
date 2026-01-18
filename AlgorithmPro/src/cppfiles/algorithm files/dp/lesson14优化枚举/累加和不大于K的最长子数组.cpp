// 累加和不大于k的最长子数组
// 给定一个无序数组arr，长度为n，其中元素可能是正、负、0
// 给定一个整数k，求arr所有的子数组中累加和不大于k的最长子数组长度
// 要求时间复杂度为O(n)
// 测试链接 : https://www.nowcoder.com/practice/3473e545d6924077a4f7cbc850408ade

#include<vector>
#include<iostream>
namespace
{
	int n, k;
	constexpr int MAXN = 100005;
	std::vector<int> nums;
	std::vector<int> prefix1;
	std::vector<int> prefix2;
	std::vector<int> minSums;
	std::vector<int> minSumends;

	int compute1()
	{
		int ans = 0;
		for (int i = 1; i <= n; i++)
		{
			prefix1[i] = prefix1[i - 1] + nums[i];
			prefix2[i] = prefix1[i] >= prefix2[i - 1] ? prefix1[i] : prefix2[i - 1];
			int target = prefix1[i] - k;
			int left = 0;
			int right = i - 1;
			int pos = -1;
			while (left <= right)
			{
				int middle = left + (right - left) / 2;
				if (prefix2[middle] < target)
				{
					left = middle + 1;
				}
				else
				{
					pos = middle;
					right = middle - 1;
				}
			}

			if (pos != -1)
			{
				ans = std::max(ans, i - pos);
			}
		}
		return ans;
	}

	int compute2()
	{
		minSums[n + 1] = 0;
		minSumends[n + 1] = n + 1;
		minSums[n] = nums[n];
		minSumends[n] = n;
		int ans = 0;
		for (int i = n-1; i >= 1; i--)
		{
			int temp = nums[i] + minSums[i + 1];
			if (nums[i] < temp)
			{
				minSums[i] = nums[i];
				minSumends[i] = i;
			}
			else
			{
				minSums[i] = temp;
				minSumends[i] = minSumends[i + 1];
			}
		}

		int ptr = 1;
		int tempSum = 0;
		while (ptr <= n && (tempSum + minSums[ptr] <= k))
		{
			tempSum += minSums[ptr];
			ptr = minSumends[ptr] + 1;
		}
		ans = ptr - 1;

		for (int i = 2; i <= n;i++)
		{
			if (ptr >= i)
			{
				tempSum -= nums[i - 1];
			}
			else
			{
				ptr = i;
				tempSum = 0;
			}
			
			while (ptr <= n && (tempSum + minSums[ptr] <= k))
			{
				tempSum += minSums[ptr];
				ptr = minSumends[ptr] + 1;
			}
			ans = std::max(ans, ptr - i);
		}
		return ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		nums.resize(MAXN);
		prefix1.resize(MAXN);
		prefix2.resize(MAXN);
		minSums.resize(MAXN);
		minSumends.resize(MAXN);
		while (std::cin >> n >> k)
		{
			for (int i = 1; i <= n; i++)
			{
				std::cin >> nums[i];
			}

			std::cout << compute2() << "\n";
		}
	}
}