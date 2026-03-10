//¶þ²æÊ÷µÄÓÒÊÓÍ¼
//https://leetcode.cn/problems/binary-tree-right-side-view/?envType=study-plan-v2&envId=top-100-liked

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
		std::vector<int> rightSideView(TreeNode* root) {
			std::vector<int> ans;
			if (root == nullptr)
			{
				return ans;
			}

			std::vector<TreeNode*> queue;
			queue.resize(102);
			int left = 0;
			int right = 0;

			queue[right++] = root;
			while (left < right)
			{
				int edge = right;
				for (; left < edge; left++)
				{
					if (left == edge - 1)
					{
						ans.push_back(queue[left]->val);
					}

					if (queue[left]->left != nullptr)
					{
						queue[right++] = queue[left]->left;
					}

					if (queue[left]->right != nullptr)
					{
						queue[right++] = queue[left]->right;
					}
				}
			}

			return ans;
		}
	};
}