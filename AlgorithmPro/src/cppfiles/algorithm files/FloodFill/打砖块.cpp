// 打砖块
// 有一个 m * n 的二元网格 grid ，其中 1 表示砖块，0 表示空白
// 砖块 稳定（不会掉落）的前提是：
// 一块砖直接连接到网格的顶部，或者
// 至少有一块相邻（4 个方向之一）砖块 稳定 不会掉落时
// 给你一个数组 hits ，这是需要依次消除砖块的位置
// 每当消除 hits[i] = (rowi, coli) 位置上的砖块时，对应位置的砖块（若存在）会消失
// 然后其他的砖块可能因为这一消除操作而 掉落
// 一旦砖块掉落，它会 立即 从网格 grid 中消失（即，它不会落在其他稳定的砖块上）
// 返回一个数组 result ，其中 result[i] 表示第 i 次消除操作对应掉落的砖块数目。
// 注意，消除可能指向是没有砖块的空白位置，如果发生这种情况，则没有砖块掉落。
// 测试链接 : https://leetcode.cn/problems/bricks-falling-when-hit/

#include<vector>
namespace
{
	using std::vector;
	class Solution {
	public:



		int dfs(vector<vector<int>>& grid, int i, int j)
		{
			if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 1)
			{
				return 0;
			}

			grid[i][j] = 2;
			return 1 + dfs(grid, i - 1, j)+
			dfs(grid, i + 1, j)+
			dfs(grid, i, j + 1)+
			dfs(grid, i, j - 1);
		}

		bool worth(vector<vector<int>>& grid, int i, int j)
		{
			return grid[i][j] == 1
				&&
				(i == 0 ||
					(j > 0 && grid[i][j - 1] == 2) ||
					(j < grid[0].size() - 1 && grid[i][j + 1] == 2) ||
					(i > 0 && grid[i-1][j] == 2) ||
					(i < grid.size() - 1 && grid[i+1][j] == 2));
		}

		vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
			vector<int> ans;
			ans.resize(hits.size());
			//只有一行的情况下不会有砖块掉落，直接返回
			if (grid.size() == 1)
			{
				return ans;
			}

			//先把所有炮位-1
			for (auto& row : hits)
			{
				grid[row[0]][row[1]]--;
			}

			//在天花板做洪水填充，把和天花板相连的砖块改成2
			for (int i = 0; i < grid[0].size(); i++)
			{
				if (grid[0][i] == 1)
				{
					dfs(grid, 0, i);
				}
			}

			//时光倒流技巧，把之前的减一恢复。
			//然后必须检查恢复的砖块是否稳定（1.天花板的砖块    2.上下左右的砖块至少有一块是2，也就是稳定的砖块）
			//统计答案
			for (int i = hits.size() - 1,x,y; i >= 0; i--)
			{
				x = hits[i][0];
				y = hits[i][1];
				grid[x][y]++;
				if (worth(grid, x, y))
				{
					ans[i] = dfs(grid, x, y) - 1;
				}
				else
				{
					ans[i] = 0;
				}
			}

			return ans;
		}
	};
}