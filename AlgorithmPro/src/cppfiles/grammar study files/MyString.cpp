#include<iostream>
#include "pch.h"
class myString
{

private:
	char* m_Buffer;
	unsigned int m_Size;

public:

	myString(const char* string)
	{
		m_Size = strlen(string);   
		m_Buffer = (char*)malloc(sizeof(char) * m_Size+1);
		memcpy(m_Buffer, string, m_Size+1 );
		m_Buffer[m_Size] = 0;
	}

	//拷贝构造函数，仅当想复制时具有相同的类型时被调用
	//深拷贝

	myString(const myString& other) :m_Size(other.m_Size)
	{
		m_Buffer = (char*)malloc(sizeof(char) * m_Size + 1);
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
		m_Buffer[m_Size] = 0;
	}
		


	~myString()
	{
		free(m_Buffer);
	}

	char& operator[](unsigned int index)
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const myString& string);
	
};

std::ostream& operator<<(std::ostream& stream, const myString& string)
{
	stream << string.m_Buffer;
	return stream;
}



