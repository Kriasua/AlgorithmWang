// 飞行路线（语言提供的堆）
// Alice和Bob现在要乘飞机旅行，他们选择了一家相对便宜的航空公司
// 该航空公司一共在n个城市设有业务，设这些城市分别标记为0 ~ n−1
// 一共有m种航线，每种航线连接两个城市，并且航线有一定的价格
// Alice 和 Bob 现在要从一个城市沿着航线到达另一个城市，途中可以进行转机
// 航空公司对他们这次旅行也推出优惠，他们可以免费在最多k种航线上搭乘飞机
// 那么 Alice 和 Bob 这次出行最少花费多少
// 测试链接 : https://www.luogu.com.cn/problem/P4568

#include<vector>
#include<queue>
#include<iostream>
#include<array>
#include <climits>
namespace
{
	struct compare
	{
		bool operator()(const std::array<int, 3>& a, const std::array<int, 3>& b)
		{
			return a[1] > b[1];
		}
	};

	//n == city Num    m == edge Num
	int n, m, k;
	constexpr int MAXN = 10001;
	constexpr int MAXM = 100001;
	constexpr int MAXK = 10;
	int start, end;
	std::vector<int> head;
	std::vector<int> next;
	std::vector<std::array<int,2>> to;
	std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;
	std::vector<std::vector<bool>> visited;
	std::vector<std::vector<int>> distances;

	void build()
	{
		for (int i = 0; i <= n; i++)
		{
			head[i] = 0;
		}


		for (int i=0;i<=k;i++)
		{
			for (int j = 0; j < n; j++)
			{
				visited[i][j] = false;
				distances[i][j] = INT_MAX;
			}
		}
		std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> empty_heap;
		heap.swap(empty_heap);
		
	}

	int dijkstra()
	{
		heap.push({ start,0,k });
		distances[k][start] = 0;
		while (!heap.empty())
		{
			auto top = heap.top();
			int city = top[0];
			int cost = top[1];
			int free = top[2];
			heap.pop();

			if (visited[free][city])
			{
				continue;
			}

			if (city == end)
			{
				return cost;
			}

			visited[free][city] = true;

			for (int edge = head[city + 1]; edge != 0; edge = next[edge])
			{
				auto& nextNode = to[edge];

				if (free > 0 && distances[free - 1][nextNode[0]] > cost)
				{
					heap.push({ nextNode[0] ,cost,free - 1 });
					distances[free - 1][nextNode[0]] = cost;
				}

				if (distances[free][nextNode[0]] > cost + nextNode[1])
				{
					heap.push({ nextNode[0] ,cost + nextNode[1],free });
					distances[free][nextNode[0]] = cost + nextNode[1];
				}

			}

		}
		return -1;

	}
	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		head.resize(MAXN+1);
		next.resize(MAXM+1);
		to.resize(MAXM+1);
		visited.resize(MAXK+1);
		distances.resize(MAXK+1);
		for (int i = 0; i < MAXK + 1; i++)
		{
			visited[i].resize(MAXN);
			distances[i].resize(MAXN);
		}

		while (std::cin >> n >> m >> k)
		{
			build();
			std::cin >> start >> end;
			
			//链式前向星建图
			int cnt = 1;
			for (int i = 0,s,e,w; i < m; i++)
			{
				std::cin >> s >> e >> w;
				next[cnt] = head[s + 1];
				head[s + 1] = cnt;
				to[cnt++] = { e,w };

				next[cnt] = head[e + 1];
				head[e + 1] = cnt;
				to[cnt++] = { s,w };
			}

			std::cout << dijkstra() << "\n";

		}
	}
}