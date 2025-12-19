// 移除子树后的二叉树高度
// 给你一棵 二叉树 的根节点 root ，树中有 n 个节点
// 每个节点都可以被分配一个从 1 到 n 且互不相同的值
// 另给你一个长度为 m 的数组 queries
// 你必须在树上执行 m 个 独立 的查询，其中第 i 个查询你需要执行以下操作：
// 从树中 移除 以 queries[i] 的值作为根节点的子树
// 题目所用测试用例保证 queries[i] 不等于根节点的值
// 返回一个长度为 m 的数组 answer
// 其中 answer[i] 是执行第 i 个查询后树的高度
// 注意：
// 查询之间是独立的，所以在每个查询执行后，树会回到其初始状态
// 树的高度是从根到树中某个节点的 最长简单路径中的边数
// 测试链接 : https://leetcode.cn/problems/height-of-binary-tree-after-subtree-removal-queries/

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

		const int MAXN = 100005;
		int n;
		int count;
		std::vector<int> dnf;
		std::vector<int> sizes;
		std::vector<int> depths;
		std::vector<int> premax;
		std::vector<int> sufmax;

		int f(TreeNode* node, int depth)
		{
			if (node == nullptr)
			{
				return 0;
			}

			dnf[node->val] = ++count;
			depths[count] = depth;
			int tmep = count;
			int leftsize = f(node->left, depth + 1);
			int rightsize = f(node->right, depth + 1);
			sizes[tmep] = leftsize + rightsize + 1;
			return sizes[tmep];
		}

		std::vector<int> treeQueries(TreeNode* root, std::vector<int>& queries) {
			count = 0;
			int m = queries.size();
			std::vector<int> ans(m);
			dnf.resize(MAXN);
			sizes.resize(MAXN);
			depths.resize(MAXN);
			premax.resize(MAXN);
			sufmax.resize(MAXN);

			n = f(root, 0);
			int max = INT_MIN;
			for (int i = 1; i <= n; i++)
			{
				max = std::max(depths[i], max);
				premax[i] = max;
			}
			max = INT_MIN;
			for (int i = n; i >= 1; i--)
			{
				max = std::max(depths[i], max);
				sufmax[i] = max;
			}

			for (int i = 0;i<m;i++)
			{
				int DNF = dnf[queries[i]];
				int size = sizes[DNF];
				int right = DNF + size - 1;
				ans[i] = std::max(premax[DNF - 1], sufmax[right + 1]);
			}
			return ans;

		}
	};
}