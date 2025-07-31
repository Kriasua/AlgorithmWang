/*
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。

除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到
“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，
房屋将自动报警。

给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。*/
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

    class Solution {
    public:

        int yes;
        int no;

        void f(TreeNode* root)
        {
            if (root == nullptr)
            {
                yes = 0;
                no = 0;
            }
            else {
                int y = root->val;
                int n = 0;
                rob(root->left);
                y += no;
                n += std::max(yes, no);
                rob(root->right);
                y += no;
                n += std::max(yes, no);

                yes = y;
                no = n;
            }
        }
        int rob(TreeNode* root) {

            f(root);

            return std::max(yes, no);

        }
    };
}