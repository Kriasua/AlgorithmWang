// 合唱队
// 具体描述情打开链接查看
// 测试链接 : https://www.luogu.com.cn/problem/P3205

#include<string>
#include<vector>
#include<iostream>

const int mod = 19650827;
int n;
std::vector<int> nums;
constexpr int MAXN = 1002;
std::vector<std::vector<std::pair<int,int>>> dp;
namespace
{
	int compute()
	{
		if (n == 1)
		{
			return 1;
		}
		for (int l = n - 2; l >= 0; l--)
		{
			for (int r = l+1; r < n; r++)
			{
				if (l == r - 1)
				{
					dp[l][r] = nums[l] < nums[r] ? std::pair<int,int>({1, 1}) : std::pair<int, int>({0, 0});
				}
				else
				{
					int left = 0;
					int right = 0;
					if (nums[l] < nums[l + 1])
					{
						left = (left + dp[l + 1][r].first) % mod;
					}
					if (nums[l] < nums[r])
					{
						left = (left + dp[l + 1][r].second) % mod;
						right = (right + dp[l][r - 1].first) % mod;
					}
					if (nums[r] > nums[r-1])
					{
						right = (right + dp[l][r - 1].second) % mod;
					}
					dp[l][r] = { left % mod,right % mod };
				}
			}
		}

		return (dp[0][n - 1].first + dp[0][n - 1].second) % mod;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		nums.resize(MAXN);
		dp.resize(MAXN, std::vector<std::pair<int, int>>(MAXN));
		while (std::cin >> n)
		{
			for (int i = 0; i < n; i++)
			{
				std::cin >> nums[i];
			}
			std::cout << compute() << "\n";
		}
	}
}