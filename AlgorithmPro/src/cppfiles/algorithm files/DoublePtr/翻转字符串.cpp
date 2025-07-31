/*
* 把一个字符串每个单词都翻转
* 
* 例子： "Hello World"  ->  "World Hello"
*/

#include<string>
#include<iostream>
namespace
{
	void swap(std::string& str, int a, int b)
	{
		char temp = str[a];
		str[a] = str[b];
		str[b] = temp;
	}

	void reverseWord(std::string& str, int a, int b)
	{
		while (a < b)
		{
			swap(str, a++, b--);

		}
	}

	void reverseString(std::string& str)
	{
		if (str.size() <= 1)
		{
			return;
		}

		int l = 0;
		int r = str.size() - 1;

		reverseWord(str, l, r);

		l = 0;
		r = 0;
		int preR;
		while (l < str.size() - 1)
		{
			while (r < str.size() && str[r] != ' ')
			{
				r++;
			}
			preR = r - 1;
			reverseWord(str, l, preR);
			r++;
			l = r;
		}
	}
}
