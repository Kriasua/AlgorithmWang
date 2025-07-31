#include<iostream>
#include "pch.h"
// �����κ��ж����ͱȽϲ��������������������ֵ
namespace {

	int flip(int x)
	{
		return x ^ 1;
	}

	int sign(int x)
	{
		return flip((x >> 31) & 1);
	}

	int GetMax(int a, int b)
	{
		int sa = sign(a);
		int sb = sign(b);
		int sc = sign(a - b);

		int diffSign = sa ^ sb;
		int sameSign = flip(diffSign);

		int returnA = diffSign * sa + sameSign * sc;
		int returnB = flip(returnA);

		return a * returnA + b * returnB;
	}
}

