#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<climits>
#include<array>
//https://www.nowcoder.com/practice/7c4559f138e74ceb9ba57d76fd169967


namespace {
	std::unordered_map<int, std::array<int, 2>> myMap;
	int cnt = 0;
	int setAllVal = 0;
	int setAlltimes = -1;

	void setVal(int x, int y)
	{
		auto it = myMap.find(x);
		if (it == myMap.end())
		{
			myMap.emplace(x, std::array<int, 2>{y, cnt++});
		}
		else
		{
			it->second = std::array<int, 2>{ y,cnt++ };
		}
	}

	void setAll(int x)
	{
		setAllVal = x;
		setAlltimes = cnt++;
	}

	int find(int x)
	{
		auto it = myMap.find(x);
		if (it == myMap.end())
		{
			return -1;
		}
		else
		{
			return setAlltimes >= it->second.at(1) ? setAllVal : it->second.at(0);
		}
	}

	int n, opt, x, y;

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		while (std::cin >> n)
		{
			myMap.clear();
			cnt = 0;
			setAllVal = 0;
			setAlltimes = -1;
			for (int i = 0; i < n; i++)
			{
				std::cin >> opt;
				if (opt == 1)
				{
					std::cin >> x >> y;
					setVal(x, y);
				}
				else if (opt == 2)
				{
					std::cin >> x;
					std::cout << find(x) << '\n';
				}
				else
				{
					std::cin >> x;
					setAll(x);
				}

			}
		}
	}
}

namespace review
{
	int N;
	int opt;
	std::unordered_map<int, std::pair<int,int>> map;
	int setAll;
	int lastSet;
	int curTime;

	void clean()
	{
		map.clear();
		curTime = 0;
		setAll = 0;
		lastSet = -1;
	}

	void put(int x, int y)
	{
		map[x] = { y,curTime };
		curTime++;
	}

	int find(int x)
	{
		const auto& tar = map.find(x);
		if (tar == map.end())
		{
			return -1;
		}
		
		std::pair<int, int> p = map[x];
		if (p.second > lastSet)
		{
			return p.first;
		}
		else
		{
			return setAll;
		}
	}

	void set(int x)
	{
		setAll = x;
		lastSet = curTime++;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		while (std::cin >> N)
		{
			clean();
			for (int i = 0; i < N; i++)
			{
				std::cin >> opt;
				if (opt == 1)
				{
					int x, y;
					std::cin >> x >> y;
					put(x, y);
				}
				else if (opt == 2)
				{
					int x;
					std::cin >> x;
					std::cout << find(x) << "\n";
				}
				else
				{
					int x;
					std::cin >> x;
					set(x);
				}
			}
		}
	}
}
