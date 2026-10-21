//https://leetcode.cn/problems/balanced-binary-tree/submissions/756150556/
#include<cmath>
#include<algorithm>
#include "pch.h"
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

    bool isBalance = true;

    class Solution {
    public:

        int height(TreeNode* root)
        {
            if (root == nullptr)
            {
                return 0;
            }

            int l = height(root->left);
            int r = height(root->right);

            if (std::abs(l - r) > 1)
            {
                isBalance = false;
            }

            return std::max(l, r) + 1;
        }

        bool isBalanced(TreeNode* root) {
            if (root == nullptr)
            {
                return true;
            }

            isBalance = true;
            height(root);
            return isBalance;
        }
    };

	class Solution1 {
	public:
        struct info
        {
            int height;
            bool isBal;
        };

        info f(TreeNode* node)
        {
            if (node == nullptr)
            {
                return { 0,true };
            }

            info l = f(node->left);
            info r = f(node->right);
            info ans;
            ans.height = std::max(l.height, r.height) + 1;
            ans.isBal = l.isBal && r.isBal && (std::abs(l.height - r.height) <= 1);

            return ans;
        }

		bool isBalanced(TreeNode* root) {
            info ans = f(root);
            return ans.isBal;
		}
	};
}