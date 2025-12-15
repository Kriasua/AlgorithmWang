// 二叉搜索子树的最大键值和
// 给你一棵以 root 为根的二叉树
// 请你返回 任意 二叉搜索子树的最大键值和
// 二叉搜索树的定义如下：
// 任意节点的左子树中的键值都 小于 此节点的键值
// 任意节点的右子树中的键值都 大于 此节点的键值
// 任意节点的左子树和右子树都是二叉搜索树
// 测试链接 : https://leetcode.cn/problems/maximum-sum-bst-in-binary-tree/

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

		struct Info
		{
			int min;
			int max;
			bool isBST;
			int maxSum;
			int sum;

			Info() {};
			Info(int Min, int Max, bool is, int MaxSum, int Sum) : min(Min), max(Max), isBST(is), maxSum(MaxSum), sum(Sum) {};
		};

		Info f(TreeNode* node)
		{
			if (node == nullptr)
			{
				return Info(INT_MAX, INT_MIN, true, 0, 0);
			}

			Info left = f(node->left);
			Info right = f(node->right);


			Info info;
			if (left.isBST && right.isBST && node->val > left.max && node->val < right.min)
			{
				info.isBST = true;
			}
			else
			{
				info.isBST = false;
			}

			int p1 = INT_MIN;
			if (info.isBST)
			{
				p1 = left.sum + right.sum + node->val;
			}
			int p2 = std::max(left.maxSum, right.maxSum);
			info.maxSum = std::max(p1, p2);
			info.min = std::min(std::min(left.min, right.min), node->val);
			info.max = std::max(std::max(left.max, right.max), node->val);
			info.sum = left.sum + right.sum + node->val;
			return info;
		}

        int maxSumBST(TreeNode* root) {
			Info info = f(root);
			return info.maxSum;
        }
    };
}