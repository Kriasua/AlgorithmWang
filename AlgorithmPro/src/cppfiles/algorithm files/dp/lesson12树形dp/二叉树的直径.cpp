// 二叉树的直径
// 给你一棵二叉树的根节点，返回该树的直径
// 二叉树的 直径 是指树中任意两个节点之间最长路径的长度
// 这条路径可能经过也可能不经过根节点 root
// 两节点之间路径的 长度 由它们之间边数表示
// 测试链接 : https://leetcode.cn/problems/diameter-of-binary-tree/

#include<array>
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
		std::array<int, 2> f(TreeNode* node)
		{
			if (node == nullptr)
			{
				return { 0,0 };
			}

			std::array<int, 2> left = f(node->left);
			std::array<int, 2> right = f(node->right);
			int p1 = left[0] + right[0];
			int p2 = std::max(left[1], right[1]);

			int curAns = std::max(p1, p2);
			int curDepth = std::max(left[0], right[0]) + 1;
			return { curDepth,curAns };
		}

        int diameterOfBinaryTree(TreeNode* root) {
			std::array<int, 2> ans = f(root);
			return ans[1];
        }
    };
}