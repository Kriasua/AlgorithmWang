// �����λʱ��
// ����һ������arr����Ϊn����ʾn������Ա��ÿ����һ���˵�ʱ��
// ����һ������m����ʾ��m���˵�λ��������Ǹ������ˣ���������Ҫ�ȶ�ã�
// ����mԶԶ����n������n <= 10^3, m <= 10^9������ô�������Ž⣿
// �ȸ�����ԣ������������2����
// �Ҳ����������ӣ������ö�������֤
#include<queue>
#include<vector>
#include <random>
#include<iostream>
namespace
{


	int waitingTime(std::vector<int>& waitors, int m)
	{
		std::pair<int, int> Top;
		auto cmp = [](const std::pair<int, int>& a, const std::pair<int, int>& b)
			{
				return a.first > b.first;
			};

		std::priority_queue < std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> minHeap(cmp);

		for (int num : waitors)
		{
			minHeap.push({ 0,num });
		}

		for (int i = 0; i < m; i++)
		{
			Top = minHeap.top();
			minHeap.pop();
			Top.first += Top.second;
			minHeap.push(Top);
		}

		return minHeap.top().first;
	}

	int f(std::vector<int> waitors, int time)
	{
		int people = 0;
		for (int num : waitors)
		{
			people += (time / num)+1;
		}
		return people;
	}

	int waitingTime2(std::vector<int>& waitors, int k)
	{
		int l = 0;
		int r = INT_MAX;
		int middle = 0;
		int ans = 0;
		for (int num : waitors)
		{
			r = std::min(r, num);
		}
		r *= k;

		while (l <= r)
		{
			middle = l + ((r - l) >> 1);
			if (f(waitors, middle) >= k + 1)
			{
				ans = middle;
				r = middle - 1;
			}
			else
			{
				l = middle + 1;
			}
		}
		return ans;
	}

	std::vector<int> generateRandomVector(int Length, int Time) 
	{

		static std::random_device rd;

		static std::mt19937 gen(rd());

		std::uniform_int_distribution<> length_dist(0, Length);
		int randomLength = length_dist(gen);

		std::uniform_int_distribution<> time_dist(0, Time);
		std::vector<int> result;
		result.reserve(randomLength);
		for (int i = 0; i < randomLength; ++i) {
			result.push_back(time_dist(gen));
		}
		return result;
	}

	int generateRandomInt(int MAX) {

		static std::random_device rd;
		static std::mt19937 gen(rd());
		std::uniform_int_distribution<> distrib(0, MAX);
		return distrib(gen);
	}
}

