// 知识竞赛
// 最近部门要选两个员工去参加一个需要合作的知识竞赛，
// 每个员工均有一个推理能力值ai，以及一个阅读能力值bi
// 如果选择第i个人和第j个人去参加竞赛，
// 两人在推理方面的能力为X = (ai + aj)/2
// 两人在阅读方面的能力为Y = (bi + bj)/2
// 现在需要最大化他们表现较差一方面的能力
// 即让min(X,Y) 尽可能大，问这个值最大是多少
// 测试链接 : https://www.nowcoder.com/practice/2a9089ea7e5b474fa8f688eae76bc050

#include<algorithm>
#include<vector>
#include<iostream>
#include <iomanip>
namespace
{
	int n;
	class node
	{
	public:
		int reasoning = 0;
		int reading = 0;
		node() = default;


		node(int reason, int read) : reasoning(reason), reading(read)
		{

		}

		bool operator<(const node& other) const
		{
			return std::abs(reasoning - reading) < std::abs(other.reasoning - other.reading);
		}


	};
	std::vector<node> people;
	constexpr int MAXN = 200005;

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		people.resize(MAXN);

		while (std::cin >> n)
		{
			for (int i = 0; i < n; i++)
			{
				int reason ,read;
				std::cin >> reason >> read;
				people[i] = node(reason, read);
			}

			std::sort(people.begin(), people.begin() + n);
			int ans = 0;
			int maxReasoning = people[0].reasoning;
			int maxReading = people[0].reading;
			for (int i = 1; i < n; i++)
			{
				int curReading = people[i].reading;
				int curReasoning = people[i].reasoning;
				if (curReading > curReasoning)
				{
					ans = std::max(ans, curReasoning + maxReasoning);
				}
				else
				{
					ans = std::max(ans, curReading + maxReading);
				}
				maxReasoning = std::max(maxReasoning, curReasoning);
				maxReading = std::max(maxReading, curReading);
			}
			float output = (float)ans / 2;
			std::cout << std::fixed << std::setprecision(1)<< output << "\n";
		}
	}
}