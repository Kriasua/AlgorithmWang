// ����һ���������� nums �����п��ܰ����ظ�Ԫ�أ����㷵�ظ��������п��ܵ����
// �� ���� �����ظ�����ϡ����صĴ��У���Ͽ��԰� ����˳�� ����
// ע����ʵҪ�󷵻صĲ����Ӽ�����Ϊ�Ӽ�һ���ǲ�������ͬԪ�صģ�Ҫ���ص���ʵ�ǲ��ظ������
// �������룺nums = [1,2,2]
// �����[[],[1],[1,2],[1,2,2],[2],[2,2]]

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
