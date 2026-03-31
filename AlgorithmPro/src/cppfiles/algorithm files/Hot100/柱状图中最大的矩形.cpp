//柱状图中最大的矩形
//https://leetcode.cn/problems/largest-rectangle-in-histogram/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	class Solution {
	public:
		int largestRectangleArea(std::vector<int>& heights) {
			int n = heights.size();
			std::vector<std::vector<int>> smaller(n, std::vector<int>(2));
			std::vector<int> stack(n);
			int stackSize = 0;

			//严格大压小，重复的也弹出，后期修正
			for (int i = 0; i < n; i++)
			{
				while (stackSize != 0 && heights[i] <= heights[stack[stackSize - 1]])
				{
					int index = stack[--stackSize];
					smaller[index][1] = i;
					smaller[index][0] = stackSize == 0 ? -1 : stack[stackSize - 1];
				}

				stack[stackSize++] = i;
			}

			while (stackSize != 0)
			{
				int index = stack[--stackSize];
				smaller[index][1] = n;
				smaller[index][0] = stackSize == 0 ? -1 : stack[stackSize - 1];
			}

			//重复值修正
			for (int i = n-1; i >= 0; i--)
			{
				if (heights[i] == heights[smaller[i][1]])
				{
					smaller[i][1] = smaller[smaller[i][1]][1];
				}
			}

			int ans = 0;
			for (int i = 0; i < n; i++)
			{
				int leftMin = smaller[i][0];
				int rightMin = smaller[i][1];

				ans = std::max(ans, heights[i] * (1 + (i - leftMin - 1) + (rightMin - i - 1)));
			}
			return ans;

		}
	};
}