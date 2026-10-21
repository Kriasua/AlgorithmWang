#include<vector>
//给一个数组，问这个数组是不是某个二叉搜索树的后序遍历
//https://leetcode.cn/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/

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

	class Solution1 {
	public:
		bool f(std::vector<int>& postorder, int l, int r)
		{
			if (l >= r)
			{
				return true;
			}

			int root = postorder[r];
			int i = l;
			while (i < r && postorder[i] < root)
			{
				i++;
			}

			for (int j = i; j < r; j++)
			{
				if (postorder[j] < root)
				{
					return false;
				}
			}

			return f(postorder, l, i - 1) && f(postorder, i, r - 1);
		}

		bool verifyTreeOrder(std::vector<int>& postorder) {
			if (postorder.empty())
			{
				return true;
			}

			return f(postorder, 0, postorder.size() - 1);
		}
	};
}