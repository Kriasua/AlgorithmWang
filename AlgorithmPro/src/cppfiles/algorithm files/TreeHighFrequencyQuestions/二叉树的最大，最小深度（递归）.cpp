struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};

class Solution {
    int max(int a, int b)
    {
        return a > b ? a : b;
    }
        
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return max(maxDepth(root->left), maxDepth(root->right)) + 1;
        }

    }
};

class Solution2 {
public:
    int min(int a, int b)
    {
        return a > b ? b : a;
    }

    int minDepth(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        if (root->left == nullptr && root->right == nullptr)
        {
            return 1;
        }

        int ldeep = 0x7fffffff;
        int rdeep = 0x7fffffff;

        if (root->left != nullptr)
        {
            ldeep = minDepth(root->left);
        }

        if (root->right != nullptr)
        {
            rdeep = minDepth(root->right);
        }

        return min(ldeep,rdeep)+1;


    }
};

