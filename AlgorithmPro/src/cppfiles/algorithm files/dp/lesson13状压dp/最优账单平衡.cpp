// 最优账单平衡
// 给你一个表示交易的数组 transactions
// 其中 transactions[i] = [fromi, toi, amounti]
// 表示 ID = fromi 的人给 ID = toi 的人共计 amounti
// 请你计算并返回还清所有债务的最小交易笔数
// 测试链接 : https://leetcode.cn/problems/optimal-account-balancing/

#include<vector>
#include <bit>
namespace
{
	class Solution
	{
	public:

		std::vector<int> getDebts(std::vector<std::vector<int>>& transactions, int n)
		{
			std::vector<int> original(n + 1);
			for (auto& trans : transactions)
			{
				original[trans[0]] -= trans[2];
				original[trans[1]] += trans[2];
			}
			std::vector<int> debts;
			for (int num : original)
			{
				if (num != 0)
				{
					debts.push_back(num);
				}
			}

			return debts;
		}

		int f(std::vector<int>& debts, int sum, int status, std::vector<int>& dp)
		{
			if (status == 0)
			{
				return 0;
			}

			if (dp[status] != -1)
			{
				return dp[status];
			}

			if (sum == 0)
			{
				int index = status & (~status + 1);
				int pos = __builtin_ctz(index);
				return f(debts, debts[pos], status ^ index,dp) + 1;
			}

			int ans = 0;

			for (int i = 0; i < debts.size(); i++)
			{
				if (((1 << i) & status) != 0)
				{
					ans = std::max(ans, f(debts, sum + debts[i], status ^ (1 << i),dp));
				}
			}
			dp[status] = ans;

			return ans;
		}

		int minTransfers(std::vector<std::vector<int>>& transactions)
		{
			int n = 0;
			int sum = 0;
			for (auto& trans : transactions)
			{
				n = std::max(n, std::max(trans[0], trans[1]));
			}

			std::vector<int> debts = getDebts(transactions, n);
			for (int num : debts)
			{
				sum += num;
			}
			if (sum != 0)
			{
				return -1;
			}

			n = debts.size();
			int status = (1 << n) - 1;
			std::vector<int> dp(status + 1,-1);
			return n - f(debts, 0, status, dp);
		}
	};
}