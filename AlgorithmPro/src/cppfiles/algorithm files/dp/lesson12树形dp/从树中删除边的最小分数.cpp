// 从树中删除边的最小分数
// 存在一棵无向连通树，树中有编号从0到n-1的n个节点，以及n-1条边
// 给你一个下标从0开始的整数数组nums长度为n，其中nums[i]表示第i个节点的值
// 另给你一个二维整数数组edges长度为n-1
// 其中 edges[i] = [ai, bi] 表示树中存在一条位于节点 ai 和 bi 之间的边
// 删除树中两条不同的边以形成三个连通组件，对于一种删除边方案，定义如下步骤以计算其分数：
// 分别获取三个组件每个组件中所有节点值的异或值
// 最大 异或值和 最小 异或值的 差值 就是这种删除边方案的分数
// 返回可能的最小分数
// 测试链接 : https://leetcode.cn/problems/minimum-score-after-removals-on-a-tree/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:

		const int MAXN = 1005;
		int cnt;
		std::vector<int> dfn;
		std::vector<int> sizes;
		std::vector<int> xors;
		std::vector<std::vector<int>> tree;

		struct Info
		{
			int size;
			int xorVal;
		};
		
		Info f(int node, int father, std::vector<int>& nums)
		{
			int id = ++cnt;
			dfn[node] = id;
			Info info;
			for (int num : tree[node])
			{
				if (num != father)
				{
					info = f(num, node, nums);
					sizes[id] += info.size;
					xors[id] ^= info.xorVal;
				}
			}
			sizes[id]++;
			xors[id] ^= nums[node];

			return { sizes[id] , xors[id] };
		}

		int minimumScore(std::vector<int>& nums, std::vector<std::vector<int>>& edges) {
			cnt = 0;
			dfn.assign(MAXN, 0);
			sizes.assign(MAXN, 0);
			xors.assign(MAXN, 0);
			// tree 需要清空
			tree.assign(MAXN, std::vector<int>());
			int ans = INT_MAX;

			//建树，双向
			for (auto& edge : edges)
			{
				tree[edge[0]].push_back(edge[1]);
				tree[edge[1]].push_back(edge[0]);
			}

			//填写dfn,sizes,xors数组
			f(0, -1, nums);

			int n = edges.size();

			for (int i = 0; i < n - 1; i++)
			{
				int bigi = std::max(dfn[edges[i][0]], dfn[edges[i][1]]);
				for (int j = i + 1; j < n; j++)
				{
					int bigj = std::max(dfn[edges[j][0]], dfn[edges[j][1]]);
					int smaller = std::min(bigi, bigj);
					int bigger = std::max(bigi, bigj);
					int sizeSmaller = smaller + sizes[smaller] - 1;

					//意味着断掉的两条边属于同一颗字树
					if (bigger <= sizeSmaller)
					{
						int p1 = xors[smaller] ^ xors[1];
						int p2 = xors[smaller] ^ xors[bigger];
						int p3 = xors[bigger];
						int min = std::min(p1, std::min(p2, p3));
						int max = std::max(p1, std::max(p2, p3));
						ans = std::min(ans, max - min);
					}
					else
					{
						int p1 = xors[smaller] ^ xors[bigger] ^ xors[1];
						int min = std::min(p1, std::min(xors[bigger], xors[smaller]));
						int max = std::max(p1, std::max(xors[bigger], xors[smaller]));
						ans = std::min(ans, max - min);
					}
				}
			}

			return ans;
		}
	};
}