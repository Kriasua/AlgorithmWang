// 节点数为n高度不大于m的二叉树个数
// 现在有n个节点，计算出有多少个不同结构的二叉树
// 满足节点个数为n且树的高度不超过m的方案
// 因为答案很大，所以答案需要模上1000000007后输出
// 测试链接 : https://www.nowcoder.com/practice/aaefe5896cce4204b276e213e725f3ea

#include<iostream>
#include<vector>
namespace
{
	using LL = long long int;
	const int mod = 1000000007;
	const int MAXNM = 51;
	int n, m;
	std::vector<std::vector<LL>> dp(MAXNM, std::vector<LL>(MAXNM));

	LL f(int node, int height)
	{
		if (node == 0)
		{
			return 1;
		}

		if (height == 0)
		{
			return 0;
		}

		if (dp[node][height] != -1)
		{
			return dp[node][height];
		}

		LL ans = 0;
		for (int i = 0; i < node; i++)
		{
			ans += (f(i, height-1)%mod) * (f(node-1-i,height-1)%mod);
			ans %= mod;
		}


		dp[node][height] = ans % mod;
		return dp[node][height];
	}

	void f2()
	{
		for (int i = 0; i <= m;i++)
		{
			dp[0][i] = 1;
		}

		for (int j = 1; j <= m; j++)
		{
			for (int i = 1; i <= n; i++)
			{
				LL ans = 0;
				for (int k = 0; k < i; k++)
				{
					ans += (dp[k][j-1] % mod) * (dp[i - 1 - k][j - 1] % mod);
					ans %= mod;
				}
				dp[i][j] = ans % mod;
			}
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		while (std::cin >> n >> m)
		{
			for (int i = 0; i <= n; ++i) {
				std::fill(dp[i].begin(), dp[i].begin() + m + 1, 0);
			}
			//std::cout << f(n, m) << "\n";
			f2();
			std::cout << dp[n][m] << "\n";
			
		}
	}
}