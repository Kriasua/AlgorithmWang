// 繁忙的都市
// 一个非常繁忙的大都市，城市中的道路十分的拥挤，于是市长决定对其中的道路进行改造
// 城市的道路是这样分布的：城市中有n个交叉路口，有些交叉路口之间有道路相连
// 两个交叉路口之间最多有一条道路相连接，这些道路是双向的
// 且把所有的交叉路口直接或间接的连接起来了
// 每条道路都有一个分值，分值越小表示这个道路越繁忙，越需要进行改造
// 但是市政府的资金有限，市长希望进行改造的道路越少越好，于是他提出下面的要求：
// 1. 改造的那些道路能够把所有的交叉路口直接或间接的连通起来
// 2. 在满足要求1的情况下，改造的道路尽量少
// 3. 在满足要求1、2的情况下，改造的那些道路中分值最大的道路分值尽量小
// 作为市规划局的你，应当作出最佳的决策，选择哪些道路应当被修建
// 返回选出了几条道路 以及 分值最大的那条道路的分值是多少
// 测试链接 : https://www.luogu.com.cn/problem/P2330

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
namespace
{
	int n, m;
	constexpr int MAXn = 301;
	constexpr int MAXm = 8001;
	std::vector<int> fathers;

	void build()
	{
		for (int i = 1; i <= n; i++)
		{
			fathers[i] = i;
		}
	}

	int find(int num)
	{
		if (num == fathers[num])
		{
			return num;
		}

		int result = find(fathers[num]);
		fathers[num] = result;
		return result;
	}

	bool Union(int a, int b)
	{
		int fa = find(a);
		int fb = find(b);

		if (fa != fb)
		{
			fathers[fa] = fb;
			return true;
		}
		else
		{
			return false;
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::vector<std::array<int,3>> edgeLists;
		edgeLists.resize(MAXm);
		fathers.resize(MAXn);

		while (std::cin >> n >> m)
		{
			build();
			for (int i = 0; i < m; i++)
			{
				std::cin >> edgeLists[i][0] >> edgeLists[i][1] >> edgeLists[i][2];
			}

			std::sort(edgeLists.begin(), edgeLists.begin() + m, [](std::array<int, 3>& a, std::array<int, 3>& b)
				{
					return a[2] < b[2];
				});

			int s = 0;
			int Max = 0;

			for (auto& col : edgeLists)
			{
				if (Union(col[0], col[1]))
				{
					s++;
					Max = std::max(Max, col[2]);
				}

				if (s == n - 1)
				{
					break;
				}
			}

			std::cout << n - 1 << " " << Max << "\n";
		}

	}
}