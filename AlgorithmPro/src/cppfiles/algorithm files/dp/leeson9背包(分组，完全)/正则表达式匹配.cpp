// 正则表达式匹配
// 给你字符串s、字符串p
// s中一定不含有'.'、'*'字符，p中可能含有'.'、'*'字符
// '.' 表示可以变成任意字符，数量1个
// '*' 表示可以让 '*' 前面那个字符数量任意(甚至可以是0个)
// p中即便有'*'，一定不会出现以'*'开头的情况，也一定不会出现多个'*'相邻的情况(无意义)
// 请实现一个支持 '.' 和 '*' 的正则表达式匹配
// 返回p的整个字符串能不能匹配出s的整个字符串
// 测试链接 : https://leetcode.cn/problems/regular-expression-matching/

#include<vector>
#include<string>
namespace
{
	class Solution {
	public:
		bool isMatch(std::string s, std::string p) {
			int n = s.size();
			int m = p.size();
			std::vector<std::vector<bool>> dp(n + 1, std::vector<bool>(m + 1, false));
			dp[0][0] = true;

			//优先处理第一行也就是i == 0的情况
			for (int j = 1; j <= m; j++)
			{
				if (p[j - 1] == '*')
				{
					dp[0][j] = dp[0][j - 2];
				}
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					//普通字符或者是‘.’的情况
					if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
					else
					{
						//'*'的情况，最为特殊，着重讨论
						if (p[j - 1] != '.' && p[j - 1] != '*')
						{
							dp[i][j] = false;
						}
						else
						{
							bool p1 = dp[i][j - 2];
							bool p2 = false;
							if ((s[i - 1] == p[j - 2] || p[j - 2] == '.'))
							{
								p2 = dp[i - 1][j];
							}

							dp[i][j] = p1 || p2;
						}
					}
				}
			}
			return dp[n][m];
		}
	};
}