#include<iostream>
#include "pch.h"
namespace {
	int add(int a, int b)
	{
		int ans = 0;
		while (b != 0)
		{
			ans = a ^ b;
			b = (a & b) << 1;
			a = ans;
		}
		return ans;
	}



	int minus(int a, int b)
	{
		return add(a, add(~b, 1));
	}

	int logicalRightShift(int x, int shift) {
		return (x >> shift) & ((1 << (32 - shift)) - 1);
	}

	int multiply(int a, int b)
	{
		int ans = 0;
		int absa = a > 0 ? a : add(~a, 1);
		int absb = b > 0 ? b : add(~b, 1);

		while (absb > 0) {
			if (absb & 1) {
				ans = add(ans, absa);
			}
			absa <<= 1;
			absb >>= 1; // Œﬁ∑˚∫≈”““∆£¨∏ﬂŒª≤π0
		}

		if ((a ^ b) < 0)
		{
			return add(~ans, 1);
		}

		return ans;
	}

	void printBinary(unsigned int x)
	{
		for (int i = 31; i >= 0; i--)
		{
			if ((x & (1 << i)) == 0)
			{
				std::cout << 0;
			}
			else
			{
				std::cout << 1;
			}
		}
		std::cout << std::endl;
	}
}
