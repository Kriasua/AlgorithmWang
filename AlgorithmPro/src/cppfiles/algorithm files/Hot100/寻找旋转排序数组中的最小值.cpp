//如题
//https://leetcode.cn/problems/find-minimum-in-rotated-sorted-array/description/

#include<vector>
namespace
{
	class Solution {
	public:
		int findMin(std::vector<int>& nums) {
			int left = 0;
			int right = nums.size() - 1;
			int ans = nums[0]; // 默认第一个是最小值（处理未旋转的情况）

			while (left <= right) {
				int mid = left + (right - left) / 2;

				if (nums[mid] < ans) {
					ans = nums[mid];
				}

				if (nums[mid] > nums[right]) {

					left = mid + 1;
				}
				else {

					right = mid - 1;
				}
			}
			return ans;
		}
	};
}