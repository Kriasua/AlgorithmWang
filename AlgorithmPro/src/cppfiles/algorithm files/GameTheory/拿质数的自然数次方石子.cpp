// 质数次方版取石子(巴什博弈扩展)
// 一共有n颗石子，两个人轮流拿
// 每一轮当前选手可以拿 p的k次方 颗石子
// 当前选手可以随意决定p和k，但要保证p是质数、k是自然数
// 拿到最后一颗石子的人获胜
// 根据石子数返回谁赢
// 如果先手赢，返回"October wins!"
// 如果后手赢，输出"Roy wins!"
// 测试链接 : https://www.luogu.com.cn/problem/P4018

#include<iostream>
namespace
{
	int T, n;
	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cin >> T;

		for (int i = 0; i < T; i++)
		{
			std::cin >> n;
			if (n % 6 == 0)
			{
				std::cout << "Roy wins!" << "\n";
			}
			else
			{
				std::cout << "October wins!" << "\n";
			}
		}
		return 0;
	}
}