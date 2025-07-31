/*给定一个无序数组arr，其中元素可正、可负、可0。求arr所有子数组中正数与负数个数相等的最长子数组的长度。
输入描述：
第一行一个整数N，表示数组长度
接下来一行有N个数表示数组中的数*/
#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
namespace
{
	using std::vector;
	vector<int> arr;
	int N;
	std::unordered_map<int, int> map;

	int compute()
	{
		map.clear();
		map.emplace(0, -1);
		int ans = 0;
		for (int i = 0, sum = 0; i < N; i++)
		{
			if (arr[i] > 0)
			{
				arr[i] = 1;
			}
			else if (arr[i] < 0)
			{
				arr[i] = -1;
			}
			else
			{
				arr[i] = 0;
			}
		}

		for (int i = 0, sum = 0; i < N; i++)
		{

			sum += arr[i];
			if (map.find(sum) != map.end())
			{
				ans = std::max(ans, i - map[sum]);
			}
			if (map.find(sum) == map.end())
			{
				map.emplace(sum, i);
			}
		}


		return ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		arr.resize(100001);
		while (std::cin >> N)
		{
			for (int i = 0; i < N; i++)
			{
				std::cin >> arr[i];
			}
			std::cout << compute();
			std::cout << "\n";
		}
	}
}