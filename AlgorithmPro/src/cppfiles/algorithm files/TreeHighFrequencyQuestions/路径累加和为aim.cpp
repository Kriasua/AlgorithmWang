#include<vector>
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

        void f(TreeNode* cur, int sum, int aim, std::vector<int>& path, std::vector<std::vector<int>>& ans)
        {
            //当前为叶节点
            if (cur->left == nullptr && cur->right == nullptr)
            {
                if (cur->val + sum == aim)
                {
                    path.push_back(cur->val);
                    ans.push_back(path);
                    path.pop_back();
                }
            }
            else
            {
                path.push_back(cur->val);
                if (cur->left != nullptr)
                {
                    f(cur->left, sum + cur->val, aim, path, ans);
                }
                if (cur->right != nullptr)
                {
                    f(cur->right, sum + cur->val, aim, path, ans);
                }
                path.pop_back();
            }
        }

        std::vector<std::vector<int>> pathSum(TreeNode* root, int targetSum) {
            std::vector<std::vector<int>> ans;
            if (root == nullptr)
            {
                return ans;
            }
            std::vector<int> path;
            f(root, 0, targetSum, path, ans);
            return ans;
        }
    };
}