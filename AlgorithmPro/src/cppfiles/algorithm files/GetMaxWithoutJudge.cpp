#include<iostream>
#include "pch.h"
// 不用任何判断语句和比较操作，返回两个数的最大值
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

