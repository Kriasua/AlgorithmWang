// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
// 测试链接 : https://leetcode.cn/problems/number-of-islands/

#include<vector>
namespace
{

	//用洪水填充做的。还有一个方法是用并查集做的。
	class Solution {
	public:

		void dfs(std::vector<std::vector<char>>& grid, int i, int j)
		{
			if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != '1')
			{
				return;
			}

			grid[i][j] = 0;
			dfs(grid, i - 1, j);
			dfs(grid, i + 1, j);
			dfs(grid, i, j + 1);
			dfs(grid, i, j - 1);
		}

		int numIslands(std::vector<std::vector<char>>& grid) {
			int islands = 0;
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if (grid[i][j] == '1')
					{
						islands++;
						dfs(grid, i, j);
					}
				}
			}
			return islands;
		}
	};
}