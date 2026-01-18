// DI序列的有效排列
// 给定一个长度为n的字符串s，其中s[i]是:
// "D"意味着减少，"I"意味着增加
// 有效排列是对有n+1个在[0,n]范围内的整数的一个排列perm，使得对所有的i：
// 如果 s[i] == 'D'，那么 perm[i] > perm[i+1]
// 如果 s[i] == 'I'，那么 perm[i] < perm[i+1]
// 返回有效排列的perm的数量
// 因为答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/valid-permutations-for-di-sequence/

#include<vector>
#include<string>
namespace
{
	//记忆化搜索，O(n^3)
	class Solution1 {
	public:
		int f(std::string& s, int n, int i, int less, std::vector<std::vector<int>>& dp)
		{
			if (dp[i][less] != -1)
			{
				return dp[i][less];
			}

			int mod = 1000000007;
			int more = n - i - less;
			int ans = 0;
			if (i == n - 1)
			{
				return s[i - 1] == 'D' ? less : more;
			}

			if (s[i - 1] == 'D')
			{
				for (int j = 0; j < less; j++)
				{
					ans = (ans % mod + f(s, n, i + 1, j, dp) % mod) % mod;
				}
			}
			else
			{
				for (int j = 0; j < more; j++)
				{
					ans = (ans % mod + f(s, n, i + 1, j + less, dp) % mod) % mod;
				}
			}
			dp[i][less] = ans;
			return ans;
		}

		int numPermsDISequence(std::string s) {
			int mod = 1000000007;
			int ans = 0;
			int n = s.size() + 1;
			std::vector<std::vector<int>> dp(n, std::vector<int>(n,-1));

			for (int i = 0; i < n; i++)
			{
				ans = (ans % mod + f(s, n, 1, i, dp) % mod) % mod;
			}

			return ans;
		}
	};

	//dp,用前缀和数组优化，O(n^2)
	class Solution2 {
	public:
		int numPermsDISequence(std::string s) {
			int mod = 1000000007;
			int ans = 0;
			int n = s.size() + 1;
			std::vector<std::vector<int>> dp(n, std::vector<int>(n));
			std::vector<std::vector<int>> prefix(n, std::vector<int>(n));
			//填最后一行
			dp[n - 1][0] = 1;
			for (int j = 0; j < n; j++)
			{
				prefix[n - 1][j] = 1;
			}

			for (int i = n-2; i >=0; i--)
			{
				for (int j = 0; j < n; j++)
				{
					if (s[i] == 'D')
					{
						//less == 0
						if (j == 0)
						{
							dp[i][j] = 0;	
						}
						else
						{
							dp[i][j] = prefix[i + 1][j - 1];
						}
					}
					else
					{
						int left = j;
						int right = n - i - 2;
						//就是上面的more == 0
						if (left > right)
						{
							dp[i][j] = 0;
						}
						else 
						{
							int sum = prefix[i + 1][right];
							if (left > 0) {
								sum = (sum - prefix[i + 1][left - 1] + mod) % mod;
							}
							dp[i][j] = sum;
						}
					}
				}
				prefix[i][0] = dp[i][0];
				for (int j = 1; j < n; j++) {
					prefix[i][j] = (prefix[i][j - 1] + dp[i][j]) % mod;
				}

			}
			return prefix[0][n-1];
		}
	};
}