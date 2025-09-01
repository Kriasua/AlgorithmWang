// ��ש��
// ��һ�� m * n �Ķ�Ԫ���� grid ������ 1 ��ʾש�飬0 ��ʾ�հ�
// ש�� �ȶ���������䣩��ǰ���ǣ�
// һ��שֱ�����ӵ�����Ķ���������
// ������һ�����ڣ�4 ������֮һ��ש�� �ȶ� �������ʱ
// ����һ������ hits ��������Ҫ��������ש���λ��
// ÿ������ hits[i] = (rowi, coli) λ���ϵ�ש��ʱ����Ӧλ�õ�ש�飨�����ڣ�����ʧ
// Ȼ��������ש�������Ϊ��һ���������� ����
// һ��ש����䣬���� ���� ������ grid ����ʧ���������������������ȶ���ש���ϣ�
// ����һ������ result ������ result[i] ��ʾ�� i ������������Ӧ�����ש����Ŀ��
// ע�⣬��������ָ����û��ש��Ŀհ�λ�ã�������������������û��ש����䡣
// �������� : https://leetcode.cn/problems/bricks-falling-when-hit/

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
			//ֻ��һ�е�����²�����ש����䣬ֱ�ӷ���
			if (grid.size() == 1)
			{
				return ans;
			}

			//�Ȱ�������λ-1
			for (auto& row : hits)
			{
				grid[row[0]][row[1]]--;
			}

			//���컨������ˮ��䣬�Ѻ��컨��������ש��ĳ�2
			for (int i = 0; i < grid[0].size(); i++)
			{
				if (grid[0][i] == 1)
				{
					dfs(grid, 0, i);
				}
			}

			//ʱ�⵹�����ɣ���֮ǰ�ļ�һ�ָ���
			//Ȼ�������ָ���ש���Ƿ��ȶ���1.�컨���ש��    2.�������ҵ�ש��������һ����2��Ҳ�����ȶ���ש�飩
			//ͳ�ƴ�
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