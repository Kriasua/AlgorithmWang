// ���ʳ��������
// a -> b������a��ʳ�����б�b��ʳ
// ����һ�������޻�ͼ������
// ���ͼ�д���������ﵽ�����ʳ�ߵ�ʳ�����м���
// �������������ܹ�����ֻ��Ҫ�������ģ�� 80112002 �Ľ��
// �������� : https://www.luogu.com.cn/problem/P4017

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
			//�����������
			for (int i = 1; i <= n; i++)
			{
				graph[i].clear();
				inDegree[i] = 0;
				message[i] = 0;
				queue[i] = 0;
			}

			//��ͼ
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
				if (graph[cur].empty())  //��cur�ڵ����Ϊ0����ζ����ʳ���������
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
