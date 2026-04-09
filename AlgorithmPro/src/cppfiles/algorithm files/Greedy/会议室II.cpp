// 会议室II
// 给你一个会议时间安排的数组 intervals
// 每个会议时间都会包括开始和结束的时间intervals[i]=[starti, endi]
// 返回所需会议室的最小数量
// 测试链接 : https://leetcode.cn/problems/meeting-rooms-ii/

#include<queue>
#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:
		int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
			std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
			int ans = 0;
			std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b)
				{
					return a[0] < b[0];
				});

			for (auto& interval : intervals)
			{
				int start = interval[0];
				int end = interval[1];
				while (!heap.empty() && heap.top() <= start)
				{
					heap.pop();
				}
				heap.push(end);
				ans = std::max(ans, (int)heap.size());
			}

			return ans;
		}
	};
}