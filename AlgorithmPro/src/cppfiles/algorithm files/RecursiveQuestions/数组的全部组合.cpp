// 给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的组合
// 答案 不能 包含重复的组合。返回的答案中，组合可以按 任意顺序 排列
// 注意其实要求返回的不是子集，因为子集一定是不包含相同元素的，要返回的其实是不重复的组合
// 比如输入：nums = [1,2,2]
// 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

#include<vector>
#include<algorithm>
#include<unordered_set>
#include "pch.h"
namespace
{
    class Solution {
    public:

        void f(std::vector<std::vector<int>>& ans, std::vector<int>& path, std::vector<int>& nums, int size,int i)
        {
            if (i == nums.size())
            {
                ans.push_back(std::vector<int>(path.begin(), path.begin()+size));
                return;
            }

            int j = i + 1;
            while (j < nums.size() && nums[i] == nums[j])
            {
                j++;
            }

            f(ans, path, nums, size,j);

            for (; i < j; i++)
            {
                path[size++] = nums[i];
                f(ans, path, nums, size, j);
            }
            
        }


        std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
            std::vector<std::vector<int>> ans;
            if (nums.empty())
            {
                return ans;
            }

            std::sort(nums.begin(), nums.end());
            std::vector<int> path(nums.size());
            f(ans, path, nums,0,0);

            return ans;

        }
        
    };
}
