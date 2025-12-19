// 相邻字符不同的最长路径
// 给你一棵 树（即一个连通、无向、无环图），根节点是节点 0
// 这棵树由编号从 0 到 n - 1 的 n 个节点组成
// 用下标从 0 开始、长度为 n 的数组 parent 来表示这棵树
// 其中 parent[i] 是节点 i 的父节点
// 由于节点 0 是根节点，所以 parent[0] == -1
// 另给你一个字符串 s ，长度也是 n ，其中 s[i] 表示分配给节点 i 的字符
// 请你找出路径上任意一对相邻节点都没有分配到相同字符的 最长路径
// 并返回该路径的长度
// 测试链接 : https://leetcode.cn/problems/longest-path-with-different-adjacent-characters/

#include<string>
#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:

		std::pair<int, int> f(std::vector<std::vector<int>>& tree, std::string& s, int node)
		{
			//pair的含义：{从当前节点一路往下扎，字符要不同，能扎多深？ ， 当前节点的答案是多少}
			if (tree[node].empty())
			{
				return { 1,1 };
			}
			std::vector<std::pair<int, int>> infos;
			int p1 = 0;
			int p2 = 0;

			std::pair<int, int> max1 = {0,0};
			std::pair<int, int> max2 = {0,0};
			for (int num : tree[node])
			{
				std::pair<int, int> pair = f(tree, s, num);
				p2 = std::max(p2, pair.second);
				if (s[node] != s[num])
				{
					if (pair.first >= max1.first)
					{
						max2 = max1;
						max1 = pair;
					}
					else if (pair.first >= max2.first)
					{
						max2 = pair;
					}
				}
			}
			p1 = max1.first + max2.first + 1;
			return { max1.first + 1, std::max(p1,p2) };
			
		}

		int longestPath(std::vector<int>& parent, std::string s) {
			int n = s.size();
			std::vector<std::vector<int>> tree(n);
			for (int i = 1; i < n; i++)
			{
				tree[parent[i]].push_back(i);
			}
			return f(tree, s, 0).second;
		}
	};
}