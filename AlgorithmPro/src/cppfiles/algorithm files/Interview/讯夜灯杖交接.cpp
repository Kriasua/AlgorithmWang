//https://www.nowcoder.com/discuss/861268371394867200?sourceSSR=dynamic
//打开链接自己看吧
#include<vector>
#include<map>
#include<list>
#include<iostream>
namespace
{
	constexpr int MAXN = 1002;

	//双向链表模拟队列，因为排中间的人可能会在中途退出，不符合传统队列先进先出
	std::list<int> queue;

	//事件表，按照位置从小到大排列
	//key为坐标，value为在这个坐标上发生的事件
	//pair<i,0>表示发生了i人的入队事件，1则表示出队
	std::map<int, std::vector<std::pair<int,int>>> map;

	//每个人的贡献值
	std::vector<int> contributions;
	int n;

	void build()
	{
		std::fill(contributions.begin(), contributions.end(), 0);
		queue.clear();
		map.clear();
	}

	void compute()
	{
		int lastPos = map.begin()->first;
		for (auto& [pos, events] : map)
		{
			int dist = pos - lastPos;
			if (dist > 0)
			{
				if (!queue.empty())
				{
					contributions[queue.front()] += dist;
				}
				else
				{
					//这个是特殊情况，表明灯杖在上一个位置，并且队列空了，所以这个位置的人要回去取灯杖
					//只可能有一人进队，也只可能发生这个人进队这一个事件（思考为什么）
					contributions[events[0].first] += dist;
				}
			}

			for (auto& event : events)
			{
				if (event.second == 0)
				{
					queue.push_back(event.first);
				}
				else
				{
					queue.remove(event.first);
				}
			}

			lastPos = pos;
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		contributions.resize(MAXN);
		int start;
		int end;
		while (std::cin >> n)
		{
			build();
			for (int i = 0; i < n; i++)
			{
				std::cin >> start >> end;
				
				map[start].push_back( { i,0 });
				map[end].push_back( { i,1 });
			}
			compute();
			for (int i = 0; i < n - 1; i++)
			{
				std::cout << contributions[i] << " ";
			}
			std::cout << contributions[n - 1] << "\n";
		}
	}
}