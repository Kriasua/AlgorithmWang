#include"Bitset.h"
#include<vector>
#include "pch.h"

class bitSet
{

private:
	int n;
	std::vector<int> set;

public:

	bitSet(const int x)
	{
		n = x;
		set.resize((n + 31) / 32, 0);
	}
	
	void add(int x)
	{
		*(set.begin() + (x / 32)) |= (1 << (x % 32));
	}

	void remove(int x)
	{
		*(set.begin() + (x / 32)) &= ~(1 << (x % 32));
	}

	bool contain(int x)
	{
		return (*(set.begin() + (x / 32)) & 1 << (x % 32)) != 0;
	}

	void reverse(int x)
	{
		*(set.begin() + (x / 32)) ^= (1 << (x % 32));
	}

};