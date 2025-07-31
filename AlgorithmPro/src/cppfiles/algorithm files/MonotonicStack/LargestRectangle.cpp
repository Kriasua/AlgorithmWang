// 柱状图中最大的矩形
// 给定 n 个非负整数，用来表示柱状图中各个柱子的高度
// 每个柱子彼此相邻，且宽度为 1 。求在该柱状图中，能够勾勒出来的矩形的最大面积
// 测试链接：https://leetcode.cn/problems/largest-rectangle-in-histogram


#include<vector>
namespace
{
	class Solution {
	public:
		int largestRectangleArea(std::vector<int>& heights) {
			std::vector<int> stack;
			stack.resize(heights.size());
			int ans=0;
			int size=0,cur,left;
			for (int i = 0; i < heights.size(); i++)
			{//无论相等弹不弹出，都能计算正确，详细自己分析
				while (size > 0 && heights[i] < heights[stack[size - 1]])
				{
					cur = stack[--size];
					left = size == 0 ? -1 : stack[size - 1];
					ans = std::max(ans, (i - left - 1) * heights[cur]);
				}

				stack[size++] = i;
			}

			while (size > 0)
			{
				cur = stack[--size];
				left = size == 0 ? -1 : stack[size - 1];
				ans = std::max(ans, heights[cur] * (int)(heights.size() - left - 1));
			}

			return ans;
		}
	};
}


