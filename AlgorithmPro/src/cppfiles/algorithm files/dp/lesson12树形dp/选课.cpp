// 选课，树上01背包的普通解法
// 在大学里每个学生，为了达到一定的学分，必须从很多课程里选择一些课程来学习
// 在课程里有些课程必须在某些课程之前学习，如高等数学总是在其它课程之前学习
// 现在有 N 门功课，每门课有个学分，每门课有一门或没有直接先修课
// 若课程 a 是课程 b 的先修课即只有学完了课程 a，才能学习课程 b
// 一个学生要从这些课程里选择 M 门课程学习
// 问他能获得的最大学分是多少
// 测试链接 : https://www.luogu.com.cn/problem/P2014

#include<iostream>
#include<vector>
namespace
{
	int n, m;
	constexpr int MAXN = 305;
	constexpr int MAXM = 305;
	std::vector<std::vector<int>> tree;
	std::vector<int> credits;
	std::vector<std::vector<std::vector<int>>> dp;

	int f(int i, int j, int k)
	{
		if (k == 0)
		{
			return 0;
		}

		if (k == 1 || j == 0)
		{
			return credits[i];
		}

		if (dp[i][j][k] != -1)
		{
			return dp[i][j][k];
		}

		int ans = 0;

		int p1 = f(i, j - 1, k);
		int jsize = tree[tree[i][j - 1]].size();
		int p2 = 0;
		for (int s = 1; s <= k - 1; s++)
		{
			p2 = std::max(p2, f(tree[i][j - 1], jsize, s) + f(i, j - 1, k - s));
		}

		ans = std::max(p1, p2);
		dp[i][j][k] = ans;
		return ans;
	}

	int compute()
	{
		return f(0, tree[0].size(), m);
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		tree.resize(MAXN);
		credits.resize(MAXN);
		dp.resize(MAXN, std::vector<std::vector<int>>(MAXN, std::vector<int>(MAXN, -1)));

		while (std::cin >> n >> m)
		{
			m++;
			int ki, si;
			tree.assign(MAXN, std::vector<int>());
			dp.assign(MAXN, std::vector<std::vector<int>>(MAXN, std::vector<int>(MAXN, -1)));

			for (int i = 1; i <= n; i++)
			{
				std::cin >> ki >> si;
				credits[i] = si;
				tree[ki].push_back(i);
			}
			std::cout << compute() << "\n";
		}
	}
}