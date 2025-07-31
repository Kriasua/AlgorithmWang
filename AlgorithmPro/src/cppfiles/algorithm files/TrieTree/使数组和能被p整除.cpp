// 使数组和能被P整除
// 给你一个正整数数组 nums，请你移除 最短 子数组（可以为 空）
// 使得剩余元素的 和 能被 p 整除。 不允许 将整个数组都移除。
// 请你返回你需要移除的最短子数组的长度，如果无法满足题目要求，返回 -1 。
// 子数组 定义为原数组中连续的一组元素。
// 测试链接 : https://leetcode.cn/problems/make-sum-divisible-by-p/
#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>

namespace
{
    class Solution {
    public:
        int minSubarray(std::vector<int>& nums, int p) {
            std::unordered_map<int, int> map;
            long long int sum = 0;
            for (int num : nums)
            {
                sum += num;
            }
            
            int AllMod = sum % p;
            if (AllMod == 0)
            {
                return 0;
            }
            map.emplace(0, -1);
            sum = 0;
            int target = 0;
            int ans = INT_MAX;
            for (int i = 0, mod =0; i < nums.size(); i++)
            {
                sum += nums[i];
                mod = sum % p;
                target = ((mod + p) - AllMod) % p;
                if (map.find(target) != map.end())
                {
                    ans = std::min(ans, i - map[target]);
                }

                map[mod] = i;
            }

            return ans == nums.size() ? -1 : ans;

        }
    };
}