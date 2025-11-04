// 最长回文子序列
// 给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度
// 测试链接 : https://leetcode.cn/problems/longest-palindromic-subsequence/

#include<string>
#include<vector>
namespace
{
	//取巧做法，相当于把原始串逆序了，然后求原始串和逆序串的最长公共子序列
    class Solution1 {
    public:
		int longestCommonSubsequence(std::string text1, std::string text2) {
			int m1 = text1.size();
			int m2 = text2.size();
			std::vector<std::vector<int>> dp(m1 + 1, std::vector<int>(m2 + 1));

			for (int i = m1 - 1; i >= 0; i--)
			{
				for (int j = m2 - 1; j >= 0; j--)
				{
					int ans = 0;
					if (text1[i] == text2[j])
					{
						ans = dp[i + 1][j + 1] + 1;
					}
					else
					{
						ans = std::max(dp[i + 1][j], dp[i][j + 1]);
					}
					dp[i][j] = ans;
				}
			}
			return dp[0][0];
		}

        int longestPalindromeSubseq(std::string s) {
            std::string reverse = "";
            for (int i = s.size() - 1; i >= 0; i--)
            {
                reverse += s[i];
            }
			
			return longestCommonSubsequence(s, reverse);
        }
    };

	//正常做法的暴力递归
	class Solution2 {
	public:

		int f(std::string& s, int l, int r)
		{
			if (l == r)
			{
				return 1;
			}

			if (l > r)
			{
				return 0;
			}

			if (s[l] == s[r])
			{
				return f(s, l + 1, r - 1) + 2;
			}
			else
			{
				return std::max(f(s, l, r - 1), f(s, l+1, r));
			}

		}

		int longestPalindromeSubseq(std::string s) {
			if (s == "")
			{
				return 0;
			}

			if (s.size() == 1)
			{
				return 1;
			}

			return f(s, 0, s.size() - 1);
		}
	};

	//记忆化搜索
	class Solution3 {
	public:

		int f(std::string& s, int l, int r, std::vector<std::vector<int>>& dp)
		{
			if (l == r)
			{
				return 1;
			}

			if (l > r)
			{
				return 0;
			}

			if (dp[l][r] != -1)
			{
				return dp[l][r];
			}

			int ans = 0;

			if (s[l] == s[r])
			{
				ans = f(s, l + 1, r - 1, dp) + 2;
			}
			else
			{
				ans = std::max(f(s, l, r - 1, dp), f(s, l + 1, r, dp));
			}

			dp[l][r] = ans;
			return ans;
		}

		int longestPalindromeSubseq(std::string s) {
			int n = s.size();

			if (s == "")
			{
				return 0;
			}

			if (n == 1)
			{
				return 1;
			}

			std::vector<std::vector<int>> dp(n, std::vector<int>(n, -1));

			return f(s, 0, s.size() - 1 , dp);
		}
	};

	//正宗动态规划
	class Solution4 {
	public:

		int longestPalindromeSubseq(std::string s) {
			int n = s.size();

			if (s == "")
			{
				return 0;
			}

			if (n == 1)
			{
				return 1;
			}

			std::vector<std::vector<int>> dp(n, std::vector<int>(n));

			for (int i = 0; i < n; i++)
			{
				dp[i][i] = 1;
			}

			for (int i = n-2; i >=0 ; i--)
			{
				for (int j = i + 1; j < n; j++)
				{
					if (s[i] == s[j])
					{
						dp[i][j] = dp[i+1][j-1] + 2;
					}
					else
					{
						dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
					}
				}
			}


			return dp[0][n-1];
		}
	};
}