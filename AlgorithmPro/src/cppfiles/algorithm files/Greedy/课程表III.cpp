// 课程表III
// 这里有n门不同的在线课程，按从1到n编号
// 给你一个数组courses
// 其中courses[i]=[durationi, lastDayi]表示第i门课将会持续上durationi天课
// 并且必须在不晚于lastDayi的时候完成
// 你的学期从第 1 天开始
// 且不能同时修读两门及两门以上的课程
// 返回你最多可以修读的课程数目
// 测试链接 : https://leetcode.cn/problems/course-schedule-iii/
#include<vector>
#include<queue>


namespace
{
	class Solution {
	public:
		struct compare
		{
			bool operator()(int a, int b)
			{
				return a < b;
			}
		};

		int scheduleCourse(std::vector<std::vector<int>>& courses) {
			std::priority_queue<int, std::vector<int>, compare> heap;
			std::sort(courses.begin(), courses.end(), [](auto& a, auto& b)
				{
					return a[1] < b[1];
				});

			int time = 0;
			for (auto& course : courses)
			{
				int duration = course[0];
				int ddl = course[1];

				if (time + duration > ddl)
				{
					if (!heap.empty() && duration < heap.top())
					{
						time -= heap.top();
						heap.pop();
						heap.push(duration);
						time += duration;
					}
				}
				else
				{
					time += duration;
					heap.push(duration);
				}
			}
			return heap.size();
		}
	};
}