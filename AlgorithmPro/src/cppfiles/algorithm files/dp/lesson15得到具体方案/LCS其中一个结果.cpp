// 最长公共子序列其中一个结果
// 给定两个字符串str1和str2
// 输出两个字符串的最长公共子序列
// 如果最长公共子序列为空，则输出-1
// 测试链接 : https://www.nowcoder.com/practice/4727c06b9ee9446cab2e859b4bb86bb8

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
namespace
{
	std::string str1;
	std::string str2;
	int m, n;
	constexpr int MAXL = 5005;
	std::vector<std::vector<int>> dp;

	void build()
	{
		m = str1.size();
		n = str2.size();
		dp.assign(m+1, std::vector<int>(n+1, 0));
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		dp.resize(MAXL, std::vector<int>(MAXL));
		while (std::cin >> str1 >> str2)
		{
			build();
			for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					if (str1[i-1] == str2[j-1])
					{
						dp[i][j] = dp[i - 1][j - 1] + 1;
					}
					else
					{
						dp[i][j] = dp[i - 1][j] >= dp[i][j - 1] ? dp[i - 1][j] : dp[i][j - 1];
					}
				}
			}
			std::string ans = "";
			int raw = m;
			int col = n;
			while (dp[raw][col] != 0)
			{
				if (str1[raw-1] == str2[col-1])
				{
					ans += str1[raw-1];
					raw--;
					col--;
				}
				else
				{
					if (dp[raw - 1][col] >= dp[raw][col - 1])
					{
						raw--;
					}
					else
					{
						col--;
					}
				}
			}
			std::reverse(ans.begin(),ans.end());
			if (ans.empty())
			{
				std::cout << -1 << "\n";
			}
			else
			{
				std::cout << ans << "\n";
			}
		}
	}
}