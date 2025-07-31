// ��������Ծ����
// ������������һ�����ϵĻ���DOS����Ϸ
// ��Ϸ����N+1����������0��N��ţ�����������
// ���Ϊ0�Ľ����߶�Ϊ0����λ�����Ϊi�Ľ����ĸ߶�ΪH(i)����λ
// ����������ڱ��Ϊ0�Ľ�����
// ÿһ������������һ�����ұߣ�����������������ڵ�k���������������ڵ�����ֵ��E
// ��һ�����������ڸ�k+1����
// ������õ�����ʧȥ��������H(k+1)��E֮�������
// ��� H(k+1) > E ��ô�����˾�ʧȥH(k+1)-E������ֵ�����������õ�E-H(k+1)������ֵ
// ��ϷĿ���ǵ���ڸ�N����������������У�����ֵ����Ϊ��������λ
// ���ڵ������ǻ������Զ�������ֵ��ʼ��Ϸ���ſ��Ա�֤�ɹ������Ϸ
// �������� : https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71

#include <iostream>
#include <array>
namespace
{
	constexpr int MAX = 100001;
	std::array<int, MAX> nums;
	int N;

	bool f(int energy, int maxheight)
	{

		for (int i = 1; i <= N; i++)
		{
			energy += (energy - nums[i]);
			if (energy < 0)
			{
				return false;
			}
			if (energy >= maxheight)
			{
				return true;
			}
		}

		return true;
	}

	int findLowestEnergy(int l, int r, int MaxHeight)
	{
		int Ans = 0;

		int m = 0;
		while (l <= r)
		{
			m = l + ((r - l) >> 1);
			if (f(m, MaxHeight))
			{
				Ans = m;
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}

		return Ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		nums[0] = 0;
		while (std::cin >> N)
		{
			int l = 0;
			int r = 0;
			for (int i = 1; i <= N; i++)
			{
				std::cin >> nums[i];
				r = std::max(r, nums[i]);
			}

			std::cout << findLowestEnergy(l, r, r) << "\n";
		}
	}
}
