// 打家劫舍 IV
// 沿街有一排连续的房屋。每间房屋内都藏有一定的现金
// 现在有一位小偷计划从这些房屋中窃取现金
// 由于相邻的房屋装有相互连通的防盗系统，所以小偷不会窃取相邻的房屋
// 小偷的 窃取能力 定义为他在窃取过程中能从单间房屋中窃取的 最大金额
// 给你一个整数数组 nums 表示每间房屋存放的现金金额
// 第i间房屋中放有nums[i]的钱数
// 另给你一个整数k，表示小偷需要窃取至少 k 间房屋
// 返回小偷需要的最小窃取能力值
// 测试链接 : https://leetcode.cn/problems/house-robber-iv/

#include<vector>
namespace
{
    class Solution {
    public:
        const int MAX = 1000000001;
        std::vector<int> dp;
        bool f(std::vector<int>& nums, int k, int capability)
        {
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                int p1 = dp[i + 1];
                int p2 = 0;
                if (capability >= nums[i])
                {
                    p2 = dp[i + 2] + 1;
                }
                dp[i] = std::max(p1, p2);
            }

            return dp[0] >= k;

        }

        //空间压缩
        bool fOptimized(std::vector<int>& nums, int k, int capability)
        {
            int nextnext = 0;
            int next = 0;
            int cur = 0;
            for (int i = nums.size() - 1; i >= 0; i--)
            {
                int p1 = next;
                int p2 = 0;
                if (capability >= nums[i])
                {
                    p2 = nextnext + 1;
                }
                cur = std::max(p1, p2);
                nextnext = next;
                next = cur;
            }

            return cur >= k;

        }

        int minCapability(std::vector<int>& nums, int k) {
            int left = 0;
            int right = MAX;
            int middle;
            int ans = 0;
            dp.resize(nums.size() + 2);
            while (left <= right)
            {
                middle = left + ((right - left) >> 1);
                if (f(nums, k, middle))
                {
                    right = middle - 1;
                    ans = middle;
                }
                else
                {
                    left = middle + 1;
                }
            }
            return ans;
        }
    };
}