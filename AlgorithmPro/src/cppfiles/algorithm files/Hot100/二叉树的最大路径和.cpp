//二叉树的最大路径和
//https://leetcode.cn/problems/binary-tree-maximum-path-sum/description/?envType=study-plan-v2&envId=top-100-liked
#include<climits>
#include <algorithm>

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

	struct info
	{
		int p1;//以根节点为起点的最大路径和
		int p2;//最大路径和
	};

	class Solution {
	public:

		info f(TreeNode* node) {
			if (node == nullptr) {
				// p1 返回一个极小值，但在计算时要小心溢出
				// 或者返回 0 并配合特殊的逻辑处理
				return { -10001, INT_MIN }; // 题目范围通常是 -10000 到 10000
			}

			info infL = f(node->left);
			info infR = f(node->right);

			// 计算 p1：必须包含当前节点，要么只选自己，要么选自己+左，要么选自己+右
			int p1 = node->val + std::max({ 0, infL.p1, infR.p1 });

			// 计算 p2：
			// 情况1：路径不经过当前节点（左子树内部或右子树内部的最大路径）
			int p2_no_root = std::max(infL.p2, infR.p2);
			// 情况2：路径经过当前节点（左+根+右，但左右如果小于0则不取）
			int p2_with_root = node->val + std::max(0, infL.p1) + std::max(0, infR.p1);

			int p2 = std::max(p2_no_root, p2_with_root);

			return { p1, p2 };
		}

		int maxPathSum(TreeNode* root) {
			info ans = f(root);
			return ans.p2;
		}
	};
}