// �ۼӺʹ��ڵ���target����������鳤��
// ����һ������ n ���������������һ�������� target
// �ҵ��ۼӺ� >= target �ĳ�����С�������鲢�����䳤��
// ��������ڷ��������������鷵��0
// �������� : https://leetcode.cn/problems/minimum-size-subarray-sum/
#include<vector>
namespace
{
    class Solution {
    public:
        int minSubArrayLen(int target, std::vector<int>& nums) {
            int ans = INT_MAX;
            int sum = 0;
            int l = 0;
            int r = 0;
            for (; r < nums.size(); r++)
            {
                sum += nums[r];
                while (sum - nums[l] >= target)
                {
                    sum -= nums[l++];
                }

                if (sum >= target)
                {
                    ans = std::min(ans, r - l + 1);
                }

            }

            return ans == INT_MAX ? 0 : ans;
        }
    };
}