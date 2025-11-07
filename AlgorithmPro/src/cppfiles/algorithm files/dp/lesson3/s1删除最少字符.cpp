// 删除至少几个字符可以变成另一个字符串的子串
// 给定两个字符串s1和s2
// 返回s1至少删除多少字符可以成为s2的子串
// 对数器验证

#include<vector>
#include<string>
namespace
{
	int MinimumDeleteBecomeSubstring(std::string s1, std::string s2)
	{
		int n = s1.size();
		int m = s2.size();
		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));

		for (int i = 1; i <= n; i++)
		{
			dp[i][0] = i;
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= m; j++)
			{
				if (s1[i - 1] == s2[j - 1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = dp[i - 1][j] + 1;
				}
			}
		}

		int ans = INT_MAX;

		for (int num : dp[n])
		{
			ans = std::min(ans, num);
		}

		return ans;
	}
}