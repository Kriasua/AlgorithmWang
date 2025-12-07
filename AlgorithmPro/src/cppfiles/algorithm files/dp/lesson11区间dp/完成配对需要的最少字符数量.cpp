// 完成配对需要的最少字符数量
// 给定一个由'['、']'、'('，')'组成的字符串
// 请问最少插入多少个括号就能使这个字符串的所有括号正确配对
// 例如当前串是 "([[])"，那么插入一个']'即可满足
// 输出最少需要插入多少个字符
// 测试链接 : https://www.nowcoder.com/practice/e391767d80d942d29e6095a935a5b96b

#include<string>
#include<vector>
#include<iostream>

namespace
{
	int n;
	constexpr int MAXN = 105;
	std::string str;
	std::vector<std::vector<int>> dp;

	int compute()
	{
		for (int l = n - 1; l >= 0; l--)
		{
			for (int r = l; r < n; r++)
			{
				if (l == r)
				{
					dp[l][r] = 1;
				}
				else if (l == r - 1)
				{
					if ((str[l] == '(' && str[r] == ')')
						||
						(str[l] == '[' && str[r] == ']'))
					{
						dp[l][r] = 0;
					}
					else
					{
						dp[l][r] = 2;
					}
				}
				else
				{
					int p1 = INT_MAX;
					int p2 = INT_MAX;
					if ((str[l] == '(' && str[r] == ')')
						||
						(str[l] == '[' && str[r] == ']'))
					{
						p1 = dp[l + 1][r - 1];
					}
					for (int i = l; i < r; i++)
					{
						p2 = std::min(p2, dp[l][i] + dp[i + 1][r]);
					}
					dp[l][r] = std::min(p1, p2);
				}
			}
		}

		return dp[0][n - 1];
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		dp.resize(MAXN, std::vector<int>(MAXN));
		while (std::cin >> str)
		{
			n = str.size();
			std::cout << compute() << "\n";
			str.clear();
		}
		return 0;
	}
}