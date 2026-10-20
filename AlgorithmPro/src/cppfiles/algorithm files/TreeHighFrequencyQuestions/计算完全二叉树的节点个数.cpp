//https://leetcode.cn/problems/count-complete-tree-nodes/description/
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

        int mostLeft(TreeNode* node, int level)
        {
            while (node != nullptr)
            {
                level++;
                node = node->left;
            }

            return level - 1;
        }

        int f(TreeNode* root, int cur, int h)
        {
            if (cur == h)
            {
                return 1;
            }

            if (mostLeft(root->right,cur+1) == h)
            {
                return (1 << h - cur) + f(root->right, cur + 1, h);
            }
            else
            {
                return (1 << h - cur - 1) + f(root->left, cur + 1, h);
            }
        }

        int countNodes(TreeNode* root) {

            if (root == nullptr)
            {
                return 0;
            }

            return f(root, 1, mostLeft(root, 1));
        }
    };

	class Solution1 {
	public:

        int mostleft(TreeNode* root, int cur)
        {
			while (root != nullptr)
			{
				root = root->left;
				cur++;
			}
            return cur - 1;
        }

        int f(TreeNode* root, int cur, int h)
        {
            if (cur == h)
            {
                return 1;
            }

            int rightLevel = mostleft(root->right, cur + 1);
            if (rightLevel == h)
            {
                return (1 << (h - cur)) + f(root->right, cur + 1, h);
            }
            else
            {
                return (1 << (h - cur - 1)) + f(root->left, cur + 1, h);
            }


        }

		int countNodes(TreeNode* root) {
            if (root == nullptr)
            {
                return 0;
            }
            int h = 0;
            TreeNode* head = root;
            while (root != nullptr)
            {
                root = root->left;
                h++;
            }

            return f(head, 1, h);
		}
	};
}