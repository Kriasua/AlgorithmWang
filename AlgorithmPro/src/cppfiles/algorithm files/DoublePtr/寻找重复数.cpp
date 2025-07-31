// Ѱ���ظ���
// ����һ������ n + 1 ������������ nums �������ֶ��� [1, n] ��Χ�ڣ����� 1 �� n��
// ��֪���ٴ���һ���ظ���������
// ���� nums ֻ�� һ���ظ������� ������ ����ظ����� ��
// ����ƵĽ���������� ���޸� ���� nums ��ֻ�ó����� O(1) �Ķ���ռ䡣
// �������� : https://leetcode.cn/problems/find-the-duplicate-number/
#include<vector>
namespace
{
    class Solution {
    public:
        int findDuplicate(std::vector<int>& nums) {
            int slow = nums[0];
            int fast = nums[slow];
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[nums[fast]];
            }

            fast = 0;
            while (slow != fast)
            {
                slow = nums[slow];
                fast = nums[fast];
            }
            return fast;

        }
    };
}
