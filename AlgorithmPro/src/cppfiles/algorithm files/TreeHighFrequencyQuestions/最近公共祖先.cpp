

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
        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

            if (root == p || root == q || root == nullptr)
            {
                return root;
            }

            TreeNode* left = lowestCommonAncestor(root->left, p, q);
            TreeNode* right = lowestCommonAncestor(root->right,p,q);

            if (left == nullptr && right == nullptr)
            {
                return nullptr;
            }

            if (left != nullptr && right != nullptr)
            {
                return root;
            }
            
            return left ? left : right;


        }
    };

    //////////////////////////////////变形：二叉搜索树的公共祖先/////////////////////////////////

    class Solution2 {
    public:
        int min(int a, int b)
        {
            return a > b ? b : a;
        }

        int max(int a, int b)
        {
            return a > b ? a : b;
        }

        TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
            while (root != p && root != q)
            {
                if ((root->val > min(p->val, q->val)) && (root->val < max(p->val, q->val)))
                {
                    break;
                }

                root = root->val < min(p->val, q->val) ? root->right : root->left;

            }

            return root;

        }
    };
}