// 检查边长度限制的路径是否存在
// 给你一个 n 个点组成的无向图边集 edgeList
// 其中 edgeList[i] = [ui, vi, disi] 表示点 ui 和点 vi 之间有一条长度为 disi 的边
// 请注意，两个点之间可能有 超过一条边 。
// 给你一个查询数组queries ，其中 queries[j] = [pj, qj, limitj]
// 你的任务是对于每个查询 queries[j] ，判断是否存在从 pj 到 qj 的路径
// 且这条路径上的每一条边都 严格小于 limitj 。
// 请你返回一个 布尔数组 answer ，其中 answer.length == queries.length
// 当 queries[j] 的查询结果为 true 时， answer 第 j 个值为 true ，否则为 false
// 测试链接 : https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/

#include<vector>
#include<algorithm>
namespace
{
    using std::vector;
    class Solution {
    public:
        std::vector<int> fathers;
		int find(int num)
		{
			if (num == fathers[num])
			{
				return num;
			}

			int result = find(fathers[num]);
			fathers[num] = result;
			return result;
		}

		void Union(int a, int b)
		{
			int fa = find(a);
			int fb = find(b);

			if (fa != fb)
			{
				fathers[fa] = fb;
			}
			
		}

		bool isSameSet(int a, int b)
		{
			return find(a) == find(b);
		}

        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
			int m = queries.size();
            fathers.resize(n);
            for (int i = 0; i < n; i++)
            {
                fathers[i] = i;
            }

			//因为queries[i]是一个查询项，要把它的答案填到ans[i]里面
			//但是为了完成题目又需要把queries按照limit排序，会打乱顺序，所以
			//把queries数组搬到help数组，并且在help[i]后面加上index
			vector<vector<int>> help(m);
			for (int i = 0; i < m; i++)
			{
				help[i] = queries[i];
				help[i].push_back(i);
			}

			std::sort(help.begin(), help.end(), [](std::vector<int>& a, std::vector<int>& b)
				{
					return a[2] < b[2];
				});

			std::sort(edgeList.begin(), edgeList.end(), [](std::vector<int>& a, std::vector<int>& b)
				{
					return a[2] < b[2];
				});

			vector<bool> ans;
			ans.resize(m);

			//对help里每一个元素：在edgeList里面把所有权值 < limit的合并
			//合并完之后，如果在同一个集合里，说明存在路径，填入true
			int cur = 0;
			for (auto& col : help)
			{
				while (cur < edgeList.size() && edgeList[cur][2] < col[2])
				{
					Union(edgeList[cur][0], edgeList[cur][1]);
					cur++;
				}

				ans[col[3]] = isSameSet(col[0], col[1]) ? true : false;
			}

			return ans;

        }
    };
}