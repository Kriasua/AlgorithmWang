#include<vector>
#include<unordered_set>
#include "pch.h"
namespace 
{
    class Solution {
    public:


        void swap(std::vector<int>& nums, int a, int b)
        {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
        }

        void f(std::vector<std::vector<int>>& ans, std::vector<int>& nums, int i)
        {
            if (i == nums.size())
            {
                ans.push_back(nums);
                return;
            }

            for (int j = i; j < nums.size(); j++)
            {
                swap(nums, j, i);
                f(ans, nums, i + 1);
                swap(nums, j, i);
            }

        }

        std::vector<std::vector<int>> permute(std::vector<int>& nums) {
            std::vector<std::vector<int>> ans;
            if (nums.empty())
            {
                return ans;
            }

            f(ans, nums, 0);
            return ans;
        }

        ///////////////////////////////////////////////////////////////////
        //可以有重复数字的全排列


        void f2(std::vector<std::vector<int>>& ans, std::vector<int>& nums, int i)
        {
            if (i == nums.size())
            {
                ans.push_back(nums);
                return;
            }

            std::unordered_set<int> set;
            for (int j = i; j < nums.size(); j++)
            {
                if (set.find(nums[j])==set.end())
                {
                    set.emplace(nums[j]);
                    swap(nums, j, i);
                    f2(ans, nums, i + 1);
                    swap(nums, j, i);
                }
            }
        }

        std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
            std::vector<std::vector<int>> ans;
            if (nums.empty())
            {
                return ans;
            }
            std::unordered_set<int> set;
            f2(ans,nums,0);
            return ans;
        }
    };
}