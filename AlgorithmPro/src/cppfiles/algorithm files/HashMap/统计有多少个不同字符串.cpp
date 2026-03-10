// 统计有多少个不同的字符串
// 测试链接 : https://www.luogu.com.cn/problem/P3370

#include<iostream>
#include<string>
#include<vector>
#include<unordered_set>
#include <cstdint>
namespace
{
	int N;
	constexpr int MAXM = 1502;
	constexpr int MAXN = 10005;
	const int base = 599;
	std::vector<std::string> strings;
	std::vector<uint64_t> powers;
	std::unordered_set<uint64_t> set;

	uint64_t calHashValue(std::string& str)
	{
		int size = str.size();
		uint64_t ans = 0;

		for (int i = 0; i < size; i++)
		{
			uint64_t tmp = str[i] - '0' + 1;
			ans += tmp * powers[i];
		}

		return ans;
	}

	int count()
	{
		set.clear();
		for (int i = 0; i < N; i++)
		{
			uint64_t value = calHashValue(strings[i]);
			set.emplace(value);
		}
		return set.size();
	}

	void precompute()
	{
		powers[0] = 1;
		for (int i = 1; i < MAXM; i++)
		{
			powers[i] = powers[i - 1] * base;
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		strings.resize(MAXN);
		powers.resize(MAXM);
		precompute();
		while (std::cin >> N)
		{
			for (int i = 0; i < N; i++)
			{
				std::cin >> strings[i];
			}
			std::cout << count() << "\n";
		}
	}
}