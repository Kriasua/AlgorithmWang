/*����
����һ����������arr, ����Ԫ�ؿ������ɸ�����0������һ������k����arr�������������ۼӺ�Ϊk��������鳤��
����������
��һ����������N, k��N��ʾ���鳤�ȣ�k�Ķ���������Ŀ�����и���
�ڶ���N��������ʾ�����ڵ���*/
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