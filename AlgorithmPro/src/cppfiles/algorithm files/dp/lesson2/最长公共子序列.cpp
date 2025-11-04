// 最长公共子序列
// 给定两个字符串text1和text2
// 返回这两个字符串的最长 公共子序列 的长度
// 如果不存在公共子序列，返回0
// 两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列
// 测试链接 : https://leetcode.cn/problems/longest-common-subsequence/

#include<string>
#include<vector>
namespace
{
	//暴力递归
	class Solution1 {
	public:
		int f(std::string& text1, std::string& text2, int i1, int i2)
		{
			if (i1 == text1.size() || i2 == text2.size())
			{
				return 0;
			}

			int p1 = f(text1, text2, i1 + 1, i2 + 1);
			int p2 = f(text1, text2, i1, i2 + 1);
			int p3 = f(text1, text2, i1 + 1, i2);
			int p4 = 0;
			if (text1[i1] == text2[i2])
			{
				p4 = f(text1, text2, i1 + 1, i2 + 1) + 1;
			}

			return std::max(std::max(p1, p2), std::max(p3, p4));
		}

		int longestCommonSubsequence(std::string text1, std::string text2) {
			int m1 = text1.size();
			int m2 = text2.size();
			return f(text1, text2, 0, 0);
		}
	};

	//记忆化搜索
	class Solution2 {
	public:
		int f(std::string& text1, std::string& text2, int i1, int i2, std::vector<std::vector<int>>& dp)
		{
			if (i1 == text1.size() || i2 == text2.size())
			{
				return 0;
			}

			if (dp[i1][i2] != -1)
			{
				return dp[i1][i2];
			}

			int ans = 0;

			int p1 = f(text1, text2, i1 + 1, i2 + 1,dp);
			int p2 = f(text1, text2, i1, i2 + 1,dp);
			int p3 = f(text1, text2, i1 + 1, i2,dp);
			int p4 = 0;
			if (text1[i1] == text2[i2])
			{
				p4 = f(text1, text2, i1 + 1, i2 + 1,dp) + 1;
			}

			ans = std::max(std::max(p1, p2), std::max(p3, p4));
			dp[i1][i2] = ans;
			return ans;
		}

		int longestCommonSubsequence(std::string text1, std::string text2) {
			int m1 = text1.size();
			int m2 = text2.size();
			std::vector<std::vector<int>> dp(m1, std::vector<int>(m2,-1));
			return f(text1, text2, 0, 0, dp);
		}
	};

	//正宗动态规划
	class Solution3 {
	public:
		int longestCommonSubsequence(std::string text1, std::string text2) {
			int m1 = text1.size();
			int m2 = text2.size();
			std::vector<std::vector<int>> dp(m1+1, std::vector<int>(m2+1));
			//先填越界位置
			for (int i = 0; i <= m2; i++)
			{
				dp[m1][i] = 0;
			}
			for (int i = 0; i <= m1; i++)
			{
				dp[i][m2] = 0;
			}

			for (int i = m1 - 1; i >= 0; i--)
			{
				for (int j = m2 - 1; j >= 0; j--)
				{
					int ans = 0;
					int p1 = dp[i+1][j+1];
					int p2 = dp[i+1][j];
					int p3 = dp[i][j+1];
					int p4 = 0;
					if (text1[i] == text2[j])
					{
						p4 = dp[i + 1][j + 1] + 1;
					}

					ans = std::max(std::max(p1, p2), std::max(p3, p4));
					dp[i][j] = ans;
				}
			}

			return dp[0][0];
		}
	};
}