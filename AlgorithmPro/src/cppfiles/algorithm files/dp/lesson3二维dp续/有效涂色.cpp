// 有效涂色问题
// 给定n、m两个参数
// 一共有n个格子，每个格子可以涂上一种颜色，颜色在m种里选
// 当涂满n个格子，并且m种颜色都使用了，叫一种有效方法
// 求一共有多少种有效的涂色方法
// 1 <= n, m <= 5000
// 结果比较大请 % 1000000007 之后返回
// 对数器验证

#include<vector>
namespace
{
	//算阶乘
	int f(int num)
	{
		int ans = num;
		while (num != 1)
		{
			ans *= num - 1;
			num--;
		}
		return ans;
	}

	int fillCellsUseAllColorWays(int n, int m)
	{
		if (n < m)
		{
			return 0;
		}

		std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
		//当j比i大时，也就是颜色比格子多，没有答案，返回0
		//j == i时，也就是对角线位置
		//举例：3种颜色填3个格子，6种填法。
		for (int i = 0; i <= m; i++)
		{
			dp[i][i] = f(i);
		}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				dp[i][j] = dp[i - 1][j] * j;
				dp[i][j] += dp[i - 1][j - 1] * j;
			}
		}

		return dp[n][m];
	}


}