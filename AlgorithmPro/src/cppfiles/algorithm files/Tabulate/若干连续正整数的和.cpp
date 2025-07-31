#include<iostream>

namespace
{
	bool f(int rest,int last)
	{
		if (rest == 0)
		{
			return true;
		}

		if (rest < 0)
		{
			return false;
		}

		return f(rest-last,last+1);
	}

	bool IsSumOfConsecutiveNumbers(int num)
	{
		for (int i = 1; i < num; i++)
		{
			if (f(num, i) == true)
			{
				return true;
			}
		}

		return false;
		
	}

	bool IsSumOfConsecutiveNumbers2(int num)
	{
		/*if (num >= 0 && num <= 2)
		{
			return false;
		}*/

		if ((num & (num - 1)) == 0)
		{
			return false;
		}

		return true;
	}
}

