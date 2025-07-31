/*描述
给定一个无序数组arr, 其中元素可正、可负、可0。给定一个整数k，求arr所有子数组中累加和为k的最长子数组长度
输入描述：
第一行两个整数N, k。N表示数组长度，k的定义已在题目描述中给出
第二行N个整数表示数组内的数*/
#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
namespace
{
	using std::vector;
	vector<int> arr;
	int N;
	int K;
	std::unordered_map<int, int> map;

	int compute()
	{
		map.clear();
		map.emplace(0, -1);
		for (int i = 0,sum = 0; i < N; i++)
		{
			sum += arr[i];
			if (map.find(sum) == map.end())
			{
				map.emplace(sum, i);
			}
		}

		int ans = 0;
		for (int i = 0, sum = 0; i < N; i++)
		{
			sum += arr[i];
			if (map.find(sum - K) != map.end())
			{
				ans = std::max(ans, i - map[sum - K]);
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
			std::cin >> K;
			for (int i = 0; i < N; i++)
			{
				std::cin >> arr[i];
			}
			std::cout << compute();
			std::cout << "\n";
		}
	}
		


}