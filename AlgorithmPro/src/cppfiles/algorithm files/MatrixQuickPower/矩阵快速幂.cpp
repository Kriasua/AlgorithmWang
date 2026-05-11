#include<vector>
#include <cassert>

namespace
{
	using std::vector;
	using LL = long long int;

	vector<vector<LL>> multiply(vector<vector<LL>>& A, vector<vector<LL>>& B)
	{
		int n = A.size();
		vector<vector<LL>> ans(n, vector<LL>(n));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				LL temp = 0;
				for (int k = 0; k < n; k++)
				{
					temp += A[i][k] * B[k][j];
				}
				ans[i][j] = temp;
			}
		}
		return ans;
	}

	vector<vector<LL>> matrixPW(vector<vector<LL>> matrix, int pow)
	{
		assert(!matrix.empty() && matrix.size() == matrix[0].size());
		int n = matrix.size();
		vector<vector<LL>> ans(n, vector<LL>(n));
		for (int i = 0; i < n; i++)
		{
			ans[i][i] = 1;
		}

		while (pow > 0)
		{
			if ((1 & pow) != 0)
			{
				ans = multiply(ans, matrix);
			}
			matrix = multiply(matrix, matrix);
			pow >>= 1;
		}

		return ans;
	}
}