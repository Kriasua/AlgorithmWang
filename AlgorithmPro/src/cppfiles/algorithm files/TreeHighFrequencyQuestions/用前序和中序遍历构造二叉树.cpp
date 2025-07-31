#include<vector>
#include<unordered_map>
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

        TreeNode* f(std::vector<int>& preorder, int prel, int prer, std::vector<int>& inorder, int inl, int inr
        ,std::unordered_map<int,int>& map)
        {
            if (prel > prer)
            {
                return nullptr;
            }

            TreeNode* head = new TreeNode(preorder[prel]);

            if (prer == prel)
            {
                return head;
            }

            int it = map[preorder[prel]];
            int leftTree = it - inl;
            head->left = f(preorder, prel + 1, prel + leftTree, inorder, inl, it - 1,map);
            head->right = f(preorder, prel + leftTree+1 ,prer ,inorder,it+1 ,inr ,map);
    
            return head;
        }

        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
            std::unordered_map<int, int> map;
            int i = 0;
            for (int val : inorder)
            {
                map.emplace(val, i++);
            }
            return f(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1,map);
        }
    };
}