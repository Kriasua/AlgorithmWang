// ��һ����n����������ֻţ�����Բݣ�Aţ�ȳԣ�Bţ���
// ÿֻţ���Լ��Ļغϣ��Բݵ�����������4���ݣ�1��4��16��64....
// ˭���Լ��Ļغ����ðѲݳ���˭Ӯ�����������n������˭Ӯ
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

