/*现在有一个打怪类型的游戏，这个游戏是这样的，你有n个技能，每一个技能会有一个伤害，
同时若怪物低于一定的血量，则该技能可能造成双倍伤害，每一个技能最多只能释放一次，
已知怪物有m点血量，现在想问你最少用几个技能能消灭掉他（血量小于等于0）。
输入描述：
第一行输入一个整数T，代表有T组测试数据。

对于每一组测试数据，一行输入
2个整数n和m，代表有n个技能，怪物有m点血量。

接下来n行，每一行输入两个数A和x，代表该技能造成的伤害和怪物血量小于等于x的时候该技能会
造成双倍伤害
1≤T≤100
1≤n≤10
0≤m≤10 
1≤A,x≤m
输出描述：
对于每一组数据，输出一行，代表使用的最少技能数量，若无法消灭输出-1。*/
#include<array>
#include<climits>
#include<iostream>
#include<cmath>

namespace
{
	std::array<int, 11> skills;
	std::array<int, 11> threshold;

	void swap(int a, int b)
	{
		int temp = skills[a];
		skills[a] = skills[b];
		skills[b] = temp;
		temp = threshold[a];
		threshold[a] = threshold[b];
		threshold[b] = temp;
	}

	int f(int rest, int cur, int n)
	{
		if (cur == n)
		{
			if (rest > 0)
			{
				return 0x7fffffff;
			}

			return 0;
		}

		if (rest <= 0)
		{
			return 0;
		}

		int result = 0x7fffffff;
		int ans = 0;
		for (int i = cur; i < n; i++)
		{
			swap(i, cur);
			if (rest <= threshold[cur])
			{
				ans = f(rest - 2 * skills[cur], cur + 1, n);
			}
			else
			{
				ans = f(rest - skills[cur], cur + 1, n);
			}
			swap(i, cur);
			result = std::min(result, ans);
		}
		return result == 0x7fffffff? 0x7fffffff : result + 1;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		int T,n,m;
		std::cin >> T;
		while (T--)
		{
			std::cin >> n >> m;
			for (int j = 0; j < n; j++)
			{
				std::cin >> skills[j];
				std::cin >> threshold[j];
			}
			int result = f(m, 0, n);
			std::cout << (result == 0x7fffffff ? -1 : result) << "\n";
		}

	}
}

