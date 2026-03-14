//æÿ’Û÷√¡„
//https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	//ø’º‰O(m*n)£¨≤ª∫√
	class Solution1 {
	public:

		void setZero(std::vector<std::vector<int>>& matrix, int x, int y)
		{
			int m = matrix.size();
			int n = matrix[0].size();
			for (int i = 0; i < m; i++)
			{
				matrix[i][y] = 0;
			}

			for (int i = 0; i < n; i++)
			{
				matrix[x][i] = 0;
			}
		}

		void setZeroes(std::vector<std::vector<int>>& matrix) {
			int m = matrix.size();
			int n = matrix[0].size();
			std::vector<std::vector<int>> queue(m*n,std::vector<int>(2));
			int left = 0;
			int right = 0;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][j] == 0)
					{
						queue[right++] = { i,j };
					}
				}
			}

			while (left < right)
			{
				int x = queue[left][0];
				int y = queue[left++][1];
				setZero(matrix, x, y);
			}
		}
	};

	class Solution2 {
	public:
		void setZeroes(std::vector<std::vector<int>>& matrix) {
			int m = matrix.size();
			int n = matrix[0].size();
			
			std::vector<bool> isRows(m,false);
			std::vector<bool> isCols(n,false);

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (matrix[i][j] == 0)
					{
						isRows[i] = true;
						isCols[j] = true;
					}
				}
			}

			for (int i = 0; i < m; i++)
			{
				if (isRows[i])
				{
					for (int col = 0; col < n; col++)
					{
						matrix[i][col] = 0;
					}
				}
			}

			for (int i = 0; i < n; i++)
			{
				if (isCols[i])
				{
					for (int row = 0; row < m; row++)
					{
						matrix[row][i] = 0;
					}
				}
			}

		}
	};
}