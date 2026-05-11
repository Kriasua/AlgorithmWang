// 给你一个整数n，请你帮忙统计一下我们可以按下述规则形成多少个长度为n的字符串：
// 字符串中的每个字符都应当是小写元音字母（'a', 'e', 'i', 'o', 'u'）
// 每个元音 'a' 后面都只能跟着 'e'
// 每个元音 'e' 后面只能跟着 'a' 或者是 'i'
// 每个元音 'i' 后面 不能 再跟着另一个 'i'
// 每个元音 'o' 后面只能跟着 'i' 或者是 'u'
// 每个元音 'u' 后面只能跟着 'a'
// 由于答案可能会很大，结果对1000000007取模
// 测试链接 : https://leetcode.cn/problems/count-vowels-permutation/

#include<vector>
#include<iostream>
namespace
{
	class Solution {
	public:
		int MOD = 1e9 + 7;

		long long int f(int n, char c, std::vector<std::vector<int>>& dp)
		{
			if (n == 0)
			{
				return 1;
			}

			int index;
			if (c == 'a')
			{
				index = 0;
			}
			else if (c == 'e')
			{
				index = 1;
			}
			else if (c == 'i')
			{
				index = 2;
			}
			else if (c == 'o')
			{
				index = 3;
			}
			else 
			{
				index = 4;
			}

			if (dp[n][index] != -1)
			{
				return dp[n][index];
			}

			long long int ans = 0;
			if (c == 'a')
			{
				ans = (ans + f(n - 1, 'e',dp)) % MOD;
			}
			else if (c == 'e')
			{
				ans = (ans + f(n - 1, 'a',dp)) % MOD;
				ans = (ans + f(n - 1, 'i',dp)) % MOD;
			}
			else if (c == 'i')
			{
				ans = (ans + f(n - 1, 'a',dp)) % MOD;
				ans = (ans + f(n - 1, 'e',dp)) % MOD;
				ans = (ans + f(n - 1, 'o',dp)) % MOD;
				ans = (ans + f(n - 1, 'u',dp)) % MOD;
			}
			else if (c == 'o')
			{
				ans = (ans + f(n - 1, 'i',dp)) % MOD;
				ans = (ans + f(n - 1, 'u',dp)) % MOD;
			}
			else
			{
				ans = (ans + f(n - 1, 'a',dp)) % MOD;
			}

			ans %= MOD;
			dp[n][index] = ans;
			return ans;
		}

		int countVowelPermutation(int n) {
			std::vector<std::vector<int>> dp(n + 1, std::vector<int>(5, -1));
			long long int ans = f(n - 1, 'a', dp) + f(n - 1, 'e', dp) + f(n - 1, 'i', dp) + f(n - 1, 'o', dp) + f(n - 1, 'u', dp);
			return ans % MOD;
		}
	};
}

int main()
{
	Solution sol;
	for (int i = 1; i < 20; i++)
	{
		std::cout << sol.countVowelPermutation(i) << "\n";
	}
}