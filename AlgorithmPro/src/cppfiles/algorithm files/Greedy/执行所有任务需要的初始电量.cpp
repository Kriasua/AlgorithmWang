// 执行所有任务的最少初始电量
// 每一个任务有两个参数，需要耗费的电量、至少多少电量才能开始这个任务
// 返回手机至少需要多少的初始电量，才能执行完所有的任务
// 测试链接 : https://leetcode.cn/problems/minimum-initial-energy-to-finish-tasks/
#include<vector>
#include<algorithm>

namespace
{
	class Solution {
	public:
		int minimumEffort(std::vector<std::vector<int>>& tasks) {
			std::sort(tasks.begin(), tasks.end(), [](const auto& a, const auto& b)
				{
					return (a[1] - a[0]) > (b[1] - b[0]);

				});

			int ans = 0;
			int cur = 0;

			for (auto& task : tasks)
			{
				if (cur < task[1])
				{
					ans += (task[1] - cur);
					cur += (task[1] - cur);
				}
				cur -= task[0];
			}

			return ans;
		}
	};
}