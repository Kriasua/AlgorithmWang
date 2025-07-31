// 草一共有n的重量，两只牛轮流吃草，A牛先吃，B牛后吃
// 每只牛在自己的回合，吃草的重量必须是4的幂，1、4、16、64....
// 谁在自己的回合正好把草吃完谁赢，根据输入的n，返回谁赢
#include<iostream>
namespace
{

	char f(int rest, char cur)
	{
		char enemy = cur == 'A' ? 'B' : 'A';

		if (rest < 5)
		{
			if (rest == 0 || rest == 2)
			{
				return enemy;
			}
			else
			{
				return cur;
			}
		}

		int pick = 1;
		while (pick <= rest)
		{
			if (f(rest - pick, enemy) == cur)
			{
				return cur;
			}

			pick *= 4;
		}

		return enemy;
	}

	char winner(int grass)
	{
		return f(grass, 'A');
	}

	char winner2(int grass)
	{
		
		int ans = grass % 5;
		if (ans == 0 || ans == 2)
		{
			return 'B';
		}

		return 'A';
	}
}

