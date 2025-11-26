// 从栈中取出K个硬币的最大面值和
// 一张桌子上总共有 n 个硬币 栈 。每个栈有 正整数 个带面值的硬币
// 每一次操作中，你可以从任意一个栈的 顶部 取出 1 个硬币，从栈中移除它，并放入你的钱包里
// 给你一个列表 piles ，其中 piles[i] 是一个整数数组
// 分别表示第 i 个栈里 从顶到底 的硬币面值。同时给你一个正整数 k
// 请你返回在 恰好 进行 k 次操作的前提下，你钱包里硬币面值之和 最大为多少
// 测试链接 : https://leetcode.cn/problems/maximum-value-of-k-coins-from-piles/

#include<vector>
namespace
{
	class Solution {
	public:
		int maxValueOfCoins(std::vector<std::vector<int>>& piles, int k) {
			int n = piles.size();
			std::vector<std::vector<int>> dp(n+1,std::vector<int>(k+1));

			for (int i = 1; i <= n; i++)
			{
				for (int cur = 1; cur <= k; cur++)
				{
					int ans = 0;
					ans = dp[i - 1][cur];
					int cnts = piles[i - 1].size();
					int accumulation = 0;
					for (int j = 1; j <= cnts; j++)
					{
						if (cur >= j)
						{
							accumulation += piles[i-1][j - 1];
							ans = std::max(ans, dp[i - 1][cur - j] + accumulation);
						}
						else
						{
							break;
						}
					}
					dp[i][cur] = ans;
				}
			}

			return dp[n][k];
		}
	};
}