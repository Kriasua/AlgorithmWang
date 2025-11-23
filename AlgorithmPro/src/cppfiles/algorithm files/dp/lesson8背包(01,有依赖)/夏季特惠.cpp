// 夏季特惠
// 某公司游戏平台的夏季特惠开始了，你决定入手一些游戏
// 现在你一共有X元的预算，平台上所有的 n 个游戏均有折扣
// 标号为 i 的游戏的原价a_i元，现价只要b_i元
// 也就是说该游戏可以优惠 a_i - b_i，并且你购买该游戏能获得快乐值为w_i
// 由于优惠的存在，你可能做出一些冲动消费导致最终买游戏的总费用超过预算
// 只要满足 : 获得的总优惠金额不低于超过预算的总金额
// 那在心理上就不会觉得吃亏。
// 现在你希望在心理上不觉得吃亏的前提下，获得尽可能多的快乐值。
// 测试链接 : https://leetcode.cn/problems/tJau2o/

#include<vector>
#include<iostream>
namespace
{
	using LL = long long int;
	constexpr int MAXN = 505;
	constexpr int MAXX = 100005;
	int n, X;
	std::vector<int> a;
	std::vector<int> b;
	std::vector<LL> w;
	std::vector<int> assistcost;
	std::vector<LL> assistvalue;
	std::vector<std::vector<LL>> dp;

	int f(int i, int rest, int discount)
	{
		if (i == n + 1)
		{
			//没有超预算
			if (rest >= 0)
			{
				return 0;
			}
			else
			{
				//心理上觉得不亏
				if (discount + rest >= 0)
				{
					return 0;
				}
				else
				{
					return INT_MIN;
				}
			}
		}

		int p1 = f(i + 1, rest, discount);
		int p2 = f(i + 1, rest - b[i], discount + (a[i] - b[i])) + w[i];

		int ans = std::max(p1, p2);
		return ans;
	}

	int dpSolution()
	{
		int index = 0;
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			int actualCost = a[i] - 2 * b[i];
			if (actualCost >= 0)
			{
				ans += w[i];
				X += actualCost;
			}
			else
			{
				assistcost[index] = -actualCost;
				assistvalue[index++] = w[i];
			}
		}

		for (int rest = 0; rest <= X; rest++)
		{
			dp[rest][index] = 0;
		}

		for (int i = index - 1; i >= 0; i--)
		{
			for (int rest = 0; rest <= X; rest++)
			{

				int p1 = dp[rest][i+1];
				int p2 = 0;
				if (rest >= assistcost[i])
				{
					p2 = assistvalue[i] + dp[rest - assistcost[i]][i + 1];
				}
				dp[rest][i] = std::max(p1, p2);
			}
		}

		return dp[X][0] + ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		a.resize(MAXN);
		b.resize(MAXN);
		w.resize(MAXN);
		assistcost.resize(MAXN);
		assistvalue.resize(MAXN);
		dp.resize(MAXX, std::vector<LL>(MAXN));

		while (std::cin >> n >> X)
		{
			for (int i = 0; i < n; i++)
			{
				std::cin >> a[i] >> b[i] >> w[i];
			}

			std::cout << dpSolution() << "\n";
		}
	}
}