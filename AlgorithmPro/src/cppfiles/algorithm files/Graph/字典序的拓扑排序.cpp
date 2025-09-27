// �ֵ�����С����������
// Ҫ�󷵻�������ȷ������������ �ֵ�����С �Ľ��
// ��ͼ��ʹ����ʽǰ���Ƿ�ʽ����Ϊ����ƽ̨��������ͼ��ʽ�Ῠ�ռ�
// �������� : https://www.luogu.com.cn/problem/U107394
#include<vector>
#include<queue>
#include<iostream>
namespace
{
	//n��,m��
	int n, m, u, v;
	int MAX = 100001;
	std::vector<int> head;
	std::vector<int> next;
	std::vector<int> to;
	std::vector<int> inDegree;
	std::vector<int> ans;

	std::priority_queue<int,std::vector<int>,std::greater<int>> heap;
	int cnt;

	void build()
	{
		for (int i = 1; i <= n; i++) {
			head[i] = 0;
			inDegree[i] = 0;
		}
		cnt = 1;
		ans.clear();
	}

	void minusDegree(int cur)
	{
		int curEdge = head[cur];
		while (curEdge != 0)
		{
			if (--inDegree[to[curEdge]] == 0)
			{
				heap.push(to[curEdge]);
			}

			curEdge = next[curEdge];
		}
	}

	int main()
	{
		head.resize(MAX);
		next.resize(MAX);
		to.resize(MAX);
		inDegree.resize(MAX);
		

		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		while (std::cin >> n >> m)
		{
			build();
			std::priority_queue<int, std::vector<int>, std::greater<int>> empty_heap;
			heap.swap(empty_heap);
			for (int i = 0; i < m; i++)
			{
				//��ʽǰ���ǽ�ͼ
				std::cin >> u >> v;
				next[cnt] = head[u];
				head[u] = cnt;
				to[cnt++] = v;
				inDegree[v]++;
			}

			for (int i = 1; i <= n; i++)
			{
				if (inDegree[i] == 0)
				{
					heap.push(i);
				}
			}

			while (!heap.empty())
			{
				int Top = heap.top();
				heap.pop();
				minusDegree(Top);
				ans.push_back(Top);
				
			}

			for (int i = 0; i < n - 1; i++)
			{
				std::cout << ans[i] << " ";
			}

			std::cout <<ans.back()<< "\n";
		}
	}
}