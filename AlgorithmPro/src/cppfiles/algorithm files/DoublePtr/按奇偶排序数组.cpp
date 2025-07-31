// ����ż��������II
// ����һ���Ǹ��������� nums��nums ��һ������������ ��һ��������ż��
// ��������������Ա㵱 nums[i] Ϊ����ʱ��iҲ������
// �� nums[i] Ϊż��ʱ�� i Ҳ�� ż��
// ����Է��� �κ���������������������Ϊ��
// �������� : https://leetcode.cn/problems/sort-array-by-parity-ii/
#include<vector>
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

        std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
            int last = nums.size() - 1;
            int even = 0;
            int odd = 1;
            while (even < nums.size() && odd < nums.size())
            {
                if ((nums[last] & 1) != 1)
                {
                    swap(nums, even, last);
                    even += 2;
                }
                else
                {
                    swap(nums, odd, last);
                    odd += 2;
                }
            }

            return nums;
        }
    };
}