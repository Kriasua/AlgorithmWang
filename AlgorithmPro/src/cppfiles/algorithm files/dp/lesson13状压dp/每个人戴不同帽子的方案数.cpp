// 每个人戴不同帽子的方案数
// 总共有 n 个人和 40 种不同的帽子，帽子编号从 1 到 40
// 给你一个整数列表的列表 hats ，其中 hats[i] 是第 i 个人所有喜欢帽子的列表
// 请你给每个人安排一顶他喜欢的帽子，确保每个人戴的帽子跟别人都不一样，并返回方案数
// 由于答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/number-of-ways-to-wear-different-hats-to-each-other

#include<vector>
namespace
{
	class Solution {
	public:
		using LL = long long int;
		const int mod = 1000000007;
		int finished;
		int maxHat;
		LL f(std::vector<int>& help, std::vector<std::vector<LL>>& dp, int n, int status, int hat)
		{
			if (status == finished)
			{
				return 1;
			}

			if (hat == maxHat+1)
			{
				return 0;
			}

			if (dp[hat][status] != -1)
			{
				return dp[hat][status];
			}

			LL ans = f(help, dp, n, status, hat + 1);

			for (int i = 0; i < n; i++)
			{
				//先看这个人被满足了没
				if (((1 << i) & status) == 0)
				{
					//再看这顶帽子能不能满足这个人
					if (((1 << i) & help[hat]) != 0)
					{
						ans = ((ans % mod) + (f(help, dp, n, status | (1 << i), hat + 1) % mod)) % mod;
					}
				}
			}

			dp[hat][status] = ans % mod;
			return ans % mod;
		}

		int numberWays(std::vector<std::vector<int>>& hats) {
			int n = hats.size();
			std::vector<int> help(41);
			maxHat = 0;
			for (int i = 0; i < n; i++)
			{
				int target = 1 << i;
				for (int num : hats[i])
				{
					help[num] |= target;
					maxHat = std::max(maxHat, num);
				}
			}
			finished = (1 << n) - 1;
			std::vector<std::vector<LL>> dp(41, std::vector<LL>(finished+1,-1));
			return f(help, dp, n, 0, 1) % mod;
		}
	};
}