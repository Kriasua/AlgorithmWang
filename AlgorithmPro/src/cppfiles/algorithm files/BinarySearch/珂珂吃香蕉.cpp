// �����㽶������
// ����ϲ�����㽶�������� n ���㽶���� i ������ piles[i] ���㽶
// �����Ѿ��뿪�ˣ����� h Сʱ�������
// ������Ծ��������㽶���ٶ� k ����λ����/Сʱ)
// ÿ��Сʱ��������ѡ��һ���㽶�����гԵ� k ��
// �������㽶���� k ���������Ե���ѵ������㽶��Ȼ����һСʱ�ڲ����ٳԸ�����㽶
// ����ϲ�������ԣ�����Ȼ���ھ�������ǰ�Ե����е��㽶��
// ������������ h Сʱ�ڳԵ������㽶����С�ٶ� k��k Ϊ������
// �������� : https://leetcode.cn/problems/koko-eating-bananas/

#include<vector>
namespace
{
	class Solution {
	public:
		int minEatingSpeed(std::vector<int>& piles, int h) {
			int l = 1;
			int r = 0;
			int m = 0;
			int ans = 0;
			for (int num : piles)
			{
				r = std::max(r, num);
			}

			while (l <= r)
			{
				m = l + ((r - l) >> 1);
				if (f(piles, m) <= h)
				{
					ans = m;
					r = m - 1;
				}
				else
				{
					l = m + 1;
				}
			}

			return ans;


		}

		long long int f(std::vector<int>& piles, int speed)
		{
			long long int ans = 0;
			for (int num : piles)
			{
				ans += (num + speed - 1) / speed;
			}

			return ans;
		}
	};
}

