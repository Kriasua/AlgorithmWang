// 牛牛的背包问题 & 世界冰球锦标赛
// 牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
// 牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
// 牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。
// 输入描述：
// 输入包括两行
// 第一行为两个正整数n和w(1 <= n <= 30, 1 <= w <= 2 * 10^9),表示零食的数量和背包的容量
// 第二行n个正整数v[i](0 <= v[i] <= 10^9),表示每袋零食的体积
// 输出描述：
// 输出一个正整数, 表示牛牛一共有多少种零食放法。
// 测试链接 : https://www.luogu.com.cn/problem/P4799


#include<vector>
#include<iostream>
#include<algorithm>
namespace
{
	using LL = long long int;
	constexpr int MAXN = 40;
	constexpr int MAXM = 1 << 20;
	std::vector<LL> price;
	std::vector<LL> lsum;
	std::vector<LL> rsum;
	int middle ,N;
	int lcnt;
	int rcnt;
	LL M;

	void dfsl(int i, LL sum, std::vector<LL>& arr)
	{
		if (i == middle)
		{
			if (sum <= M)
			{
				arr[lcnt++] = sum;
			}
			return;
		}


		dfsl(i + 1, sum, arr);
		if (sum + price[i] > M)
		{
			return;
		}
		else
		{
			dfsl(i + 1, sum + price[i], arr);
		}
	}


	void dfsr(int i, LL sum, std::vector<LL>& arr)
	{
		if (i == N)
		{
			if (sum <= M)
			{
				arr[rcnt++] = sum;
			}
			return;
		}

		dfsr(i + 1, sum, arr);
		if (sum + price[i] > M)
		{
			return;
		}
		else
		{
			dfsr(i + 1, sum + price[i], arr);
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		price.resize(MAXN);
		lsum.resize(MAXM);
		rsum.resize(MAXM);
		while (std::cin >> N >> M)
		{
			middle = N / 2;
			for (int i = 0; i < N; i++)
			{
				std::cin >> price[i];
			}

			lcnt = 0;
			rcnt = 0;
			dfsl(0, 0, lsum);
			dfsr(middle, 0, rsum);
			std::sort(lsum.begin(), lsum.begin() + lcnt);
			std::sort(rsum.begin(), rsum.begin() + rcnt);

			int l = 0;
			int r = rcnt-1;
			LL ans = 0;
			for (; l < lcnt; l++)
			{
				while (r>=0 && lsum[l] + rsum[r] > M)
				{
					r--;
				}

				ans += r + 1;
				
			}

			std::cout << ans << "\n";
		}
	}
}




