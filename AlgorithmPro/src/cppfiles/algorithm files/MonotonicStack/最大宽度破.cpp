// 最大宽度坡
// 给定一个整数数组 A，坡是元组 (i, j)，其中  i < j 且 A[i] <= A[j]
// 这样的坡的宽度为 j - i，找出 A 中的坡的最大宽度，如果不存在，返回 0
// 测试链接 : https://leetcode.cn/problems/maximum-width-ramp/

#include<vector>

namespace
{
	class Solution {
	public:
		int maxWidthRamp(std::vector<int>& nums) {
			std::vector<int> stack;
			stack.resize(nums.size());
			int size = 0;
			stack[size++] = 0;
			int ans = 0;
			for (unsigned int i = 1; i < nums.size(); i++)
			{
				if (nums[i] < nums[stack[size - 1]])
				{
					stack[size++] = i;
				}
			}

			int i = nums.size() - 1;
			for (;i>=0;i--)
			{
				if (size == 0)
				{
					break;
				}

				while (size > 0 && (nums[i] >= nums[stack[size - 1]]))
				{
					ans = std::max(ans, i - stack[size - 1]);
					size--;
				}
					
			}

			return ans;
		}
	};
}