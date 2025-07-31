// ��װ��8��ƻ���Ĵ��ӡ�װ��6��ƻ���Ĵ��ӣ�һ��Ҫ��֤��ƻ��ʱ����ʹ�õĴ��Ӷ�װ��
// �����޷�װ�����д��ӵķ������迼�ǣ�����n��ƻ������������Ҫ���ٸ�����
// ���������ÿ�����Ӷ�װ���ķ�������-1
#include<iostream>
namespace Welly
{

	int f(int rest)
	{
		if (rest == 0)
		{
			return 0;
		}

		if (rest < 0)
		{
			return 0x7fffffff;   // std::INT_MAX
		}

		int case1 = f(rest - 8); //-1
		int case2 = f(rest - 6); //0
		
		if (case1 == 0x7fffffff && case2 == 0x7fffffff)
		{
			return 0x7fffffff;
		}

		int min = case1 < case2 ? case1 : case2;
		min++;
		return min;


	}

	int findMinBag(int apple)
	{
		if (apple == 0)
		{
			return -1;
		}
		int ans = f(apple);
		return ans == 0x7fffffff ? -1 : ans;
	}

	//���ñ����ݹ��ҹ��ɣ��ҵ�����ֱ�Ӵ��

	int findMinBag2(int apple)
	{
		if (apple >= 0 && apple <= 5)
		{
			return -1;
		}

		if (apple & 1)
		{
			return -1;
		}

		if (apple == 6 || apple == 8 )
		{
			return 1;
		}

		if (apple == 10)
		{
			return -1;
		}

		if (apple == 12 || apple == 14 || apple == 16)
		{
			return 2;
		}

		int ans = (apple - 18) / 8;
		return ans + 3;

	}
}

