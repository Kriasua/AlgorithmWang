// ţţ�ı������� & ������������
// ţţ׼���μ�ѧУ��֯�Ĵ���, ����ǰţţ׼����������װ��һЩ��ʳ, ţţ�ı�������Ϊw��
// ţţ����һ����n����ʳ, ��i����ʳ���Ϊv[i]��
// ţţ��֪������������������������������,��һ���ж�������ʳ�ŷ�(�����Ϊ0Ҳ��һ�ַŷ�)��
// ����������
// �����������
// ��һ��Ϊ����������n��w(1 <= n <= 30, 1 <= w <= 2 * 10^9),��ʾ��ʳ�������ͱ���������
// �ڶ���n��������v[i](0 <= v[i] <= 10^9),��ʾÿ����ʳ�����
// ���������
// ���һ��������, ��ʾţţһ���ж�������ʳ�ŷ���
// �������� : https://www.luogu.com.cn/problem/P4799


#include<vector>
#include<iostream>
#include<algorithm>
namespace
{
	using LL = long long int;
	constexpr int MAXN = 40;
	constexpr int MAXM = 1 << 20;
	std::vector<LL> price;
	std::vector<LL> lsum;
	std::vector<LL> rsum;
	int middle ,N;
	int lcnt;
	int rcnt;
	LL M;

	void dfsl(int i, LL sum, std::vector<LL>& arr)
	{
		if (i == middle)
		{
			if (sum <= M)
			{
				arr[lcnt++] = sum;
			}
			return;
		}


		dfsl(i + 1, sum, arr);
		if (sum + price[i] > M)
		{
			return;
		}
		else
		{
			dfsl(i + 1, sum + price[i], arr);
		}
	}


	void dfsr(int i, LL sum, std::vector<LL>& arr)
	{
		if (i == N)
		{
			if (sum <= M)
			{
				arr[rcnt++] = sum;
			}
			return;
		}

		dfsr(i + 1, sum, arr);
		if (sum + price[i] > M)
		{
			return;
		}
		else
		{
			dfsr(i + 1, sum + price[i], arr);
		}
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		price.resize(MAXN);
		lsum.resize(MAXM);
		rsum.resize(MAXM);
		while (std::cin >> N >> M)
		{
			middle = N / 2;
			for (int i = 0; i < N; i++)
			{
				std::cin >> price[i];
			}

			lcnt = 0;
			rcnt = 0;
			dfsl(0, 0, lsum);
			dfsr(middle, 0, rsum);
			std::sort(lsum.begin(), lsum.begin() + lcnt);
			std::sort(rsum.begin(), rsum.begin() + rcnt);

			int l = 0;
			int r = rcnt-1;
			LL ans = 0;
			for (; l < lcnt; l++)
			{
				while (r>=0 && lsum[l] + rsum[r] > M)
				{
					r--;
				}

				ans += r + 1;
				
			}

			std::cout << ans << "\n";
		}
	}
}




