// �ҳ���KС�����Ծ���
// ���� (a,b) ������ a �� b ��ɣ������Ծ��붨��Ϊ a �� b �ľ��Բ�ֵ��
// ����һ���������� nums ��һ������ k
// ������ nums[i] �� nums[j] ��������� 0 <= i < j < nums.length
// ���� �������Ծ����� �� k С�����Ծ��롣
// �������� : https://leetcode.cn/problems/find-k-th-smallest-pair-distance/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:

		int f(std::vector<int>& nums, int limit)
		{
			int ans = 0;
			int l = 0;
			int r = 0;
			for (; r < nums.size(); r++)
			{
				while (nums[r] - nums[l] > limit)
				{
					l++;
				}
				ans += r - l;
			}

			return ans;
		}

		int smallestDistancePair(std::vector<int>& nums, int k) {

			std::sort(nums.begin(), nums.end());
			int l = 0;
			int r = nums.back() - nums.front();
			int m = 0;
			int ans = 0;
			while (l <= r)
			{
				m = l + ((r - l) >> 1);
				if (f(nums, m) >= k)
				{
					ans=m;
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}

			return ans;

		}
	};
}