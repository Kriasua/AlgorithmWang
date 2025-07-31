/*������һ��������͵���Ϸ�������Ϸ�������ģ�����n�����ܣ�ÿһ�����ܻ���һ���˺���
ͬʱ���������һ����Ѫ������ü��ܿ������˫���˺���ÿһ���������ֻ���ͷ�һ�Σ�
��֪������m��Ѫ�������������������ü������������������Ѫ��С�ڵ���0����
����������
��һ������һ������T��������T��������ݡ�

����ÿһ��������ݣ�һ������
2������n��m��������n�����ܣ�������m��Ѫ����

������n�У�ÿһ������������A��x������ü�����ɵ��˺��͹���Ѫ��С�ڵ���x��ʱ��ü��ܻ�
���˫���˺�
1��T��100
1��n��10
0��m��10 
1��A,x��m
���������
����ÿһ�����ݣ����һ�У�����ʹ�õ����ټ������������޷��������-1��*/
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

