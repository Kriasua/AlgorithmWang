//腐烂的橘子
//https://leetcode.cn/problems/rotting-oranges/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	class Solution {
	public:
		int orangesRotting(std::vector<std::vector<int>>& grid) {
			int m = grid.size();
			int n = grid[0].size();
			std::vector<std::vector<int>> queue(105,std::vector<int>(2));
			int left = 0;
			int right = 0;
			int ans = 2;
			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j] == 2)
					{
						queue[right++] = { i,j };
					}
				}
			}

			while (left < right)
			{
				int x = queue[left][0];
				int y = queue[left++][1];
				//有上面
				if (x >= 1)
				{
					if (grid[x - 1][y] == 1)
					{
						grid[x - 1][y] = grid[x][y] + 1;
						queue[right++] = { x - 1,y };
					}
				}
				//有左边
				if (y >= 1)
				{
					if (grid[x][y - 1] == 1)
					{
						grid[x][y - 1] = grid[x][y] + 1;
						queue[right++] = { x, y - 1 };
					}
				}
				//有下面
				if (x < (m-1))
				{
					if (grid[x + 1][y] == 1)
					{
						grid[x + 1][y] = grid[x][y] + 1;
						queue[right++] = { x + 1,y };
					}
				}
				//有右边
				if (y < (n-1))
				{
					if (grid[x][y + 1] == 1)
					{
						grid[x][y + 1] = grid[x][y] + 1;
						queue[right++] = { x, y + 1 };
					}
				}

			}

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (grid[i][j] == 1)
					{
						return -1;
					}

					ans = std::max(ans, grid[i][j]);
				}
			}

			return ans - 2;
		}
	};
}