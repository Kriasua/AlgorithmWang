//二叉树展开为链表
//https://leetcode.cn/problems/flatten-binary-tree-to-linked-list/description/?envType=study-plan-v2&envId=top-100-liked

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

	//用辅助数组
	class Solution1 {
	public:

		void f(std::vector<TreeNode*>& help, TreeNode* node)
		{
			if (node == nullptr)
			{
				return;
			}

			help.push_back(node);
			f(help,node->left);
			f(help, node->right);
		}

		void flatten(TreeNode* root) {
			if (root == nullptr)
			{
				return;
			}

			std::vector<TreeNode*> help;
			f(help, root);
			TreeNode* cur = root;
			for (int i = 1; i < help.size(); i++)
			{
				cur->left = nullptr;
				cur->right = help[i];
				cur = help[i];
			}
			cur->left = nullptr;
			cur->right = nullptr;
		}
	};
}