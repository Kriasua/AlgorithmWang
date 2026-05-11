// 三堆石头拿取斐波那契数博弈
// 有三堆石头，数量分别为a、b、c
// 两个人轮流拿，每次可以选择其中一堆石头，拿取斐波那契数的石头
// 拿到最后一颗石子的人获胜，根据a、b、c返回谁赢
// 来自真实大厂笔试，每堆石子的数量在10^5以内
// 没有在线测试，对数器验证

#include<vector>
#include<iostream>
namespace
{
	std::vector<int> printSGTable(int n)
	{
		int MAXN = n;
		std::vector<int> sg(MAXN);
		std::vector<bool> appear(30);
		std::vector<int> fibonacci = { 1,2 };
		fibonacci.resize(26);
		for (int i = 2; i < 26; i++)
		{
			fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
		}

		for (int i = 1; i < MAXN; i++)
		{
			int j = 0;
			std::fill(appear.begin(), appear.end(), false);
			while (fibonacci[j] <= i)
			{
				appear[sg[i - fibonacci[j]]] = true;
				j++;
			}

			for (int k = 0; k < MAXN; k++)
			{
				if (!appear[k])
				{
					sg[i] = k;
					break;
				}
			}
		}

		return sg;
		
	}

	void win(int a, int b, int c)
	{
		std::vector<int> sg = printSGTable(100002);
		int eor = sg[a] ^ sg[b] ^ sg[c];
		if (eor == 0)
		{
			std::cout << "后手赢" << std::endl;
		}
		else
		{
			std::cout << "先手赢" << std::endl;
		}
	}
}
