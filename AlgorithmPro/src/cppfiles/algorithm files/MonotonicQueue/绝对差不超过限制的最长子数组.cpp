// ���Բ�������Ƶ������������
// ����һ���������� nums ����һ����ʾ���Ƶ����� limit
// ���㷵�������������ĳ���
// ���������е���������Ԫ��֮��ľ��Բ����С�ڻ��ߵ��� limit
// ������������������������飬�򷵻� 0
// �������� : https://leetcode.cn/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/

#include<vector>

namespace
{
	class Solution {
	public:
		int longestSubarray(std::vector<int>& nums, int limit) {

			std::vector<int> maxQueue;
			std::vector<int> minQueue;
			maxQueue.resize(nums.size());
			minQueue.resize(nums.size());
			int L = 0;
			int R = 0;
			int minH = 0;
			int minT = 0;
			int maxH = 0;
			int maxT = 0;
			int ans = 0;
			for (; R < nums.size(); R++)
			{
				while (maxT > maxH && nums[R] >= nums[maxQueue[maxT - 1]])
				{
					maxT--;
				}
				maxQueue[maxT++] = R;

				while (minT > minH && nums[R] <= nums[minQueue[minT - 1]])
				{
					minT--;
				}
				minQueue[minT++] = R;


				while (L < R && (nums[maxQueue[maxH]] - nums[minQueue[minH]] > limit))
				{
					if (maxQueue[maxH] == L)
					{
						maxH++;
					}

					if (minQueue[minH] == L)
					{
						minH++;
					}
					L++;
				}

				ans = std::max(ans, R - L + 1);
			}

			return ans;

		}
	};
}