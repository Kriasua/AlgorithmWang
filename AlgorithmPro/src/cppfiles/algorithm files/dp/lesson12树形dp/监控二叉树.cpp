// 监控二叉树
// 给定一个二叉树，我们在树的节点上安装摄像头
// 节点上的每个摄影头都可以监视其父对象、自身及其直接子对象
// 计算监控树的所有节点所需的最小摄像头数量
// 测试链接 : https://leetcode.cn/problems/binary-tree-cameras/

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
		int ans;

		int f(TreeNode* node)
		{
			if (node == nullptr)
			{
				return 0;
			}

			int left = f(node->left);
			int right = f(node->right);
			if (left == 1 || right == 1)
			{
				ans++;
				return 2;//2代表有覆盖，并且该位置有相机
			}

			if (left == 2 || right == 2)
			{
				return 0;//0代表有覆盖，但是没相机
			}

			return 1;//无覆盖且无相机
		}

		int minCameraCover(TreeNode* root) {
			ans = 0;
			if (f(root) == 1)
			{
				ans++;
			}
			return ans;
		}
	};
}