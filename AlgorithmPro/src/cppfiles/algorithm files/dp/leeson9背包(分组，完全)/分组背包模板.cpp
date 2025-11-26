// 分组背包(模版)
// 给定一个正数m表示背包的容量，有n个货物可供挑选
// 每个货物有自己的体积(容量消耗)、价值(获得收益)、组号(分组)
// 同一个组的物品只能挑选1件，所有挑选物品的体积总和不能超过背包容量
// 怎么挑选货物能达到价值最大，返回最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1757

#include<iostream>
#include<vector>

namespace
{
	constexpr int MAXM = 1005;
	constexpr int MAXN = 1005;
	constexpr int MAXK = 105;
	int m, n;
	std::vector<int> weight;
	std::vector<int> cost;
	std::vector<std::vector<int>> groups;
	std::vector<std::vector<int>> dp;

	void build()
	{
		for (auto& group : groups)
		{
			group.clear();
		}
	}

	int compute(int k)
	{
		//看似三层循环，但复杂度依然是O(mn)
		for (int i = 1; i <= k; i++)
		{
			for (int cur = 0; cur <= m; cur++)
			{
				int ans = dp[i-1][cur];
				for (int num : groups[i])
				{
					if (cur - weight[num] >= 0)
					{
						ans = std::max(ans, dp[i - 1][cur - weight[num]] + cost[num]);
					}
				}
				dp[i][cur] = ans;
			}
		}

		return dp[k][m];
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		weight.resize(MAXN);
		cost.resize(MAXN);
		groups.resize(MAXK);
		dp.resize(MAXK, std::vector<int>(MAXM));

		while (std::cin >> m >> n)
		{
			build();
			int a, b, c;
			int k = 1;
			for (int i = 1; i <= n; i++)
			{
				std::cin >> a >> b >> c;
				weight[i] = a;
				cost[i] = b;
				groups[c].push_back(i);
				k = std::max(k, c);
			}
			std::cout << compute(k) << "\n";


		}

	}
}