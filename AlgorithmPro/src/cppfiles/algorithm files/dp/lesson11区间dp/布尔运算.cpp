// 布尔运算
// 给定一个布尔表达式和一个期望的布尔结果 result
// 布尔表达式由 0 (false)、1 (true)、& (AND)、 | (OR) 和 ^ (XOR) 符号组成
// 布尔表达式一定是正确的，不需要检查有效性
// 但是其中没有任何括号来表示优先级
// 你可以随意添加括号来改变逻辑优先级
// 目的是让表达式能够最终得出result的结果
// 返回最终得出result有多少种不同的逻辑计算顺序
// 测试链接 : https://leetcode.cn/problems/boolean-evaluation-lcci/

#include<string>
#include<vector>
#include<array>
namespace
{
	class Solution {
	public:

		std::array<int,2> func(std::string s, int l, int r, std::vector<std::vector<std::array<int, 2>>>& dp)
		{
			if (l == r)
			{
				if (s[l] == '1')
				{
					return { 0,1 };
				}
				else
				{
					return { 1,0 };
				}
			}
			
			if (dp[l][r][0] != -1 && dp[l][r][1] != -1)
			{
				return dp[l][r];
			}

			int t = 0;
			int f = 0;

			for (int i = l + 1; i < r; i += 2)
			{
				auto pre = func(s, l, i - 1, dp);
				auto behind = func(s, i + 1, r, dp);

				if (s[i] == '|')
				{
					t += pre[0] * behind[1] + pre[1] * behind[0] + pre[1] * behind[1];
					f += pre[0] * behind[0];
				}
				else if (s[i] == '&')
				{
					t += pre[1] * behind[1];
					f += pre[0] * behind[1] + pre[1] * behind[0] + pre[0] * behind[0];
				}
				else
				{
					t += pre[0] * behind[1] + pre[1] * behind[0];
					f += pre[0] * behind[0] + pre[1] * behind[1];
				}
			}

			std::array<int, 2> ans = { f,t };
			dp[l][r] = ans;
			return ans;
		}

		int countEval(std::string s, int result) {
			int n = s.size();
			std::vector<std::vector<std::array<int, 2>>> dp(n, std::vector<std::array<int, 2>>(n,{-1,-1}));
			auto ans = func(s, 0, n - 1, dp);
			return ans[result];

		}
	};
}