// 最大BST子树
// 给定一个二叉树，找到其中最大的二叉搜索树（BST）子树，并返回该子树的大小
// 其中，最大指的是子树节点数最多的
// 二叉搜索树（BST）中的所有节点都具备以下属性：
// 左子树的值小于其父（根）节点的值
// 右子树的值大于其父（根）节点的值
// 注意：子树必须包含其所有后代
// 测试链接 : https://leetcode.cn/problems/largest-bst-subtree/

#include<vector>
namespace
{
	class Solution
	{
	public:
		struct TreeNode {
			int val;
			TreeNode* left;
			TreeNode* right;
			TreeNode() : val(0), left(nullptr), right(nullptr) {}
			TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
			TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
		};

		struct returnInfo
		{
			bool isBST;
			int ans;
			int min;
			int max;
		};

		returnInfo f(TreeNode* node)
		{
			if (node == nullptr)
			{
				return { true, 0, INT_MAX, INT_MIN };
			}

			returnInfo cur;
			bool curIsBST = true;
			returnInfo left = f((*node).left);
			returnInfo right = f(node->right);

			if (!left.isBST || !right.isBST)
			{
				curIsBST = false;
			}

			if (node->left != nullptr && node->val <= left.max)
			{
				curIsBST = false;
			}

			if (node->right != nullptr && node->val >= right.min)
			{
				curIsBST = false;
			}

			if (curIsBST)
			{
				cur.ans = left.ans + right.ans + 1;
			}
			else
			{
				cur.ans = std::max(left.ans, right.ans);
			}

			cur.isBST = curIsBST;
			cur.min = std::min(std::min(left.min, right.min), node->val);
			cur.max = std::max(std::max(left.max, right.max), node->val);
			return cur;
		}

		int largestBSTSubTree(TreeNode* root)
		{
			returnInfo info = f(root);
			return info.ans;
		}
	};

	
}