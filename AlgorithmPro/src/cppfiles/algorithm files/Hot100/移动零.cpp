//https://leetcode.cn/problems/move-zeroes/description/?envType=study-plan-v2&envId=top-100-liked
#include<vector>

class Solution {
public:
	void moveZeroes(std::vector<int>& nums) {
		int l = 0;
		int r = 0;

		while (r < nums.size())
		{
			if (nums[r] == 0)
			{
				r++;
			}
			else
			{
				nums[l] = nums[r];
				l++;
				r++;
			}
		}

		while (l < nums.size())
		{
			nums[l] = 0;
			l++;
		}
	}
};