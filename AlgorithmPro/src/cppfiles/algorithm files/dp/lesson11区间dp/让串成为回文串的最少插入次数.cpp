// 让字符串成为回文串的最少插入次数
// 给你一个字符串 s
// 每一次操作你都可以在字符串的任意位置插入任意字符
// 请你返回让s成为回文串的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include<string>
#include<vector>
namespace
{
	class Solution {
	public:
		int minInsertions(std::string s) {
			int n = s.size();
			if (n == 1)
			{
				return 0;
			}

			if (n == 2)
			{
				return s[0] == s[1] ? 0 : 1;
			}

			std::vector<std::vector<int>> dp(n, std::vector<int>(n));
			//basecase:l == r-1
			for (int l = 0; l < n - 1; l++)
			{
				dp[l][l + 1] = s[l] == s[l + 1] ? 0 : 1;
			}


			for (int l = n - 3; l >= 0; l--)
			{
				for (int r = l + 2; r < n; r++)
				{
					if (s[l] == s[r])
					{
						dp[l][r] = dp[l + 1][r - 1];
					}
					else
					{
						dp[l][r] = std::min(dp[l + 1][r], dp[l][r - 1]) + 1;
					}
				}
			}

			return dp[0][n - 1];
		}
	};
}