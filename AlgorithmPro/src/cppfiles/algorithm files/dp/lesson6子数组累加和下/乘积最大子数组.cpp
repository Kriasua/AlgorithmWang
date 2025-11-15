// 乘积最大子数组
// 给你一个整数数组 nums
// 请你找出数组中乘积最大的非空连续子数组
// 并返回该子数组所对应的乘积
// 测试链接 : https://leetcode.cn/problems/maximum-product-subarray/

#include<vector>
namespace
{
    class Solution {
    public:
        int maxProduct(std::vector<int>& nums) {
            
            int n = nums.size();

            std::vector<int> minDp(n);
            std::vector<int> maxDp(n);

            minDp[0] = nums[0];
            maxDp[0] = nums[0];

            int ans = maxDp[0];
            for (int i = 1; i < n; i++)
            {
                int p1 = nums[i];
                int p2 = nums[i] * maxDp[i - 1];
                int p3 = nums[i] * minDp[i - 1];
                maxDp[i] = std::max(p1, std::max(p2, p3));
                minDp[i] = std::min(p1, std::min(p2, p3));
                ans = std::max(ans, maxDp[i]);
            }

            return ans;
        }
    };
}