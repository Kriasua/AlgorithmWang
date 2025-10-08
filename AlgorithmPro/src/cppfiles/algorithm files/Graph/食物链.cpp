// 最大食物链计数
// a -> b，代表a在食物链中被b捕食
// 给定一个有向无环图，返回
// 这个图中从最初级动物到最顶级捕食者的食物链有几条
// 由于这个结果可能过大，你只需要输出总数模上 80112002 的结果
// 测试链接 : https://www.luogu.com.cn/problem/P4017

#include<vector>
#include<iostream>
namespace
{
	int n, m, A, B;
	constexpr int MAX = 5000;
	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		std::vector<std::vector<int>> graph;
		std::vector<int> inDegree;
		std::vector<int> message;
		std::vector<int> queue;
		int L = 0;
		int R = 0;

		inDegree.resize(MAX);
		graph.resize(MAX);
		message.resize(MAX);
		queue.resize(MAX);

		while (std::cin >> n >> m)
		{
			L = 0;
			R = 0;
			//清空所有数组
			for (int i = 1; i <= n; i++)
			{
				graph[i].clear();
				inDegree[i] = 0;
				message[i] = 0;
				queue[i] = 0;
			}

			//建图
			for (int i = 0; i < m; i++)
			{
				std::cin >> A >> B;
				graph[A].push_back(B);
				inDegree[B]++;
			}


			for (int i = 1; i <= n; i++)
			{
				if (inDegree[i] == 0)
				{
					queue[R++] = i;
					message[i] = 1;
				}
			}

			int cur;
			int ans = 0;
			while (L < R)
			{
				cur = queue[L++];
				if (graph[cur].empty())  //该cur节点出度为0，意味着是食物链的最顶端
				{
					ans = (ans + message[cur]) % 80112002;
				}
				else
				{
					for (int num : graph[cur])
					{
						if (--inDegree[num] == 0)
						{
							queue[R++] = num;
						}

						message[num] = (message[num] + message[cur]) % 80112002;
					}
				}
			}

			std::cout << ans << "\n";
			
		}
	}
}
