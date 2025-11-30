// 混合背包 + 多重背包普通窗口优化
// 能成功找零的钱数种类
// 每一种货币都给定面值val[i]，和拥有的数量cnt[i]
// 想知道目前拥有的货币，在钱数为1、2、3...m时
// 能找零成功的钱数有多少
// 也就是说当钱数的范围是1~m
// 返回这个范围上有多少可以找零成功的钱数
// 比如只有3元的货币，数量是5张
// m = 10
// 那么在1~10范围上，只有钱数是3、6、9时，可以成功找零
// 所以返回3表示有3种钱数可以找零成功
// 测试链接 : http://poj.org/problem?id=1742

#include<iostream>
#include<vector>

namespace
{
	int n, m;
	constexpr int MAXN = 105;
	constexpr int MAXM = 100005;
	std::vector<int> values;
	std::vector<int> counts;
	std::vector<std::vector<bool>> dp;

	int compute()
	{
		for (int i = 1; i <= n; i++)
		{
			//01背包
			if (counts[i] == 1)
			{
				for (int cur = 0; cur <= m; cur++)
				{
					dp[i][cur] = dp[i - 1][cur];
					if (cur >= values[i])
					{
						dp[i][cur] = dp[i][cur] || dp[i-1][cur - values[i]];
					}
				}
			}
			//完全背包
			else if (values[i] * counts[i] >= m)
			{
				for (int cur = 0; cur <= m; cur++)
				{
					dp[i][cur] = dp[i - 1][cur];
					if (cur >= values[i])
					{
						dp[i][cur] = dp[i][cur] || dp[i][cur - values[i]];
					}
				}
			}
			//多重背包
			else
			{
				for (int mod = 0; mod <= std::min(values[i] - 1, m); mod++)
				{
					int trueCounts = 0;
					for (int cur = mod; cur <= m; cur += values[i])
					{
						if (dp[i - 1][cur])
						{
							trueCounts++;
						}
						int expired = cur - (counts[i] + 1) * values[i];
						if (expired >= 0 && dp[i-1][expired])
						{
							trueCounts--;
						}

						dp[i][cur] = trueCounts > 0 ? true : false;
					}
				}
			}
		}
		int ans = 0;
		for (bool is : dp[n])
		{
			if (is)
			{
				ans++;
			}
		}
		return ans - 1;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		values.resize(MAXN);
		counts.resize(MAXN);
		dp.resize(MAXN, std::vector<bool>(MAXM,false));
		dp[0][0] = true;

		while (true)
		{
			std::cin >> n >> m;
			if (n == 0 && m == 0)
			{
				break;
			}

			for (int i = 1; i <= n; i++)
			{
				std::cin >> values[i];
			}

			for (int i = 1; i <= n; i++)
			{
				std::cin >> counts[i];
			}

			std::cout <<compute()<< "\n";
		}

		return 0;
	}
}