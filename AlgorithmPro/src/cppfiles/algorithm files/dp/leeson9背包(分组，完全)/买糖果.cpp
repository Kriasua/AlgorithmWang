/*
* 小X开了一家糖果店，售卖”种糖果，每种糖果均有无限颗。对于不同种类的糖果，小X采用了不同的促销策略。
具体地，对于第i(1≤i≤n)种糖果，购买第一颗的价格为xi;元，第二颗为yi元，第三颗又变回xi;元，第四颗则为yi元，以此类推。
小R带了m元钱买糖果。小R不关心糖果的种类，只想得到数量尽可能多的糖果。你需要帮助小R求出，m元钱能购买的糖果数量的最大值。
*/

#include<iostream>
#include<vector>
namespace
{
	//对，但是过不了
	class Solution
	{
		int f(std::vector<std::vector<int>>& prices, int m, int i, int cur, int status)
		{
			status = status % 2;
			if (i == prices.size())
			{
				return 0;
			}

			int ans = f(prices, m, i + 1, cur, 0);
			if (cur + prices[i][status] <= m)
			{
				ans = std::max(ans, f(prices, m, i, cur + prices[i][status], status + 1) + 1);
			}
			return ans;
		}

		int candy(std::vector<std::vector<int>>& prices, int m)
		{
			int n = prices.size();
			//std::vector<std::vector<std::vector<int>>> dp(n + 1, std::vector<std::vector<int>>(m, std::vector<int>(2)));
			return f(prices, m, 1, 0, 0);
		}
	};
}