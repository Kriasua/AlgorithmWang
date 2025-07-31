// ������ΪK�����������
// ����һ������arr�����е�ֵ�п�����������0
// ����һ������k
// �����ۼӺ�>=k�������������У���̵������鳤��
// �������� : https://leetcode.cn/problems/shortest-subarray-with-sum-at-least-k/

#include<vector>
namespace
{
	class Solution {
	public:
		int shortestSubarray(std::vector<int>& nums, int k) {
			using LL = long long int;
			std::vector<LL> preSum;
			std::vector<int> deque;
			int left = 0;
			int right = 0;
			int ans = INT_MAX;
			preSum.resize(nums.size()+1);
			deque.resize(nums.size()+1);
			preSum[0] = 0;
			preSum[1] = nums[0];
			deque[right++] = 0;
			//��ʼ��ǰ׺������
			for (int i = 2; i <= nums.size(); i++)
			{
				preSum[i] = preSum[i - 1] + nums[i-1];
			}

			for (int i = 1; i < preSum.size(); i++)
			{
				while (left < right && preSum[i] - preSum[deque[left]] >= k)
				{
					ans = std::min(ans, i - deque[left++]);
				}

				while (left < right && preSum[i] <= preSum[deque[right-1]])
				{
					right--;
				}

				deque[right++] = i;
			}
			return ans == INT_MAX ? -1 : ans;
		}
	};
}