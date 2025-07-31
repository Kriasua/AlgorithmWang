#include<string>
#include<iostream>
#include<chrono>
#include "pch.h"
namespace
{

	class Timer
	{
	public:
		std::chrono::time_point<std::chrono::steady_clock> start;
		std::chrono::time_point<std::chrono::steady_clock> end;
		std::chrono::duration<double> duration;
		Timer()
		{
			start = std::chrono::high_resolution_clock::now();
		}

		~Timer()
		{
			end = std::chrono::high_resolution_clock::now();
			duration = end - start;
			float ms = duration.count() * 1000.0f;
			std::cout << ms << "ms" << std::endl;
		}

	};
	void f(int i, const char* from, const char* to, const char* other)
	{
		if (i == 1)
		{
			//std::cout << "移动圆盘" << i << "，从  " << from << "  到  " << to << "\n";
			return;
		}

		f(i - 1, from, other, to);
		//std::cout << "移动圆盘" << i << "，从  " << from << "  到  " << to << "\n";
		f(i - 1, other, to, from);
	}

	void Hanoi(int i)
	{
		Timer timer;

		f(i, "左", "中", "右");

	}
}

