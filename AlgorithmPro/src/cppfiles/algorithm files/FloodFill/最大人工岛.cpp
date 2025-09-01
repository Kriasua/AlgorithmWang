// 最大人工岛
// 给你一个大小为 n * n 二进制矩阵 grid 。最多 只能将一格 0 变成 1 。
// 返回执行此操作后，grid 中最大的岛屿面积是多少？
// 岛屿 由一组上、下、左、右四个方向相连的 1 形成
// 测试链接 : https://leetcode.cn/problems/making-a-large-island/
 
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
namespace
{
	class Solution {
	public:
		int id = 2;
		std::vector<int> cnt;
		int n;
		std::unordered_map<int, int> map;
		std::unordered_set<int> set;
		//dfs感染，给每个岛屿编号，从2开始
		int dfs(std::vector<std::vector<int>>& grid, int i, int j)
		{
			if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 1)
			{
				return 0;
			}

			grid[i][j] = id;
			return 1 + dfs(grid, i - 1, j)+
			dfs(grid, i + 1, j)+
			dfs(grid, i, j + 1)+
			dfs(grid, i, j - 1);
		}

		int addition(std::vector<std::vector<int>>& grid, int i, int j)
		{
			int up, down, left, right;
			//用数组模拟哈希表去重，为了防止多算
			//比如上面是3号岛，左边也是3号岛，就不能算两次
			set.clear();
			if (i == 0)
			{
				up = 0;
			}
			else
			{
				if (set.find(grid[i - 1][j]) != set.end())
				{
					up = 0;
				}
				else
				{
					up = map[grid[i - 1][j]];
					set.emplace(grid[i - 1][j]);
				}
			}

			if (i == n - 1)
			{
				down = 0;
			}
			else
			{
				if (set.find(grid[i + 1][j]) != set.end())
				{
					down = 0;
				}
				else
				{
					down = map[grid[i + 1][j]];
					set.emplace(grid[i + 1][j]);
				}
			}

			if (j == 0)
			{
				left = 0;
			}
			else
			{
				if (set.find(grid[i][j - 1]) != set.end())
				{
					left = 0;
				}
				else
				{
					left = map[grid[i][j - 1]];
					set.emplace(grid[i][j - 1]);
				}
			}

			if (j == n - 1)
			{
				right = 0;
			}
			else
			{
				if (set.find(grid[i][j + 1]) != set.end())
				{
					right = 0;
				}
				else
				{
					right = map[grid[i][j+1]];
					set.emplace(grid[i][j + 1]);
				}
			}

			return up + down + left + right + 1;

		}

		int largestIsland(std::vector<std::vector<int>>& grid) {
			id = 2;
			n = grid.size();
			
			int ans = 0;
			
			map.clear();

			//每发现一个陆地就调用dfs感染，顺便编号。
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if (grid[i][j] == 1)
					{
						map.emplace(id,dfs(grid, i, j));
						id++;
					}
				}
			}
			cnt.resize(id);


			//遍历整张地图，如果遇到0，就调用addition函数，查看这个0的上下左右有多少陆地，最后加起来
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if (grid[i][j] == 0)
					{
						ans = std::max(ans, addition(grid, i, j));
					}
				}
			}

			return ans == 0 ? n * n : ans;

		}
	};
}

