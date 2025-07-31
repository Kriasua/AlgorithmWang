// һȺ����ˮ����ÿ��λ�õ�ˮλ�߶�
// ���������Ƚϸ��ӣ�����������
// �������� : https://www.luogu.com.cn/problem/P5026

/*�����ʽ:
��һ��Ϊ�������� n,m����ʾ"����"����Ŀ������Ŀ�ȡ�
������ n �У�һ���������� v,x����ʾ�� i+1 �����ѵ��������ˮ�㡣

�����ʽ:
һ�� m ���������� i ��������ʾ i ��λ��ˮ�*/
#include<vector>
#include<array>
#include<iostream>
namespace
{
	int n, m;
	int v, x;
	constexpr int MAX = 1000003;
	constexpr int OFFSET = 30001;
	std::vector<int> arr;

	void set(int l , int r, int s, int e , int d)
	{
		arr[l + OFFSET] += s;
		arr[l + 1 + OFFSET] += d - s;
		arr[r + 1 + OFFSET] -= d + e;
		arr[r + 2 + OFFSET] += e;
	}

	void build()
	{
		for (int i = 1; i <= m + OFFSET; i++)
		{
			arr[i] += arr[i - 1];
		}

		for (int i = 1; i <= m + OFFSET; i++)
		{
			arr[i] += arr[i - 1];
		}
	}

	void fall(int v, int i)
	{
		set(i - 3 * v + 1, i - 2 * v, 1, v, 1);
		set(i - 2 * v + 1,i,v-1,-v,-1);
		set(i + 1, i + 2 * v, -v + 1, v, 1);
		set(i + 2 * v + 1, i + 3 * v - 1, v - 1, 1, -1);
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		arr.resize(MAX + 2 * OFFSET);
		while (std::cin >> n >> m)
		{
			std::fill(arr.begin(), arr.begin() + m + 2 * OFFSET, 0);
			for (int i = 0; i < n; i++)
			{
				std::cin >> v >> x;
				fall(v, x);
			}
			build();
			for (int i = 1 + OFFSET; i <= m + OFFSET; i++)
			{
				std::cout << arr[i] << " ";
			}
			std::cout << "\n";
		}
	}
}