// 环形数组中不能选相邻元素的最大累加和
// 给定一个数组nums，长度为n
// nums是一个环形数组，下标0和下标n-1是连在一起的
// 可以随意选择数字，但是不能选择相邻的数字
// 返回能得到的最大累加和
// 测试链接 : https://leetcode.cn/problems/house-robber-ii/

#include<vector>
namespace
{
    class Solution {
    public:
        int rob(std::vector<int>& nums) {
            if (nums.size() == 1)
            {
                return nums[0];
            }
            std::vector<int> dp1(nums.size()+2);
            std::vector<int> dp2(nums.size() + 2);
            for (int i = nums.size() - 1; i >= 1; i--)
            {
                dp1[i] = std::max(dp1[i + 1], nums[i] + dp1[i + 2]);
            }

            for (int i = nums.size() - 2; i >= 0; i--)
            {
                dp2[i] = std::max(dp2[i + 1], nums[i] + dp2[i + 2]);
            }

            return std::max(dp1[1], dp2[0]);
        }
    };
}