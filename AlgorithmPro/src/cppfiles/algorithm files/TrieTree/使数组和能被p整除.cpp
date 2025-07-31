// ʹ������ܱ�P����
// ����һ������������ nums�������Ƴ� ��� �����飨����Ϊ �գ�
// ʹ��ʣ��Ԫ�ص� �� �ܱ� p ������ ������ ���������鶼�Ƴ���
// ���㷵������Ҫ�Ƴ������������ĳ��ȣ�����޷�������ĿҪ�󣬷��� -1 ��
// ������ ����Ϊԭ������������һ��Ԫ�ء�
// �������� : https://leetcode.cn/problems/make-sum-divisible-by-p/
#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>

namespace
{
    class Solution {
    public:
        int minSubarray(std::vector<int>& nums, int p) {
            std::unordered_map<int, int> map;
            long long int sum = 0;
            for (int num : nums)
            {
                sum += num;
            }
            
            int AllMod = sum % p;
            if (AllMod == 0)
            {
                return 0;
            }
            map.emplace(0, -1);
            sum = 0;
            int target = 0;
            int ans = INT_MAX;
            for (int i = 0, mod =0; i < nums.size(); i++)
            {
                sum += nums[i];
                mod = sum % p;
                target = ((mod + p) - AllMod) % p;
                if (map.find(target) != map.end())
                {
                    ans = std::min(ans, i - map[target]);
                }

                map[mod] = i;
            }

            return ans == nums.size() ? -1 : ans;

        }
    };
}