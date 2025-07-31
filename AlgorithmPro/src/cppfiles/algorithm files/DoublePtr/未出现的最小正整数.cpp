// 缺失的第一个正数
// 给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。
// 请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
// 测试链接 : https://leetcode.cn/problems/first-missing-positive/

#include<vector>
namespace
{
    class Solution {
    public:
        int firstMissingPositive(std::vector<int>& nums) {
            int l = 0;
            int r = nums.size();

            while (l < r)
            {
                if (nums[l] == l + 1)
                {
                    l++;
                }
                else if (nums[l] <= l)
                {
                    swap(nums, l, --r);
                }
                else if (nums[l] > r)
                {
                    swap(nums, l, --r);
                }
                else if (nums[nums[l] - 1] == nums[l])
                {
                    swap(nums, l, --r);
                }
                else
                {
                    swap(nums,l, nums[l] - 1);
                }
            }
            return l + 1;   
        }

        void swap(std::vector<int>& nums, int a, int b)
        {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
        }
    };
}