#include<cmath>
#include<algorithm>
#include<cstdint>
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


    //左神的方法，全局变量法，为了处理节点值就是INT_MAX的情况，设置long long类型
    long long Minn;
    long long Maxx;

    class Solution {
    public:
        bool isValidBST(TreeNode* root) {
            if (root == nullptr)
            {
                Minn = LLONG_MAX;
                Maxx = LLONG_MIN;
                return true;
            }

            bool lok = isValidBST(root->left);
            long long lmin = Minn;
            long long lmax = Maxx;
            bool rok = isValidBST(root->right);
            long long rmin = Minn;
            long long rmax = Maxx;

            Minn = std::min(std::min(lmin, rmin), static_cast<long long>(root->val));
            Maxx = std::max(std::max(lmax, rmax), static_cast<long long>(root->val));
            
            return lok && rok && root->val > lmax && root->val < rmin;


        }
    };


    //我认为更好的方法，来自Deepseek
    /*
    这个方法的核心思想是：​​在递归过程中，动态维护每个节点值的合法范围（即上下界），
    并通过参数传递这些约束条件​​。以下是逐步解析：
    minNode​​：
    表示当前节点值的 ​​理论下界​​（必须大于该节点的值）。若为 nullptr，表示无下界限制。
    ​​maxNode​​：
    表示当前节点值的 ​​理论上界​​（必须小于该节点的值）。若为 nullptr，表示无上界限制

    ​​1.终止条件​​：
    如果当前节点为空，返回 true（空树是合法的BST）。
    ​​2.边界检查​​：
    如果 minNode 非空且 root->val <= minNode->val → 违反了下界规则。
    如果 maxNode 非空且 root->val >= maxNode->val → 违反了上界规则。
    ​​3.递归传递约束​​：
    ​​左子树​​：继承父节点的下界，上界设为当前节点值（因为左子树的所有值必须 < root->val）。
    ​​右子树​​：继承父节点的上界，下界设为当前节点值（因为右子树的所有值必须 > root->val）。
    */
    class Solution2 {
    public:
        bool isValidBST(TreeNode* root) {
            return helper(root, nullptr, nullptr);
        }

        bool helper(TreeNode* root, TreeNode* minNode, TreeNode* maxNode) {
            if (!root) return true;
            if ((minNode && root->val <= minNode->val) ||
                (maxNode && root->val >= maxNode->val)) {
                return false;
            }
            return helper(root->left, minNode, root) &&
                helper(root->right, root, maxNode);
        }
    };
}