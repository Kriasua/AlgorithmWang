// 子数组最大累加和
// 给你一个整数数组 nums
// 返回非空子数组的最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-subarray/

#include<vector>
namespace
{
    class Solution {
    public:
        int maxSubArray(std::vector<int>& nums) {
            std::vector<int> dp(nums.size());
            dp[0] = nums[0];

            for (int i = 1; i < dp.size(); i++)
            {
                if (nums[i] < dp[i - 1] + nums[i])
                {
                    dp[i] = dp[i - 1] + nums[i];
                }
                else
                {
                    dp[i] = nums[i];
                }
            }

            int ans = INT_MIN;
            for (int num : dp)
            {
                ans = std::max(ans, num);
            }

            return ans;
        }
    };

//附加问题的实现
// 子数组中找到拥有最大累加和的子数组
// 并返回如下三个信息:
// 1) 最大累加和子数组的开头left
// 2) 最大累加和子数组的结尾right
// 3) 最大累加和子数组的累加和sum
// 如果不止一个子数组拥有最大累加和，那么找到哪一个都可以
    int left, right, sum;
    void maxSubArray(std::vector<int>& nums) {
        //dp表里存多一个左边界的信息
        std::vector<std::pair<int,int>> dp(nums.size());

        dp[0] = { 0,nums[0] };

        for (int i = 1; i < dp.size(); i++)
        {
            if (nums[i] < dp[i - 1].second + nums[i])
            {
                dp[i] = { dp[i - 1].first, dp[i - 1].second + nums[i] };
            }
            else
            {
                dp[i] = {i,nums[i] };
            }
        }

        sum = INT_MIN;

        for (int i = 0; i < dp.size(); i++)
        {
            if (dp[i].second > sum)
            {
                sum = dp[i].second;
                right = i;
                left = dp[i].first;
            }
        }

        
    }
}