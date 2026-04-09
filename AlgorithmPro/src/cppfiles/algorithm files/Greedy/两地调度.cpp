// 两地调度
// 公司计划面试2n个人，给定一个数组 costs
// 其中costs[i]=[aCosti, bCosti]
// 表示第i人飞往a市的费用为aCosti，飞往b市的费用为bCosti
// 返回将每个人都飞到a、b中某座城市的最低费用
// 要求每个城市都有n人抵达
// 测试链接 : https://leetcode.cn/problems/two-city-scheduling/
#include<vector>
#include<algorithm>
namespace 
{
	class Solution {
	public:
		int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
			std::vector<int> diff(costs.size());
			int ans = 0;

			for (int i = 0; i < diff.size(); i++)
			{
				diff[i] = costs[i][1] - costs[i][0];
				ans += costs[i][0];
			}

			std::sort(diff.begin(), diff.end());
			for (int i = 0; i < diff.size() / 2; i++)
			{
				ans += diff[i];
			}
			return ans;
		}
	};

	//动态规划解
	class Solution2 {
	public:
		int twoCitySchedCost(std::vector<std::vector<int>>& costs) {
			int n = costs.size();
			int m = n / 2;
			//dp[i][j]:前i个人里，有j个人去a的最少花费
			std::vector<std::vector<int>> dp(n+1, std::vector<int>(n+1,INT_MAX));
			dp[0][0] = 0;
			for (int i = 1; i <= n; i++)
			{
				dp[i][0] = dp[i - 1][0] + costs[i - 1][1];
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					int p1 = INT_MAX;
					int p2 = INT_MAX;
					if (dp[i - 1][j - 1] == INT_MAX)
					{
						p1 = INT_MAX;
					}
					else
					{
						p1 = dp[i - 1][j - 1] + costs[i - 1][0];//去a
					}

					if (dp[i - 1][j] == INT_MAX)
					{
						p2 = INT_MAX;
					}
					else
					{
						p2 = dp[i - 1][j] + costs[i - 1][1];//去b
					}	

					dp[i][j] = std::min(p1, p2);
				}
			}

			return dp[n][m];
		}
	};
}