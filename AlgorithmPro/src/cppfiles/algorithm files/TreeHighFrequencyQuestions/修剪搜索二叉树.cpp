
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
        TreeNode* trimBST(TreeNode* root, int low, int high) {
            if (root == nullptr)
            {
                return nullptr;
            }

            if (root->val < low)
            {
                return trimBST(root->right, low, high);
            }

            if (root->val > high)
            {
                return trimBST(root->left, low, high);
            }

            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
            return root;

        }
    };

	class Solution1 {
	public:
		TreeNode* trimBST(TreeNode* root, int low, int high) {
            if (root == nullptr)
            {
                return nullptr;
            }
            else 
            {
				while (root != nullptr && (root->val < low || root->val > high))
				{
					if (root->val < low)
					{
						TreeNode* right = root->right;
						root = right;
					}
					else
					{
						TreeNode* left = root->left;
						root = left;
					}
				}
				if (root == nullptr)
				{
					return nullptr;
				}
                root->left = trimBST(root->left, low, high);
                root->right = trimBST(root->right, low, high);
                return root;
            }

		}
	};
}