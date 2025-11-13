// 环形数组的子数组最大累加和
// 给定一个数组nums，长度为n
// nums是一个环形数组，下标0和下标n-1是连在一起的
// 返回环形数组中，子数组最大累加和
// 测试链接 : https://leetcode.cn/problems/maximum-sum-circular-subarray/

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

        int minSubArray(std::vector<int>& nums) {
            std::vector<int> dp(nums.size());
            dp[0] = nums[0];

            for (int i = 1; i < dp.size(); i++)
            {
                if (nums[i] > dp[i - 1] + nums[i])
                {
                    dp[i] = dp[i - 1] + nums[i];
                }
                else
                {
                    dp[i] = nums[i];
                }
            }

            int ans = INT_MAX;
            for (int num : dp)
            {
                ans = std::min(ans, num);
            }

            return ans;
        }

        int maxSubarraySumCircular(std::vector<int>& nums) {
            int sum = 0;
            int Max = INT_MIN;
            for (int num : nums)
            {
                sum += num;
            }

            int p1 = maxSubArray(nums);
            int p2 = minSubArray(nums);

            return sum == p2 ? p1 : std::max(p1, sum - p2);
        }
    };
}