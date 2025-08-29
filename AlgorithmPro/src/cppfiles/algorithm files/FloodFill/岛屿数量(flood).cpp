// ��������
// ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е��������
// �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γ�
// ���⣬����Լ��������������߾���ˮ��Χ
// �������� : https://leetcode.cn/problems/number-of-islands/

#include<vector>
namespace
{

	//�ú�ˮ������ġ�����һ���������ò��鼯���ġ�
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