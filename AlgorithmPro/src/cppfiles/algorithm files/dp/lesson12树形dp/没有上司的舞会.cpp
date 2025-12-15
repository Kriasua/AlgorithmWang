// 没有上司的舞会
// 某大学有n个职员，编号为1...n
// 他们之间有从属关系，也就是说他们的关系就像一棵以校长为根的树
// 父结点就是子结点的直接上司
// 现在有个周年庆宴会，宴会每邀请来一个职员都会增加一定的快乐指数 
// 但是如果某个职员的直接上司来参加舞会了
// 那么这个职员就无论如何也不肯来参加舞会了
// 所以请你编程计算邀请哪些职员可以使快乐指数最大
// 返回最大的快乐指数。
// 测试链接 : https://www.luogu.com.cn/problem/P1352

#include<iostream>
#include<vector>

namespace
{
	int n;
	constexpr int MAXN = 6005;
	std::vector<int> happy;
	std::vector<std::vector<int>> tree;
	std::vector<int> yes;
	std::vector<int> no;
	std::vector<bool> has_boss;
	void build()
	{
		for (int i = 1; i <= n; i++)
		{
			tree[i].clear();
			yes[i] = 0;
			no[i] = 0;
			has_boss[i] = false;
		}
	}

	void f(int num)
	{
		if (tree[num].empty())
		{
			yes[num] = happy[num];
			no[num] = 0;
		}

		yes[num] = happy[num];
		for (int staff : tree[num])
		{
			f(staff);
			yes[num] += no[staff];
			no[num] += std::max(yes[staff], no[staff]);
		}
	}

	int compute(int boss)
	{
		f(boss);
		return std::max(yes[boss], no[boss]);
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		happy.resize(MAXN);
		tree.resize(MAXN);
		yes.resize(MAXN);
		no.resize(MAXN);
		has_boss.resize(MAXN, false);
		while (std::cin >> n)
		{
			build();
			for (int i = 1; i <= n; i++)
			{
				std::cin >> happy[i];
			}
			int l, k, boss;
			for (int i = 1; i < n; i++)
			{
				std::cin >> l >> k;
				tree[k].push_back(l);
				has_boss[l] = true;
			}

			for (int i = 1; i <= n; i++)
			{
				if (has_boss[i] == false)
				{
					boss = i;
					break;
				}
			}
			std::cout << compute(boss) << "\n";
		}
		return 0;
	}
}