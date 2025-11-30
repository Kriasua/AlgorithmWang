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

	std::vector<int> valuesReal;
	std::vector<int> weightsReal;

	std::vector<std::vector<int>> dp1;
	std::vector<int> dp2;
	//不进行枚举优化
	int compute1()
	{
		for (int i = 1; i <= n; i++)
		{
			for (int cur = 0; cur <= W; cur++)
			{
				int maxCountinCur = cur / weights[i];
				int maxCount = std::min(maxCountinCur, counts[i]);
				int ans = dp1[i - 1][cur];
				for (int j = 1; j <= maxCount; j++)
				{
					ans = std::max(ans, dp1[i - 1][cur - weights[i] * j] + values[i] * j);
				}

				dp1[i][cur] = ans;
			}
		}

		return dp1[n][W];
	}

	//做二进制枚举优化
	int compute2()
	{
		
		int index = 1;
		for (int i = 1; i <= n; i++)
		{
			int count = counts[i];
			int bin = 1;
			while (count >= bin)
			{
				valuesReal[index] = values[i] * bin;
				weightsReal[index++] = weights[i] * bin;
				count -= bin;
				bin = bin << 1;
			}

			if (count != 0)
			{
				valuesReal[index] = values[i] * count;
				weightsReal[index++] = weights[i] * count;
			}
		}

		std::fill(dp2.begin(), dp2.begin() + index, 0);
		for (int i = 1; i < index; i++)
		{
			for (int cur = W; cur >= 0; cur--)
			{
				
				if (cur >= weightsReal[i])
				{
					dp2[cur] = std::max(dp2[cur], dp2[cur - weightsReal[i]] + valuesReal[i]);
				}
			}
		}

		return dp2[W];
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		weights.resize(MAXN);
		values.resize(MAXN);
		counts.resize(MAXN);
		valuesReal.resize(MAXN * 17);
		weightsReal.resize(MAXN * 17);
		//dp1.resize(MAXN + 1, std::vector<int>(MAXW));
		dp2.resize(MAXW);

		while (std::cin >> n >> W)
		{
			for (int i = 1; i <= n; i++)
			{
				std::cin >> values[i] >> weights[i] >> counts[i];
			}
			std::cout<<compute1()<<"\n";
		}
	}
}