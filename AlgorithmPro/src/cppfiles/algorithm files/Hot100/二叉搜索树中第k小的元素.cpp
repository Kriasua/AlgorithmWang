//二叉搜索书中第k小的元素
//https://leetcode.cn/problems/kth-smallest-element-in-a-bst/description/?envType=study-plan-v2&envId=top-100-liked
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
		std::vector<int> nums;

		void f(TreeNode* node)
		{
			if (node == nullptr)
			{
				return;
			}

			f(node->left);
			nums.push_back(node->val);
			f(node->right);
		}

		int kthSmallest(TreeNode* root, int k) {
			nums.clear();
			f(root);
			return nums[k - 1];
		}
	};
}