// ȱʧ�ĵ�һ������
// ����һ��δ������������� nums �������ҳ�����û�г��ֵ���С����������
// ����ʵ��ʱ�临�Ӷ�Ϊ O(n) ����ֻʹ�ó����������ռ�Ľ��������
// �������� : https://leetcode.cn/problems/first-missing-positive/

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