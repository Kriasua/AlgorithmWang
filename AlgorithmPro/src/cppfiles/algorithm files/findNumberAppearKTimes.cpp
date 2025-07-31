// ������ֻ��1�������ִ�������m�Σ���������������m��
// ���س��ִ���С��m�ε�������

#include<vector>
#include<array>
#include "pch.h"
namespace {
    using std::vector;

    class Solution {
    public:

        int findNumber(vector<int>& nums, int m)
        {
            std::array<int, 32> help;

            int ans = 0;

            for (auto num : nums)
            {
                for (int i = 0; i < 32; i++)
                {
                    if ((num & (1 << i)) != 0)
                    {
                        help[i]++;
                    }
                }
            }

            for (int i = 0; i < 32; i++)
            {
                if ((help[i] % m) != 0)
                {
                    ans = ans | (1 << i);
                }
            }

            return ans;
        }

        int singleNumber(vector<int>& nums) {
            return findNumber(nums,3);
        }
    };
}