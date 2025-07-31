// ��ȡ��ˮ����С����
// �ϰ���Ҫ���æ���������� N ��ˮ�����꣬y ��ʾˮ�εĸ߶ȣ�x ��ʾ�����䵽 x ���λ��
// ÿ��ˮ��ÿ��1����λ���ȵ��ٶ����䡣����Ҫ�ѻ������ x ���ϵ�ĳ��λ��
// ʹ�ôӱ�������ŵĵ� 1 ��ˮ��ʼ������������ŵ���� 1 ��ˮ������֮���ʱ�������Ϊ D
// ������Ϊ��ֻҪˮ���䵽 x ���ϣ��뻨��ı��ض��룬����Ϊ����ס
// ���� N ��ˮ������� D �Ĵ�С���������С�Ļ���Ŀ�� W
// �������� : https://www.luogu.com.cn/problem/P2698

#include<vector>
#include<array>
#include<iostream>
#include<algorithm>
namespace
{
	constexpr int MAX = 100001;
	std::vector<std::array<int,2>> arr;
	std::vector<int> minDeque;
	std::vector<int> maxDeque;
	int minH = 0;
	int minT = 0;
	int maxH = 0;
	int maxT = 0;
	int N;
	int D;


	void pop(int l)
	{
		if (maxDeque[maxH] == l)
		{
			maxH++;
		}

		if (minDeque[minH] == l)
		{
			minH++;
		}

	}

	void push(int R)
	{
		while (maxT > maxH && arr[R][1] >= arr[maxDeque[maxT - 1]][1])
		{
			maxT--;
		}
		maxDeque[maxT++] = R;

		while (minT > minH && arr[R][1] <= arr[minDeque[minT - 1]][1])
		{
			minT--;
		}
		minDeque[minT++] = R;
	}

	bool ok()
	{
		return arr[maxDeque[maxH]][1] - arr[minDeque[minH]][1] >= D;
	}

	int compute()
	{
		int ans = INT_MAX;
		std::sort(arr.begin(), arr.begin()+N, [](std::array<int, 2>& a, std::array<int, 2>& b) {
			return a[0] < b[0];
			});

		int L = 0;
		int R = 0;

		for (; R < N; R++)
		{
			push(R);

			while (L < R && ok())
			{
				ans = std::min(ans, arr[R][0] - arr[L][0]);
				pop(L);
				L++;
			}

		}


		return ans == INT_MAX ? -1 : ans;
	}

	void clear()
	{
		 minH = 0;
		minT = 0;
		maxH = 0;
		 maxT = 0;
	}


	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		arr.resize(MAX);
		maxDeque.resize(MAX);
		minDeque.resize(MAX);
		while (std::cin >> N >> D)
		{
			clear();
			for (int i = 0; i < N; i++)
			{
				std::cin >> arr[i][0];
				std::cin >> arr[i][1];
			}
			std::cout << compute() << "\n";
		}
	}
}



