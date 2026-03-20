//分割回文串
//https://leetcode.cn/problems/palindrome-partitioning/description/?envType=study-plan-v2&envId=top-100-liked
#include<vector>
#include<string>

namespace
{
	//普通解法
	class Solution1 {
	public:
		std::vector<std::vector<std::string>> ans;

		bool isHuiwen(std::string& str)
		{
			int n = str.size();

			if (n == 1)
			{
				return true;
			}

			if (n == 2)
			{
				return str[0] == str[1];
			}

			for (int i = 0; i < n / 2; i++)
			{
				if (str[i] != str[n - i - 1])
				{
					return false;
				}
			}
			return true;
		}

		void f(std::string& s, int i, std::vector<std::string>& path)
		{
			if (i == s.size())
			{
				ans.push_back(path);
				return;
			}

			std::string str;
			for (int pos = i; pos < s.size(); pos++)
			{
				str.push_back(s[pos]);
				if (isHuiwen(str))
				{
					path.push_back(str);
					f(s, pos + 1, path);
					path.pop_back();
				}
			}

		}

		std::vector<std::vector<std::string>> partition(std::string s) {
			ans.clear();
			std::vector<std::string> path;
			f(s, 0, path);
			return ans;
		}
	};


	//动态规划优化查回文函数
	class Solution2 {
	public:
		std::vector<std::vector<std::string>> ans;
		std::vector<std::vector<bool>> dp;

		void f(std::string& s, int i, std::vector<std::string>& path)
		{
			if (i == s.size())
			{
				ans.push_back(path);
				return;
			}

			for (int pos = i; pos < s.size(); pos++)
			{
				if (dp[i][pos])
				{
					path.push_back(s.substr(i,pos - i+1));
					f(s, pos + 1, path);
					path.pop_back();
				}
			}

		}

		std::vector<std::vector<std::string>> partition(std::string s) {
			ans.clear();
			std::vector<std::string> path;
			if (s.size() == 1)
			{
				return { {s} };
			}

			dp.clear();
			dp.resize(s.size(), std::vector<bool>(s.size(),true));
			for (int j = 1; j < s.size(); j++)
			{
				dp[j - 1][j] = s[j - 1] == s[j];
			}

			for (int j = 2; j < s.size(); j++)
			{
				int x = 0;
				int y = j;
				while (y < s.size())
				{
					if (dp[x + 1][y - 1] && s[x] == s[y])
					{
						dp[x][y] = true;
					}
					else
					{
						dp[x][y] = false;
					}
					x++;
					y++;
				}
			}


			f(s, 0, path);
			return ans;
		}
	};


}