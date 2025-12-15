// 在二叉树中分配硬币
// 给你一个有 n 个结点的二叉树的根结点 root
// 其中树中每个结点 node 都对应有 node.val 枚硬币
// 整棵树上一共有 n 枚硬币
// 在一次移动中，我们可以选择两个相邻的结点，然后将一枚硬币从其中一个结点移动到另一个结点
// 移动可以是从父结点到子结点，或者从子结点移动到父结点
// 返回使每个结点上 只有 一枚硬币所需的 最少 移动次数
// 测试链接 : https://leetcode.cn/problems/distribute-coins-in-binary-tree/

#include<cmath>
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
			int coins;
			int nodes;
			int ans;
		};

		Info f(TreeNode* node)
		{
			if (node == nullptr)
			{
				return { 0,0,0 };
			}
			int curVal = node->val;
			Info l = f(node->left);
			Info r = f(node->right);
			int coins, nodes, ans;
			coins = l.coins + r.coins + node->val;
			nodes = l.nodes + r.nodes + 1;
			ans = l.ans + r.ans;
			int leftDiff = l.coins - l.nodes;
			int rightDiff = r.coins - r.nodes;
			ans += std::abs(leftDiff) + std::abs(rightDiff);
			return { coins,nodes,ans };
		}

		int distributeCoins(TreeNode* root) {
			Info info = f(root);
			return info.ans;
		}
	};
}