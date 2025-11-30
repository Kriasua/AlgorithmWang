// 多重背包
// 宝物筛选
// 一共有n种货物, 背包容量为t
// 每种货物的价值(v[i])、重量(w[i])、数量(c[i])都给出
// 请返回选择货物不超过背包容量的情况下，能得到的最大的价值
// 测试链接 : https://www.luogu.com.cn/problem/P1776

#include<iostream>
#include<vector>

namespace
{
	int n, W;
	constexpr int MAXN = 105;
	constexpr int MAXW = 40005;
	std::vector<int> weights;
	std::vector<int> values;
	std::vector<int> counts;
	std::vector<std::vector<int>> dp;
	std::vector<std::pair<int,int>> queue;
	int l, r;

	void queue_push(int index, int num)
	{
		while (l < r && num >= queue[r - 1].second)
		{
			r--;
		}
		queue[r++] = { index,num };
	}


	int compute()
	{
		for (int i = 1; i <= n; i++)
		{
			int weight = weights[i];
			int value = values[i];
			int count = counts[i];
			for (int mod = 0; mod <= std::min(weight - 1, W); mod++)
			{
				l = 0;
				r = 0;
			
				for (int cur = mod; cur <= W; cur += weight)
				{
					queue_push(cur,dp[i - 1][cur] - cur / weight * value);
					if (queue[l].first == cur - (count + 1) * weight)
					{
						l++;
					}
					dp[i][cur] = queue[l].second + cur / weight * value;
				}
			}

		}
		return dp[n][W];
	}


	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		weights.resize(MAXN);
		values.resize(MAXN);
		counts.resize(MAXN);
		queue.resize(MAXW);
		dp.resize(MAXN + 1, std::vector<int>(MAXW));
		while (std::cin >> n >> W)
		{
			for (int i = 1; i <= n; i++)
			{
				std::cin >> values[i] >> weights[i] >> counts[i];
			}
			std::cout << compute() << "\n";
		}
	}
}