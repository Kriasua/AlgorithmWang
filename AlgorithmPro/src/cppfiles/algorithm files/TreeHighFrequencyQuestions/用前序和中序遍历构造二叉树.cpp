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

	class Solution {
	public:
        TreeNode* f(std::vector<int>& preorder, std::vector<int>& inorder, int a, int b, int c, int d)
        {
            if (a > b)
            {
                return nullptr;
            }

            int target = preorder[a];
            int find;
            for (int i = c; i <= d; i++)
            {
                if (inorder[i] == target)
                {
                    find = i;
                }
            }

            TreeNode* n = new TreeNode(target);
            n->left = f(preorder, inorder, a + 1, a + find - c, c, find - 1);
            n->right = f(preorder, inorder, a + find - c + 1, b, find + 1, d);
            return n;
        }

		TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
            return f(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
		}
	};
}