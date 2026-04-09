#include<vector>
//给一个数组，问这个数组是不是某个二叉搜索树的后序遍历

namespace {
	class Solution
	{
	public:
		bool f(int l, int r, std::vector<int>& nums)
		{
			if (l >= r)
			{
				return true;
			}

			int edge = l - 1;
			int pivot = nums[r];
			while (edge < r - 1 && nums[edge + 1] < pivot)
			{
				edge++;
			}

			for (int i = edge + 1; i < r; i++)
			{
				if (nums[i] < pivot)
				{
					return false;
				}
			}

			bool isLeft = f(l, edge, nums);
			bool isRight = f(edge + 1, r - 1, nums);
			return isLeft && isRight;
		}

		bool isBinarySearchTree(std::vector<int>& nums)
		{
			return f(0, nums.size() - 1, nums);
		}
	};
}