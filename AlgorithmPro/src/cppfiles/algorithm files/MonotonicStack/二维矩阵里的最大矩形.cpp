// 最大矩形
// 给定一个仅包含 0 和 1 、大小为 rows * cols 的二维二进制矩阵
// 找出只包含 1 的最大矩形，并返回其面积
// 测试链接：https://leetcode.cn/problems/maximal-rectangle/

#include<vector>

namespace
{
	class Solution {
	public:
		int largestRectangleArea(std::vector<int>& heights, std::vector<int> stack) {
			stack.resize(heights.size());
			int ans = 0;
			int size = 0, cur, left;
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

		int maximalRectangle(std::vector<std::vector<char>>& matrix) {
			int ans = 0;
			int n = matrix.size();
			int m = matrix[0].size();
			std::vector<int> stack;
			stack.resize(m,0);
			std::vector<int> heights;
			heights.resize(m,0);

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
				}

				ans = std::max(ans, largestRectangleArea(heights, stack));
			}

			return ans;
		}
	};
}
