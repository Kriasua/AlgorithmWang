/*给你一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 
找出只出现一次的那两个元素。你可以按 任意顺序 返回答案。
*/

#include<vector>
namespace {
    using std::vector;

    class Solution {
    public:

        int returnRightest1(int x)
        {
            if (x == -2147483648)
                return x;
            return x & (-x);
        }

        vector<int> singleNumber(vector<int>& nums) {

            vector<int> ans;
            int size = nums.size();
            int eorNums = 0;
            int A = 0;

            for (auto num : nums)
            {
                eorNums ^= num;
            }

            int standard = returnRightest1(eorNums);

            for (auto num : nums)
            {
                if ((num & standard) != 0)
                {
                    A ^= num;
                }
            }

            int B = eorNums ^ A;

            ans.push_back(A);
            ans.push_back(B);
            return ans;
        }

        
    };
}

