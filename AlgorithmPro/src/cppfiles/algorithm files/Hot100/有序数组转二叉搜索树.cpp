//有序数组转二叉搜索树
//https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	struct TreeNode {
		int val;
		TreeNode* left;
		TreeNode* right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

	};

	class Solution {
	public:

		TreeNode* f(std::vector<int>& nums, int left, int right)
		{
			if (left > right)
			{
				return nullptr;
			}

			if (left == right)
			{
				TreeNode* node = new TreeNode(nums[left]);
				return node;
			}

			int mid = left + (right - left) / 2;
			TreeNode* node = new TreeNode(nums[mid]);
			node->left = f(nums, left, mid - 1);
			node->right = f(nums, mid + 1, right);
			return node;
		}

		TreeNode* sortedArrayToBST(std::vector<int>& nums) {
			return f(nums, 0, nums.size() - 1);
		}
	};
}