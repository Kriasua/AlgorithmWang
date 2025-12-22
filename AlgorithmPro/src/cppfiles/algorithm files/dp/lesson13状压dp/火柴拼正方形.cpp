// 火柴拼正方形
// 你将得到一个整数数组 matchsticks
// 其中 matchsticks[i] 是第 i 个火柴棒的长度
// 你要用 所有的火柴棍 拼成一个正方形
// 你 不能折断 任何一根火柴棒，但你可以把它们连在一起，而且每根火柴棒必须 使用一次
// 如果你能拼出正方形，则返回 true ，否则返回 false
// 测试链接 : https://leetcode.cn/problems/matchsticks-to-square/

#include<vector>
namespace
{
	class Solution {
	public:

		bool f(std::vector<int>& matchsticks, int edge, int n, int rest, int cnts, int status, std::vector<std::vector<int>>& dp)
		{
			if (rest < 0)
			{
				return false;
			}

			if (rest == 0)
			{
				if (cnts != 0)
				{
					return f(matchsticks, edge, n, edge, cnts - 1, status, dp);
				}
				else
				{
					return true;
				}
			}

			if (dp[cnts][status] != -1)
			{
				return dp[cnts][status] == 1;
			}

			bool ans = false;
			for (int i = 0; i < n; i++)
			{
				if (((1 << i) & status) != 0)
				{
					if (f(matchsticks, edge, n, rest - matchsticks[i], cnts, status ^ (1 << i), dp))
					{
						ans = true;
						break;
					}
				}
			}
			dp[cnts][status] = ans == true ? 1 : 0;
			return ans;
		}

		bool makesquare(std::vector<int>& matchsticks) {
			int n = matchsticks.size();
			int sum = 0;
			int max = 0;
			for (int num : matchsticks)
			{
				sum += num;
				max = std::max(max, num);
			}

			if (sum % 4 != 0)
			{
				return  false;
			}

			int edge = sum / 4;
			int status = (1 << n) - 1;
			if (max > edge)
			{
				return false;
			}

			std::vector<std::vector<int>> dp(4, std::vector<int>(1<<n+1,-1));
			return f(matchsticks, edge, n, edge, 3, status, dp);
		}
	};
}