// 统计不同回文子序列
// 给你一个字符串s，返回s中不同的非空回文子序列个数
// 由于答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/count-different-palindromic-subsequences/

#include<string>
#include<vector>
namespace
{
	class Solution {
		using LL = long long int;
	public:
		int countPalindromicSubsequences(std::string s) {
			int n = s.size();
			const int mod = 1000000007;
			std::vector<int> lastLeft(n);
			std::vector<int> lastRight(n);
			std::vector<int> letters = { -1,-1,-1,-1 };

			for (int i = 0; i < n; i++)
			{
				int index = s[i] - 'a';
				lastLeft[i] = letters[index];
				letters[index] = i;
			}

			letters = { INT_MAX,INT_MAX,INT_MAX,INT_MAX };
			for (int i = n-1; i >= 0; i--)
			{
				int index = s[i] - 'a';
				lastRight[i] = letters[index];
				letters[index] = i;
			}

			std::vector<std::vector<LL>> dp(n, std::vector<LL>(n));
			for (int i = 0; i < n-1; i++)
			{
				dp[i][i] = 1;
				dp[i][i + 1] = 2;
			}
			dp[n - 1][n - 1] = 1;

			for (int i = n - 3; i >= 0; i--)
			{
				for (int j = i + 2; j < n; j++)
				{
					if (s[i] != s[j])
					{
						dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1])%mod + mod - dp[i + 1][j - 1]) % mod;
					}
					else
					{
						int iRight = lastRight[i];
						int jLeft = lastLeft[j];

						//这区间内没有s[i]
						if (iRight == j)
						{
							dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % mod;
						}
						//这区间只有一个s[i]
						else if (iRight == jLeft)
						{
							dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % mod;
						}
						else
						{
							dp[i][j] = ((dp[i + 1][j - 1] * 2) % mod + mod - dp[iRight + 1][jLeft - 1]) % mod;
						}
					}
				}
			}

			return dp[0][n - 1] % mod;
		}
	};



	//逻辑正确，但是不是最优解，会内存溢出
	/*给你数字字符串 s ，请你返回 s 中长度为 5 的 回文子序列 数目。由于答案可能很大，请你将答案对 109 + 7 取余 后返回。*/
	//测试链接：https://leetcode.cn/problems/count-palindromic-subsequences/description/
	class Solution {
	public:
		using LL = long long int;
		int countPalindromes(std::string s) {
			int n = s.size();
			const int mod = 1000000007;
			std::vector<std::vector<std::vector<LL>>> dp(n, std::vector<std::vector<LL>>(n, std::vector<LL>(6)));

			for (int l = 0; l < n; l++)
			{
				for (int r = l; r < n; r++)
				{
					dp[l][r][1] = r - l + 1;
				}
			}

			for (int l = n - 3; l >= 0; l--)
			{
				for (int r = l + 2; r < n; r++)
				{
					dp[l][r][3] = ((dp[l + 1][r][3] + dp[l][r - 1][3])%mod + mod - dp[l + 1][r - 1][3])%mod;
					if (s[l] == s[r])
					{
						dp[l][r][3] = (dp[l][r][3] + dp[l + 1][r - 1][1]) % mod;
					}
				}
			}

			for (int l = n - 5; l >= 0; l--)
			{
				for (int r = l + 4; r < n; r++)
				{
					dp[l][r][5] = ((dp[l + 1][r][5] + dp[l][r - 1][5])%mod + mod - dp[l + 1][r - 1][5]) % mod;
					if (s[l] == s[r])
					{
						dp[l][r][5] = (dp[l][r][5] + dp[l + 1][r - 1][3]) % mod;
					}
				}
			}

			return dp[0][n - 1][5] % mod;

		}
	};
}