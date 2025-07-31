// 盛最多水的容器
// 给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
// 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水
// 返回容器可以储存的最大水量
// 说明：你不能倾斜容器
// 测试链接 : https://leetcode.cn/problems/container-with-most-water/
#include<vector>
namespace
{
    class Solution {
    public:
        int maxArea(std::vector<int>& height) {
            int l = 0;
            int r = height.size() - 1;
            int ans = 0;
            while (l < r)
            {
                ans = std::max(ans,(r - l) * std::min(height[l], height[r]));
                if (height[l] < height[r])
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            return ans;
        }
    };
}