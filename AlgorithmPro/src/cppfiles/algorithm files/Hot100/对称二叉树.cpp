//¶Ô³Æ¶þ²æÊ÷
//https://leetcode.cn/problems/symmetric-tree/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
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

		bool f(TreeNode* node1, TreeNode* node2)
		{
			if (node1 == nullptr && node2 == nullptr)
			{
				return true;
			}

			if (node1 == nullptr || node2 == nullptr || node1->val != node2->val )
			{
				return false;
			}

			bool p1 = f(node1->left, node2->right);
			bool p2 = f(node2->left, node1->right);
			return p1 && p2;
		}

        bool isSymmetric(TreeNode* root) {
			return f(root->left, root->right);
        }
    };
}