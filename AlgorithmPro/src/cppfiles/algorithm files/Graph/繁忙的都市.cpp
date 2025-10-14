// ��æ�Ķ���
// һ���ǳ���æ�Ĵ��У������еĵ�·ʮ�ֵ�ӵ���������г����������еĵ�·���и���
// ���еĵ�·�������ֲ��ģ���������n������·�ڣ���Щ����·��֮���е�·����
// ��������·��֮�������һ����·�����ӣ���Щ��·��˫���
// �Ұ����еĽ���·��ֱ�ӻ��ӵ�����������
// ÿ����·����һ����ֵ����ֵԽС��ʾ�����·Խ��æ��Խ��Ҫ���и���
// �������������ʽ����ޣ��г�ϣ�����и���ĵ�·Խ��Խ�ã���������������Ҫ��
// 1. �������Щ��·�ܹ������еĽ���·��ֱ�ӻ��ӵ���ͨ����
// 2. ������Ҫ��1������£�����ĵ�·������
// 3. ������Ҫ��1��2������£��������Щ��·�з�ֵ���ĵ�·��ֵ����С
// ��Ϊ�й滮�ֵ��㣬Ӧ��������ѵľ��ߣ�ѡ����Щ��·Ӧ�����޽�
// ����ѡ���˼�����· �Լ� ��ֵ����������·�ķ�ֵ�Ƕ���
// �������� : https://www.luogu.com.cn/problem/P2330

#include<iostream>
#include<vector>
#include<array>
#include<algorithm>
namespace
{
	int n, m;
	constexpr int MAXn = 301;
	constexpr int MAXm = 8001;
	std::vector<int> fathers;

	void build()
	{
		for (int i = 1; i <= n; i++)
		{
			fathers[i] = i;
		}
	}

	int find(int num)
	{
		if (num == fathers[num])
		{
			return num;
		}

		int result = find(fathers[num]);
		fathers[num] = result;
		return result;
	}

	bool Union(int a, int b)
	{
		int fa = find(a);
		int fb = find(b);

		if (fa != fb)
		{
			fathers[fa] = fb;
			return true;
		}
		else
		{
			return false;
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::vector<std::array<int,3>> edgeLists;
		edgeLists.resize(MAXm);
		fathers.resize(MAXn);

		while (std::cin >> n >> m)
		{
			build();
			for (int i = 0; i < m; i++)
			{
				std::cin >> edgeLists[i][0] >> edgeLists[i][1] >> edgeLists[i][2];
			}

			std::sort(edgeLists.begin(), edgeLists.begin() + m, [](std::array<int, 3>& a, std::array<int, 3>& b)
				{
					return a[2] < b[2];
				});

			int s = 0;
			int Max = 0;

			for (auto& col : edgeLists)
			{
				if (Union(col[0], col[1]))
				{
					s++;
					Max = std::max(Max, col[2]);
				}

				if (s == n - 1)
				{
					break;
				}
			}

			std::cout << n - 1 << " " << Max << "\n";
		}

	}
}