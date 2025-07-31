// �ָ���������ֵ(��������)
// ����һ���Ǹ��������� nums ��һ������ m
// ����Ҫ���������ֳ� m ���ǿյ����������顣
// ���һ���㷨ʹ���� m ����������Ժ͵����ֵ��С��
// �������� : https://leetcode.cn/problems/split-array-largest-sum/

#include<vector>
namespace
{
	using LL = long long int;
	class Solution {

	public:
		int splitArray(std::vector<int>& nums, int k) {
			LL ans = 0;
			LL l = 0;
			LL r = 0;
			LL m;
			for (int num : nums)
			{
				r += num;
			}

			while (l <= r)
			{
				m = l + ((r - l) >> 1);
				int need = f(nums, m);
				if (need <= k)
				{
					ans = m;
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}

			return (int)ans;
		}

		int f(std::vector<int>& nums, LL limit)
		{
			LL sum = 0;
			int ans = 1;
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] > limit)
				{
					return INT_MAX;
				}
				else if ((sum + nums[i]) <= limit)
				{
					sum += nums[i];
				}
				else
				{
					sum = nums[i];
					ans++;
				}
			}

			return ans;
		}

	};
}