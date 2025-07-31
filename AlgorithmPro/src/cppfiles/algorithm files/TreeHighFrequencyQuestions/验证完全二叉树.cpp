#include<array>
#include "pch.h"
namespace{

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    };

    constexpr int MAX = 101;
    class Solution {
    public:
        std::array<TreeNode*, MAX> queue;
        int l, r;

        bool isCompleteTree(TreeNode* root) {
            if (root == nullptr)
            {
                return true;
            }

            if (root->left == nullptr && root->right == nullptr)
            {
                return true;
            }

            l = r = 0;
            bool ans = true;
            bool isLeaf = false;
            queue[r++] = root;
            while (l < r)
            {
                //�ƻ����������
                if ((queue[l]->right != nullptr && queue[l]->left == nullptr)//1.����û��
                    ||
                    ((isLeaf)&&(queue[l]->right != nullptr || queue[l]->left != nullptr)))//2.���ֶ�Ů��ȫ�Ľڵ�����������Ҷ�ڵ�
                {
                    return false;
                }

                if (queue[l]->left != nullptr)
                {
                    queue[r++] = queue[l]->left;
                }

                if (queue[l]->right != nullptr)
                {
                    queue[r++] = queue[l]->right;
                }

                if (queue[l]->left == nullptr || queue[l]->right == nullptr)
                {
                    isLeaf = true;
                }
                l++;

            }
            return ans;
        }
    };
}