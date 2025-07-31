// 接取落水的最小花盆
// 老板需要你帮忙浇花。给出 N 滴水的坐标，y 表示水滴的高度，x 表示它下落到 x 轴的位置
// 每滴水以每秒1个单位长度的速度下落。你需要把花盆放在 x 轴上的某个位置
// 使得从被花盆接着的第 1 滴水开始，到被花盆接着的最后 1 滴水结束，之间的时间差至少为 D
// 我们认为，只要水滴落到 x 轴上，与花盆的边沿对齐，就认为被接住
// 给出 N 滴水的坐标和 D 的大小，请算出最小的花盆的宽度 W
// 测试链接 : https://www.luogu.com.cn/problem/P2698

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



