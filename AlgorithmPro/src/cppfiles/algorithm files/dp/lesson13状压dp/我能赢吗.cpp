// 我能赢吗
// 给定两个整数n和m
// 两个玩家可以轮流从公共整数池中抽取从1到n的整数（不放回）
// 抽取的整数会累加起来（两个玩家都算）
// 谁在自己的回合让累加和 >= m，谁获胜
// 若先出手的玩家能稳赢则返回true，否则返回false
// 假设两位玩家游戏时都绝顶聪明，可以全盘为自己打算
// 测试链接 : https://leetcode.cn/problems/can-i-win/

#include<vector>
#include<optional>
#include<string>
namespace
{
	class Solution {
	public:
		//当前先手在status状态下能否赢
		bool f(int n, int rest, int status, std::vector<std::optional<bool>>& dp)
		{
			if (rest <= 0)
			{
				return false;
			}

			if (dp[status].has_value())
			{
				return dp[status].value();
			}

			bool ans = false;
			for (int i = 1; i <= n; i++)
			{
				if (((1 << i) & status) != 0)
				{
					if (!f(n, rest - i, status ^ (1 << i), dp))
					{
						ans = true;
						break;
					}
				}
			}

			dp[status].emplace(ans);
			return ans;
		}

		bool canIWin(int n, int m) {
			if (m == 0)
			{
				return true;
			}

			int status = (1 << n + 1) - 1;
			std::vector<std::optional<bool>> dp(1 << n + 1, std::optional<bool>());

			if ((1 + n) * n / 2 < m)
			{
				return false;
			}

			return f(n, m, status, dp);
		}
	};

	//单词拆分
	class Solution1 {
	public:

		bool f(std::string& s, std::vector<std::string>& wordDict, int index, std::vector<int>& dp)
		{
			if (index == s.size())
			{
				return true;
			}

			if (dp[index] != -1)
			{
				return dp[index] == 1;
			}

			bool ans = false;
			for (auto& str : wordDict)
			{
				int n = str.size();
				bool isValid = true;
				for (int i = 0; i < n; i++)
				{
					if (index + i >= s.size() || str[i] != s[index + i])
					{
						isValid = false;
						break;
					}
				}

				if (isValid && f(s, wordDict, index + n,dp))
				{
					ans = true;
					break;
				}
			}

			dp[index] = ans == true ? 1 : 0;
			return ans;
		}

		bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
			std::vector<int> dp(s.size(), -1);
			return f(s, wordDict, 0,dp);
		}
	};
}