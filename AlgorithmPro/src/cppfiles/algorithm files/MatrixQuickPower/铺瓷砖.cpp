// 有两种形状的瓷砖，一种是2*1的多米诺形，另一种是形如"L"的托米诺形
// 两种形状都可以旋转，给定整数n，返回可以平铺2*n的面板的方法数量
// 返回对1000000007取模的值
// 测试链接 : https://leetcode.cn/problems/domino-and-tromino-tiling/

#include<vector>
#include<iostream>
namespace
{
	//递归做法
	class Solution1 {
	public:
		int mod = 1e9 + 7;

		int f(int n, int h, std::vector<std::vector<int>>& dp)
		{
			//h表示区域左方有没有单独多出来的一个格子
			if (n == 0)
			{
				if (h == 0)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}

			if (dp[h][n] != -1)
			{
				return dp[h][n];
			}

			int ans = 0;

			if (h == 0)
			{
				if (n >= 2)
				{
					ans = (ans + f(n - 2, 0,dp)) % mod;//横着铺多米诺形
					ans = (ans + (2 * f(n - 2, 1,dp))% mod) % mod;//铺L形
				}

				ans = (ans + f(n - 1, 0,dp)) % mod;//竖着铺多米诺形
				
			}
			else
			{
				
				ans = (ans + f(n - 1, 1,dp)) % mod;//用多米诺形铺多出来的那个格子
				
				ans = (ans + f(n - 1, 0,dp)) % mod;//铺L形
			}

			ans = ans % mod;
			dp[h][n] = ans;
			return ans;
		}

		int numTilings(int n) {
			std::vector<std::vector<int>> dp(2, std::vector<int>(n + 1,-1));
			return f(n, 0,dp);
		}
	};

	//矩阵快速幂
	using std::vector;
	using LL = long long int;
	class Solution2 {
	public:
		int mod = 1e9 + 7;

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
						temp = (temp + ((A[i][k] * B[k][j]) % mod)) % mod;
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

		int numTilings(int n) {
			if (n == 1)
			{
				return 1;
			}
			if (n == 2)
			{
				return 2;
			}
			if (n == 3)
			{
				return 5;
			}

			vector<vector<LL>> mat = { {2,1,0},{0,0,1},{1,0,0} };
			mat = matrixPW(mat, n - 3);

			return (((5 * mat[0][0]) % mod) + ((2 * mat[1][0]) % mod) + ((1 * mat[2][0]) % mod)) % mod;
		}
	};
}

