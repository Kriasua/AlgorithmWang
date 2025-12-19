// 路径总和 III
// 给定一个二叉树的根节点 root ，和一个整数 targetSum
// 求该二叉树里节点值之和等于 targetSum 的 路径 的数目
// 路径 不需要从根节点开始，也不需要在叶子节点结束
// 但是路径方向必须是向下的（只能从父节点到子节点）
// 测试链接 : https://leetcode.cn/problems/path-sum-iii/
#include<iostream>
#include<unordered_map>
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
		int ans = 0;

		void f(TreeNode* node, int targetSum, long long int sum, std::unordered_map<long long int, int>& preSum)
		{
			if (node == nullptr)
			{
				return;
			}

			sum += node->val;
			long long int k = sum - targetSum;
			if (preSum.contains(k))
			{
				ans += preSum[k];
			}
			preSum[sum]++;
			f(node->left, targetSum, sum, preSum);
			f(node->right, targetSum, sum, preSum);
			preSum[sum]--;
		}

		int pathSum(TreeNode* root, int targetSum) {
			std::unordered_map<long long int, int> preSum;
			preSum.emplace(0,1);
			f(root, targetSum, 0, preSum);
			return ans;
		}
	};
}

