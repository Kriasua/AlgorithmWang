// 给定一个背包的容量t，一共有n种货物，并且给定每种货物的信息
// 花费(cost)、价值(val)、数量(cnt)
// 如果cnt == 0，代表这种货物可以无限选择
// 如果cnt > 0，那么cnt代表这种货物的数量
// 挑选货物的总容量在不超过t的情况下，返回能得到的最大价值
// 背包容量不超过1000，每一种货物的花费都>0
// 测试链接 : https://www.luogu.com.cn/problem/P1833

#include<iostream>
#include<vector>
namespace
{
	int sH, sM, eH, eM;
	char colon;
	int n, times;
	constexpr int MAXN = 100005;
	constexpr int MAXT = 1005;
	std::vector<int> costs;
	std::vector<int> values;
	std::vector<int> dp;
	int index;

	int compute()
	{
		std::fill(dp.begin(), dp.begin() + times + 1, 0);
		for (int i = 1; i < index; i++)
		{
			for (int cur = times; cur >= 0; cur--)
			{
				if (cur >= costs[i])
				{
					dp[cur] = std::max(dp[cur], dp[cur - costs[i]] + values[i]);
				}
			}
		}
		return dp[times];
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);

		costs.resize(MAXN);
		values.resize(MAXN);
		dp.resize(MAXT);
		int T, C, P;
		while (std::cin >> sH >> colon >> sM >> eH >> colon >> eM >> n)
		{
			times = (eH * 60 + eM) - (sH * 60 + sM);
			index = 1;
			for (int i = 1; i <= n; i++)
			{
				std::cin >> T >> C >> P;
				//这朵花能看无数次
				if (P == 0)
				{
					P = times / T;
				}
				int count = P;
				int bin = 1;
				while (count >= bin)
				{
					values[index] = C * bin;
					costs[index++] = T * bin;
					count -= bin;
					bin = bin << 1;
				}

				if (count != 0)
				{
					values[index] = C * count;
					costs[index++] = T * count;
				}
			}
			std::cout << compute() << "\n";
		}

	}
}