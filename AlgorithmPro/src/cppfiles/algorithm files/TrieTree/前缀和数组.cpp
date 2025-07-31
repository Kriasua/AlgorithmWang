//https://leetcode.cn/problems/range-sum-query-immutable/description/

#include<vector>
namespace
{
    using std::vector;
    class NumArray {
    public:
        vector<int> preFix;
        NumArray(vector<int>& nums) {
            
            preFix.resize(nums.size() + 1);
            preFix[0] = 0;
            for (size_t i = 1; i < preFix.size(); i++)
            {
                preFix[i] = preFix[i - 1] + nums[i - 1];
            }
        }

        int sumRange(int left, int right) {
            return preFix[right + 1] - preFix[left];
        }
    };

    
}