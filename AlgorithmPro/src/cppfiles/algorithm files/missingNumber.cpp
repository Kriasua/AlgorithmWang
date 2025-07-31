/*����һ������ [0, n] �� n ���������� nums ��
�ҳ� [0, n] �����Χ��û�г����������е��Ǹ�����*/
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