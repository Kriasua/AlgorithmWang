//https://leetcode.cn/problems/check-completeness-of-a-binary-tree/description/

#include<array>
#include "pch.h"
#include<queue>
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
                //破坏两条规则的
                if ((queue[l]->right != nullptr && queue[l]->left == nullptr)//1.有右没左
                    ||
                    ((isLeaf)&&(queue[l]->right != nullptr || queue[l]->left != nullptr)))//2.发现儿女不全的节点后，你这个不是叶节点
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

	class Solution2 {
	public:
		bool isCompleteTree(TreeNode* root) {
            std::queue<TreeNode*> queue;
            queue.push(root);
            bool bit = false;
            while (!queue.empty())
            {
                TreeNode* n = queue.front();
                queue.pop();
                if (n->left != nullptr)
                {
                    queue.push(n->left);
                }
                if (n->right != nullptr)
                {
                    queue.push(n->right);
                }

                if (n->right != nullptr && n->left == nullptr)
                {
                    return false;
                }


                if (!(n->left == nullptr && n->right == nullptr) && bit)
                {
                    return false;
                }

				if ((n->left != nullptr && n->right == nullptr)
					||
					(n->left == nullptr && n->right == nullptr))
				{
					bit = true;
				}


            }
            return true;
		}
	};
}