//ÂÖ×ªÊý×é
//https://leetcode.cn/problems/rotate-array/solutions/2784427/tu-jie-yuan-di-zuo-fa-yi-tu-miao-dong-py-ryfv/?envType=study-plan-v2&envId=top-100-liked
#include<vector>

namespace
{
	class Solution {
	public:

		void reverse(std::vector<int>& nums, int left, int right)
		{
			int mid = left + (right - left) / 2;
			int sum = left + right;
			for (int i = left; i <= mid; i++)
			{
				int j = sum - i;
				int tmp = nums[j];
				nums[j] = nums[i];
				nums[i] = tmp;
			}
		}

		void rotate(std::vector<int>& nums, int k) {
			int n = nums.size();
			k = k % n;
			if (k == 0)
			{
				return;
			}

			reverse(nums, 0, n - 1);
			reverse(nums, 0, k - 1);
			reverse(nums, k, n - 1);
		}
	};
}



