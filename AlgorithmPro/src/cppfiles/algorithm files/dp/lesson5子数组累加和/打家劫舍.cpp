// 数组中不能选相邻元素的最大累加和
// 给定一个数组，可以随意选择数字
// 但是不能选择相邻的数字，返回能得到的最大累加和
// 测试链接 : https://leetcode.cn/problems/house-robber/

#include<vector>
namespace
{
    //暴力搜索
    class Solution1 {
    public:
        int f(std::vector<int>& nums, int i)
        {
            if (i > nums.size())
            {
                return 0;
            }

            int p1 = f(nums, i + 1);
            int p2 = nums[i] + f(nums, i + 2);
            return std::max(p1, p2);
        }

        int rob(std::vector<int>& nums) {
            return f(nums, 0);
        }
    };

    //动态规划
    class Solution2 {
    public:
        int rob(std::vector<int>& nums) {
            std::vector<int> dp(nums.size() + 3);
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                dp[i] = std::max(dp[i + 1], nums[i] + dp[i + 2]);
            }
            return dp[0];
        }
    };


}