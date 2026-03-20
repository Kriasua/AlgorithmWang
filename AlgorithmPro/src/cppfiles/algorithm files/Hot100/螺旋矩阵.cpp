//螺旋矩阵
//https://leetcode.cn/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	class Solution {
	public:
		std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
			int m = matrix.size();
			int n = matrix[0].size();
			int allSize = m * n;
			std::vector<int> ans(allSize);
			std::vector<std::vector<bool>> visited(m, std::vector<bool>(n, false));
			std::vector<std::vector<int>> dir{ {0,1},{1,0},{0,-1},{-1,0} };
			int dirIdx = 0;
			int row = 0;
			int col = 0;
			for (int i = 0; i < allSize; i++)
			{
				ans[i] = matrix[row][col];
				visited[row][col] = true;

				int nextRow = row + dir[dirIdx][0];
				int nextCol = col + dir[dirIdx][1];

				//越界了，换方向
				if (nextRow < 0 || nextRow > m - 1 || nextCol < 0 || nextCol > n - 1)
				{
					dirIdx++;
					if (dirIdx == 4)
					{
						dirIdx = 0;
					}
				}
				//访问过了，换方向
				else if(visited[nextRow][nextCol])
				{
					dirIdx++;
					if (dirIdx == 4)
					{
						dirIdx = 0;
					}
				}
				else
				{

				}

				row = row + dir[dirIdx][0];
				col = col + dir[dirIdx][1];
			}
			return ans;
		}
	};
}