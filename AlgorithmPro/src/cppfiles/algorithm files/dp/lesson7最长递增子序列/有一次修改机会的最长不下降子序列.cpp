// 有一次修改机会的最长不下降子序列
// 给定一个长度为n的数组arr，和一个整数k
// 只有一次机会可以将其中连续的k个数全修改成任意一个值
// 这次机会你可以用也可以不用，请返回最长不下降子序列长度
// 1 <= k, n <= 10^5
// 1 <= arr[i] <= 10^6
// 测试链接 : https://www.luogu.com.cn/problem/P8776

#include<vector>
#include<iostream>
namespace
{
	constexpr int MAXN = 100001;
	int k, n;
	std::vector<int> nums;
	std::vector<int> ends;
	std::vector<int> right;
	int ans = 0;

	int bsup(int i, int size)
	{
		int l = 0;
		int r = size - 1;
		int pos = r;
		while (l <= r)
		{
			int middle = l + (r - l >> 1);
			if (ends[middle] > nums[i])
			{
				pos = middle;
				r = middle - 1;
			}
			else
			{
				l = middle + 1;
			}
		}
		return pos;
	}

	int bsdown(int i, int size)
	{
		int l = 0;
		int r = size - 1;
		int pos = r;
		while (l <= r)
		{
			int middle = l + (r - l >> 1);
			if (ends[middle] < nums[i])
			{
				pos = middle;
				r = middle - 1;
			}
			else
			{
				l = middle + 1;
			}
		}
		return pos;
	}

	void rightarr()
	{
		ends[0] = nums[n - 1];
		right[n - 1] = 1;
		int endsize = 1;
		for (int i = n - 2; i >= k; i--)
		{
			if (nums[i] <= ends[endsize - 1])
			{
				ends[endsize++] = nums[i];
				right[i] = endsize;
			}
			else
			{
				int pos = bsdown(i, endsize);
				right[i] = pos + 1;
				ends[pos] = nums[i];
			}
		}
		ends.clear();
	}

	void lis()
	{
		rightarr();
		ans = k + right[k];
		ends[0] = nums[0];
		int endsize = 1;
		for (int i = k + 1; i < n; i++)
		{
			int left = 0;
			if (nums[i] >= ends[endsize - 1])
			{
				left = endsize;
			}
			else
			{
				left = bsup(i, endsize);
			}
			ans = std::max(ans, left + k + right[i]);

			if (nums[i - k] >= ends[endsize - 1])
			{
				ends[endsize++] = nums[i - k];
			}
			else
			{
				ends[bsup(i - k, endsize)] = nums[i - k];
			}
		}
		ans = std::max(ans, endsize + k);
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		nums.resize(MAXN);
		ends.resize(MAXN);
		right.resize(MAXN);

		while (std::cin >> n >> k)
		{
			ans = 0;
			for (int i = 0; i < n; i++)
			{
				std::cin >> nums[i];
			}
			lis();
			std::cout << ans << "\n";
		}
	}
}

