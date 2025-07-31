/*给定一个包含 [0, n] 中 n 个数的数组 nums ，
找出 [0, n] 这个范围内没有出现在数组中的那个数。*/
#include<vector>
#include "pch.h"
namespace {
    using std::vector;
    int missingNumber(vector<int>& nums) {
        int size = nums.size();
        int rest = 0;
        int all = 0;

        for (int num : nums)
        {
            rest ^= num;
        }

        for (int i = 0; i <= size; i++)
        {
            all ^= i;
        }

        return rest ^ all;
    }

}