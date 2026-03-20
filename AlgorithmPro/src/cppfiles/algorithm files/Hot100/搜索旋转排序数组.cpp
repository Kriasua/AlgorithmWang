//搜索旋转排序数组
//https://leetcode.cn/problems/search-in-rotated-sorted-array/description/?envType=study-plan-v2&envId=top-100-liked
#include<vector>

namespace
{
	class Solution {
	public:
		int search(std::vector<int>& nums, int target) {
			int left = 0;
			int right = nums.size() - 1;
			int minPos = 0; // 默认第一个是最小值（处理未旋转的情况）

			while (left <= right) {
				int mid = left + (right - left) / 2;

				if (nums[mid] < nums[minPos]) {
					minPos = mid;
				}

				if (nums[mid] > nums[right]) {

					left = mid + 1;
				}
				else {

					right = mid - 1;
				}
			}

			if (target == nums[nums.size() - 1])
			{
				return nums.size() - 1;
			}
			else if (target > nums[nums.size()-1])
			{
				left = 0;
				right = minPos - 1;
				while (left <= right)
				{
					int mid = left + (right - left) / 2;
					if (nums[mid] == target)
					{
						return mid;
					}
					else if(nums[mid] > target)
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
			}
			else
			{
				left = minPos;
				right = nums.size()-1;
				while (left <= right)
				{
					int mid = left + (right - left) / 2;
					if (nums[mid] == target)
					{
						return mid;
					}
					else if (nums[mid] > target)
					{
						right = mid - 1;
					}
					else
					{
						left = mid + 1;
					}
				}
			}
			return -1;
		}
	};
}