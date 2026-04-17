// 一共有n堆石头，两人轮流进行游戏
// 在每个玩家的回合中，玩家需要选择任何一个非空的石头堆，并从这堆石头中移除任意正数的石头数量
// 谁先拿走最后的石头就获胜，返回最终谁会获胜
// 测试链接 : https://www.luogu.com.cn/problem/P2197

#include<vector>
#include<iostream>
namespace
{
	int T, n;

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		while (std::cin >> T)
		{
			for (int i = 0; i < T; i++)
			{
				std::cin >> n;
				int xorSum = 0;
				for (int j = 0; j < n; j++)
				{
					int stone;
					std::cin >> stone;
					xorSum ^= stone;
				}
				if (xorSum == 0)
				{
					std::cout << "No" << "\n";
				}
				else
				{
					std::cout << "Yes" << "\n";
				}
			}
		}
	}
}