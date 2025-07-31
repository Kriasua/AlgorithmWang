// ͬʱ����N̨���Ե��ʱ��
// ���� n ̨���ԡ��������� n ��һ���±�� 0 ��ʼ���������� batteries
// ���е� i ����ؿ�����һ̨���� ���� batteries[i] ����
// ����ʹ����Щ����� ȫ�� n ̨���� ͬʱ ���С�
// һ��ʼ������Ը�ÿ̨�������� ����һ�����
// Ȼ������������ʱ�̣��㶼���Խ�һ̨���������ĵ�ضϿ����ӣ���������һ����أ�����Խ���������� �����
// �����ӵĵ�ؿ�����һ��ȫ�µĵ�أ�Ҳ�����Ǳ�ĵ����ù��ĵ��
// �Ͽ����Ӻ������µĵ�ز��Ứ���κ�ʱ�䡣
// ע�⣬�㲻�ܸ���س�硣
// ���㷵��������� n ̨����ͬʱ���е� � ��������
// �������� : https://leetcode.cn/problems/maximum-running-time-of-n-computers/
#include<vector>
namespace
{
	class Solution {
		using LL = long long;
	public:
		bool f(std::vector<int>& batteries, LL limit, LL sum, int n)
		{
			for (int num : batteries)
			{
				if (num > limit)
				{
					sum -= num;
					n--;
				}
			}

			if (sum >= ((LL)n * limit))
			{
				return true;  
			}
			else
			{
				return false;
			}

		}

		LL maxRunTime(int n, std::vector<int>& batteries) {
			LL l = 0;
			LL r = 0;
			LL m = 0;
			LL ans = 0;
			for (int num : batteries)
			{
				r += num;
			}

			LL sum = r;

			while (l <= r)
			{
				m = l + ((r - l) >> 1);
				if (f(batteries, m,sum,n))
				{
					ans = m;
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}

			return ans;
		}
	};
}