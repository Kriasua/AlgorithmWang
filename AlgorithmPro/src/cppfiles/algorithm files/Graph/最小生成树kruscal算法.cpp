// Kruskal算法模版（洛谷）
// 静态空间实现
// 测试链接 : https://www.luogu.com.cn/problem/P3366

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
namespace
{
	constexpr int MAXM = 200001;
	constexpr int MAXN = 5001;
	//N节点数   M边数
	int N, M;
	std::vector<std::array<int, 3>> graph;
	std::vector<int> fathers;

	void build()
	{
		for (int i = 1; i <= N; i++)
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
		fathers.resize(MAXN);
		graph.resize(MAXM);

		while (std::cin >> N >> M)
		{
			build();
			for (int i = 0; i < M; i++)
			{
				std::cin >> graph[i][0] >> graph[i][1] >> graph[i][2];
			}

			std::sort(graph.begin(), graph.begin() + M, [](std::array<int, 3>& a, std::array<int, 3>& b)
				{
					return a[2] < b[2];
				});

			int cnt = 0;
			int ans = 0;
			for (int i = 0; i < M; i++)
			{
				if (Union(graph[i][0], graph[i][1]))
				{
					cnt++;
					ans += graph[i][2];
				}
			}

			if (cnt == N - 1)
			{
				std::cout << ans << "\n";
			}
			else
			{
				std::cout << "orz" << "\n";
			}
			
		}
	}
		
}