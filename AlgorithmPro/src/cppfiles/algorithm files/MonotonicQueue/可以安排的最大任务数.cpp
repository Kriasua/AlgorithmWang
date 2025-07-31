// 你可以安排的最多任务数目
// 给你 n 个任务和 m 个工人。每个任务需要一定的力量值才能完成
// 需要的力量值保存在下标从 0 开始的整数数组 tasks 中，
// 第i个任务需要 tasks[i] 的力量才能完成
// 每个工人的力量值保存在下标从 0 开始的整数数组workers中，
// 第j个工人的力量值为 workers[j]
// 每个工人只能完成一个任务，且力量值需要大于等于该任务的力量要求值，即workers[j]>=tasks[i]
// 除此以外，你还有 pills 个神奇药丸，可以给 一个工人的力量值 增加 strength
// 你可以决定给哪些工人使用药丸，但每个工人 最多 只能使用 一片 药丸
// 给你下标从 0 开始的整数数组tasks 和 workers 以及两个整数 pills 和 strength
// 请你返回 最多 有多少个任务可以被完成。
// 测试链接 : https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:
		std::vector<int> ts;
		std::vector<int> ws;
		std::vector<int> deque;
		int left = 0;
		int right = 0;

		bool f(int tasksnumber, int pills, int strength)
		{
			left = 0;
			right = 0;
			int j = 0;
			int pillCount = 0;
			for (int i = ws.size() - tasksnumber; i < ws.size(); i++)
			{
				while (j <= tasksnumber - 1 && ts[j] <= ws[i])
				{
					deque[right++] = j++;
				}

				if (left < right && ws[i] >= ts[deque[left]])
				{
					left++;
				}
				else
				{
					pillCount++;
					while (j <= tasksnumber - 1 && ts[j] <= ws[i]+strength)
					{
						deque[right++] = j++;
					}

					if (left < right)
					{
						right--;
					}
					else
					{
						return false;
					}
				}

			}

			return pillCount <= pills;
		}

		int maxTaskAssign(std::vector<int>& tasks, std::vector<int>& workers, int pills, int strength) {
			std::sort(tasks.begin(), tasks.end());
			std::sort(workers.begin(), workers.end());
			ts = tasks;
			ws = workers;
			deque.resize(tasks.size());
			int ans = 0;
			for (int l = 0, r = std::min(tasks.size(), workers.size()), mid; l <= r;)
			{
				mid = l + ((r - l) >> 1);
				if (f(mid,pills,strength))
				{
					ans = mid;
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}

			return ans;

		}
	};
}