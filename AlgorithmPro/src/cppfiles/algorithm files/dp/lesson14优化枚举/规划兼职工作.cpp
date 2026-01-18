// 规划兼职工作
// 你打算利用空闲时间来做兼职工作赚些零花钱，这里有n份兼职工作
// 每份工作预计从startTime[i]开始、endTime[i]结束，报酬为profit[i]
// 返回可以获得的最大报酬
// 注意，时间上出现重叠的 2 份工作不能同时进行
// 如果你选择的工作在时间X结束，那么你可以立刻进行在时间X开始的下一份工作
// 测试链接 : https://leetcode.cn/problems/maximum-profit-in-job-scheduling/

#include<vector>
#include<array>
#include<algorithm>
namespace
{
	class Solution {
	public:
		int jobScheduling(std::vector<int>& startTime, std::vector<int>& endTime, std::vector<int>& profit) {
			int n = startTime.size();
			std::vector<std::array<int,3>> jobs(n);
			for (int i = 0; i < n; i++)
			{
				jobs[i][0] = startTime[i];
				jobs[i][1] = endTime[i];
				jobs[i][2] = profit[i];
			}

			//按照endTime排序
			std::sort(jobs.begin(), jobs.end(), [](std::array<int, 3>& a, std::array<int, 3>& b)
				{
					return a[1] < b[1];
				});

			std::vector<int> dp(n);
			dp[0] = jobs[0][2];

			for (int i = 1; i < n; i++)
			{
				int p1 = dp[i - 1];
				int p2 = jobs[i][2];
				int edge = jobs[i][0];
				int j = -1;
				int left = 0;
				int right = i - 1;
				//二分
				while (left <= right)
				{
					int middle = left + (right - left) / 2;
					if (jobs[middle][1] > edge)
					{
						right = middle - 1;
					}
					else
					{
						j = middle;
						left = middle + 1;
					}
				}

				//如果j==-1，证明找不到符合条件的
				if (j != -1)
				{
					p2 += dp[j];
				}

				dp[i] = std::max(p1, p2);
			}
			return dp[n - 1];
		}
	};
}
