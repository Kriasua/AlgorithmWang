#include<array>
#include<vector>
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
    private:
        std::array<TreeNode*, 2001> queue;
        int l, r;
    public:
        std::vector<std::vector<int>> levelOrder(TreeNode* root) {
            l = 0;
            r = 0;
            int size;
            std::vector<std::vector<int>> ans;
            if (root == nullptr)
            {

                return ans;
            }

            queue[r++] = root;
            while (l < r)
            {
                size = r - l;
                std::vector<int> nums;
                for (int i = 0; i < size; i++)
                {
                    nums.push_back(queue[l]->val);
                    if (queue[l]->left != nullptr)
                    {
                        queue[r++] = queue[l]->left;
                    }
                    if (queue[l]->right != nullptr)
                    {
                        queue[r++] = queue[l]->right;
                    }
                    l++;
                }
                ans.push_back(nums);
            }
            return ans;

        }
    };

    ////////////////////////Ç¿»¯°æ£º¾â³Ý×´±éÀú//////////////////////////////

    class Solution2 {
    public:
        std::array<TreeNode*, 2001> queue;
        int l, r;
        bool reverse = false;
        std::vector<std::vector<int>> zigzagLevelOrder(TreeNode* root) {
            std::vector<std::vector<int>> ans;
            if (root == nullptr)
            {
                return ans;
            }

            l = r = 0;
            queue[r++] = root;

            while (l < r)
            {
                int size = r - l;
                std::vector<int> nums;
                if (!reverse)
                {
                    for (int i = l; i < r; i++)
                    {
                        nums.push_back(queue[i]->val);
                    }

                }
                else
                {
                    for (int i = r; i > l; i--)
                    {
                        nums.push_back(queue[i - 1]->val);
                    }
                }


                for (int i = 0; i < size; i++)
                {
                    if (queue[l]->left != nullptr)
                    {
                        queue[r++] = queue[l]->left;
                    }

                    if (queue[l]->right != nullptr)
                    {
                        queue[r++] = queue[l]->right;
                    }
                    l++;
                }

                ans.push_back(nums);
                reverse = !reverse;
            }
            return ans;

        }
    };

}