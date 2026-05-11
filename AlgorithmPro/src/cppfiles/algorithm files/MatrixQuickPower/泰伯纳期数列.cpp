// 第n个泰波那契数
// t(0) = 0, t(1) = 1, t(2) = 1
// t(i) = t(i-1) + t(i-2) + t(i-3)
// 求t(n)
// 测试链接 : https://leetcode.cn/problems/n-th-tribonacci-number/
#include<vector>

namespace
{
	using std::vector;
	using LL = long long int;
	class Solution {
	public:
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

		vector<vector<LL>> matrixPW(vector<vector<LL>>& matrix, int pow)
		{
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

		int tribonacci(int n) {
			vector<vector<LL>> mat = { {1,1,0},{1,0,1},{1,0,0} };
			if (n == 0)
			{
				return 0;
			}
			if (n == 1)
			{
				return 1;
			}
			if (n == 2)
			{
				return 1;
			}

			mat = matrixPW(mat, n - 2);
			return mat[0][0] + mat[1][0];
		}
	};
}