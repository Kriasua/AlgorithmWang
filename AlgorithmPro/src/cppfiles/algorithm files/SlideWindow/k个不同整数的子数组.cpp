// K����ͬ������������
// ����һ������������ nums��һ������ k������ nums �� ���������项 ����Ŀ��
// ��� nums ��ĳ���������в�ͬ�����ĸ���ǡ��Ϊ k
// ��� nums �������������һ����ͬ��������Ϊ ���������� ����
// ���磬[1,2,3,1,2] ���� 3 ����ͬ��������1��2���Լ� 3��
// ������ ������� ���� ���֡�
// �������� : https://leetcode.cn/problems/subarrays-with-k-different-integers/

#include<vector>
#include<unordered_map>
namespace
{
    class Solution {
    public:

        int subarrayUnderKDistinct(std::vector<int>& nums, int k)
        {
            std::unordered_map<int, int> map;
            int left = 0;
            int right = 0;
            int ans = 0;
            for (; right < nums.size(); right++)
            {
                map[nums[right]]++;

                while (map.size() > k)
                {
                    if (--map[nums[left]] == 0)
                    {
                        map.erase(nums[left]);
                    }
                    left++;
                }

                ans += right - left + 1;
            }
            return ans;
        }
        std::vector<int> map;
        Solution()
        {
            map.resize(20001, 0);
        }

        //ʹ����������ϣ���Ż�
        int subarrayUnderKDistinct2(std::vector<int>& nums, int k)
        {
            int counts = k;
            int left = 0;
            int right = 0;
            int ans = 0;
            for (; right < nums.size(); right++)
            {
                if (++map[nums[right]] == 1)
                {
                    counts--;
                }

                while (counts < 0)
                {
                    if (--map[nums[left++]] == 0)
                    {
                        counts++;
                    }
                }

                ans += right - left + 1;
            }
            return ans;
        }

        int subarraysWithKDistinct(std::vector<int>& nums, int k) {
            
            return subarrayUnderKDistinct(nums, k) - subarrayUnderKDistinct(nums, k - 1);
        }
    };
}