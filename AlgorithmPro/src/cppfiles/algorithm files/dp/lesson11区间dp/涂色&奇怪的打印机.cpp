// 涂色 & 奇怪打印机
// 假设你有一条长度为5的木板，初始时没有涂过任何颜色
// 你希望把它的5个单位长度分别涂上红、绿、蓝、绿、红
// 用一个长度为5的字符串表示这个目标：RGBGR
// 每次你可以把一段连续的木板涂成一个给定的颜色，后涂的颜色覆盖先涂的颜色
// 例如第一次把木板涂成RRRRR
// 第二次涂成RGGGR
// 第三次涂成RGBGR，达到目标
// 返回尽量少的涂色次数
// 测试链接 : https://www.luogu.com.cn/problem/P4170
// 测试链接 : https://leetcode.cn/problems/strange-printer/

#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
namespace
{
	class Solution {
	public:
		int strangePrinter(std::string s) {
			int n = s.size();
			std::vector<std::vector<int>> dp(n, std::vector<int>(n));
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
						dp[l][r] = s[l] == s[r] ? 1 : 2;
					}
					else
					{
						int p1 = INT_MAX;
						int p2 = INT_MAX;
						if (s[l] == s[r])
						{
							//取最小值是不必要的,因为这种情况下dp[l][r - 1]和dp[l+1][r]必然相等，可以证明
							//p1 = std::min(dp[l][r - 1],dp[l+1][r]);
							p1 = dp[l][r - 1];
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
	};

}