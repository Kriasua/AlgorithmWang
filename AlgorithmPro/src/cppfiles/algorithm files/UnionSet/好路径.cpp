// 好路径的数目
// 给你一棵 n 个节点的树（连通无向无环的图）
// 节点编号从0到n-1，且恰好有n-1条边
// 给你一个长度为 n 下标从 0 开始的整数数组 vals
// 分别表示每个节点的值。同时给你一个二维整数数组 edges
// 其中 edges[i] = [ai, bi] 表示节点 ai 和 bi 之间有一条 无向 边
// 好路径需要满足以下条件：开始和结束节点的值相同、 路径中所有值都小于等于开始的值
// 请你返回不同好路径的数目
// 注意，一条路径和它反向的路径算作 同一 路径
// 比方说， 0 -> 1 与 1 -> 0 视为同一条路径。单个节点也视为一条合法路径
// 测试链接 : https://leetcode.cn/problems/number-of-good-paths/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:
		int n;
		std::vector<int> father;
		std::vector<int> max;
		std::vector<int> maxCnts;
		int ans;
		int find(int num)
		{
			if (num == father[num])
			{
				return num;
			}

			int result = find(father[num]);
			father[num] = result;
			return result;
		}

		void Union(int a, int b)
		{
			int fa = find(a);
			int fb = find(b);

			if (fa == fb)
			{
				return;
			}

			if (max[fa] == max[fb])
			{
				ans += maxCnts[fa] * maxCnts[fb];
				maxCnts[fb] += maxCnts[fa];
			}
			else if (max[fa] > max[fb])
			{
				max[fb] = max[fa];
				maxCnts[fb] = maxCnts[fa];
			}
			else
			{

			}

			father[fa] = fb;
			
		}

		int numberOfGoodPaths(std::vector<int>& vals, std::vector<std::vector<int>>& edges) {
			//初始化并查集相关数据
			ans = 0;
			n = vals.size();
			father.resize(n);
			max.resize(n);
			maxCnts.resize(n,1);
			for (int i = 0; i < n; i++)
			{
				father[i] = i;
				max[i] = vals[i];
			}

			//根据最大值来排序edges数组
			std::sort(edges.begin(), edges.end(), [&](std::vector<int>& a, std::vector<int>& b)
				{
					return std::max(vals[a[0]], vals[a[1]]) < std::max(vals[b[0]], vals[b[1]]);
				});

			for (auto& edge : edges)
			{
				Union(edge[0], edge[1]);
			}

			//单独一个节点也是好路径，所以加n
			return ans + n;
		}
	};
}