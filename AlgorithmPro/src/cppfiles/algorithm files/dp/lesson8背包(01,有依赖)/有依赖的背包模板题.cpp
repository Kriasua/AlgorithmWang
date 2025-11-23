// 有依赖的背包(模版)
// 物品分为两大类：主件和附件
// 主件的购买没有限制，钱够就可以；附件的购买有限制，该附件所归属的主件先购买，才能购买这个附件
// 例如，若想买打印机或扫描仪这样的附件，必须先购买电脑这个主件
// 以下是一些主件及其附件的展示：
// 电脑：打印机，扫描仪 | 书柜：图书 | 书桌：台灯，文具 | 工作椅：无附件
// 每个主件最多有2个附件，并且附件不会再有附件，主件购买后，怎么去选择归属附件完全随意，钱够就可以
// 所有的物品编号都在1~m之间，每个物品有三个信息：价格v、重要度p、归属q
// 价格就是花费，价格 * 重要度 就是收益，归属就是该商品是依附于哪个编号的主件
// 比如一件商品信息为[300,2,6]，花费300，收益600，该商品是6号主件商品的附件
// 再比如一件商品信息[100,4,0]，花费100，收益400，该商品自身是主件(q==0)
// 给定m件商品的信息，给定总钱数n，返回在不违反购买规则的情况下最大的收益
// 测试链接 : https://www.luogu.com.cn/problem/P1064
// 测试链接 : https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4

#include <iostream>
#include <vector>
#include <array>
namespace
{
	constexpr int MAXM = 65;
	constexpr int MAXN = 33005;
	int n, m;
	std::vector<int> cost;
	std::vector<int> val;
	std::vector<bool> king;
	std::vector<int> fans;
	std::vector<std::array<int,2>> follow;
	std::vector<std::vector<int>> dp;

	void build()
	{
		for (int i = 0; i <= m; i++)
		{
			fans[i] = 0;
			follow[i] = {};
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		cost.resize(MAXM);
		val.resize(MAXM);
		king.resize(MAXM);
		fans.resize(MAXM);
		follow.resize(MAXM);
		dp.resize(MAXM, std::vector<int>(MAXN));

		while (std::cin >> n >> m)
		{
			build();
			int price, importancy, belong;
			for (int i = 1; i <= m; i++)
			{
				std::cin >> price >> importancy >> belong;
				cost[i] = price;
				val[i] = price * importancy;
				king[i] = belong == 0 ? true : false;
				if (belong != 0)
				{
					fans[belong]++;
					follow[belong][fans[belong] - 1] = i;
				}
			}

			for (int i = 1; i <= m; i++)
			{
				for (int cur = 1; cur <= n; cur++)
				{
					//不是主件
					if (!king[i])
					{
						dp[i][cur] = dp[i - 1][cur];
						continue;
					}

					int ans = dp[i - 1][cur];
					//单独只买这个主件的情况
					if (cur >= cost[i])
					{
						ans = std::max(dp[i - 1][cur - cost[i]] + val[i], ans);
					}

					//只有一个附件的情况，这个附件和主件一起买
					if (fans[i] >= 1)
					{
						int indexFu1 = follow[i][0];
						if (cur >= (cost[i] + cost[indexFu1]))
						{
							ans = std::max(ans, dp[i - 1][cur - cost[i] - cost[indexFu1]] + val[i] + val[indexFu1]);
						}

						if (fans[i] == 2)
						{
							int indexFu2 = follow[i][1];
							//买主件和附件2
							if (cur >= (cost[i] + cost[indexFu2]))
							{
								ans = std::max(ans, dp[i - 1][cur - cost[i] - cost[indexFu2]] + val[i] + val[indexFu2]);
							}

							//主件和两个附件全买
							if (cur >= (cost[i] + cost[indexFu2] + cost[indexFu1]))
							{
								ans = std::max(ans, dp[i - 1][cur - cost[i] - cost[indexFu2] - cost[indexFu1]] + val[i] + val[indexFu2] + val[indexFu1]);
							}

						}
					}

					dp[i][cur] = ans;

				}
			}

			std::cout << dp[m][n] << "\n";
		}
	}
}