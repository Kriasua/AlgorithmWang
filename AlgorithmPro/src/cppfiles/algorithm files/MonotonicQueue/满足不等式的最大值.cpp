// 满足不等式的最大值
// 给你一个数组 points 和一个整数 k
// 数组中每个元素都表示二维平面上的点的坐标，并按照横坐标 x 的值从小到大排序
// 也就是说 points[i] = [xi, yi]
// 并且在 1 <= i < j <= points.length 的前提下，xi < xj 总成立
// 请你找出 yi + yj + |xi - xj| 的 最大值，
// 其中 |xi - xj| <= k 且 1 <= i < j <= points.length
// 题目测试数据保证至少存在一对能够满足 |xi - xj| <= k 的点。
// 测试链接 : https://leetcode.cn/problems/max-value-of-equation/

#include<vector>
namespace
{
	class Solution {
	public:
		int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k) {
			std::vector<int> deque;
			deque.resize(points.size(),0);
			int left = 0;
			int right = 1;
			int ans = INT_MIN;
			for (int i = 1,x,y; i < points.size(); i++)
			{
				x = points[i][0];
				y = points[i][1];
				while (left < right && x - points[deque[left]][0] > k)
				{
					left++;
				}

				if (left < right)
				{
					ans = std::max(ans, x + y + points[deque[left]][1] - points[deque[left]][0]);
				}

				while (left < right && ((y - x) >= (points[deque[right - 1]][1] - points[deque[right - 1]][0])))
				{
					right--;
				}

				deque[right++] = i;
				
			}
			
			return ans;
		}
	};
}
