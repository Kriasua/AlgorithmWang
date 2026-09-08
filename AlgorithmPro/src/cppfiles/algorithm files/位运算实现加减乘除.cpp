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
			absb >>= 1; // 无符号右移，高位补0
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



class 位运算实现加减乘除
{
	using LL = long long int;
public:
	int add(int a, int b)
	{
		int ans = a ^ b;
		int carry = (a & b) << 1;
		while (carry != 0)
		{
			int tmpA = ans;
			int tmpB = carry;
			ans = tmpA ^ tmpB;
			carry = (tmpA & tmpB) << 1;
		}

		return ans;
	}

	int addRecur(int a, int b)
	{
		int ans = a ^ b;
		int carry = (a & b) << 1;
		if (carry == 0)
		{
			return ans;
		}
		
		return addRecur(ans, carry);
	}

	int neg(int a)
	{
		return addRecur(~a, 1);
	}

	int minus(int a, int b)
	{
		return addRecur(a, neg(b));
	}

	int multiply(int a, int b)
	{
		int A = a;
		int B = b;
		int ans = 0;
		for (int i = 0; i < 32; i++)
		{
			if (((1 << i) & B) != 0)
			{
				ans = add(ans,(A << i));
			}
		}

		return ans; 
	}
};
