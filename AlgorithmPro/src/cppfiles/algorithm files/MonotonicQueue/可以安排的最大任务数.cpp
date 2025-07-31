// ����԰��ŵ����������Ŀ
// ���� n ������� m �����ˡ�ÿ��������Ҫһ��������ֵ�������
// ��Ҫ������ֵ�������±�� 0 ��ʼ���������� tasks �У�
// ��i��������Ҫ tasks[i] �������������
// ÿ�����˵�����ֵ�������±�� 0 ��ʼ����������workers�У�
// ��j�����˵�����ֵΪ workers[j]
// ÿ������ֻ�����һ������������ֵ��Ҫ���ڵ��ڸ����������Ҫ��ֵ����workers[j]>=tasks[i]
// �������⣬�㻹�� pills ������ҩ�裬���Ը� һ�����˵�����ֵ ���� strength
// ����Ծ�������Щ����ʹ��ҩ�裬��ÿ������ ��� ֻ��ʹ�� һƬ ҩ��
// �����±�� 0 ��ʼ����������tasks �� workers �Լ��������� pills �� strength
// ���㷵�� ��� �ж��ٸ�������Ա���ɡ�
// �������� : https://leetcode.cn/problems/maximum-number-of-tasks-you-can-assign/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:
		std::vector<int> ts;
		std::vector<int> ws;
		std::vector<int> deque;
		int left = 0;
		int right = 0;

		bool f(int tasksnumber, int pills, int strength)
		{
			left = 0;
			right = 0;
			int j = 0;
			int pillCount = 0;
			for (int i = ws.size() - tasksnumber; i < ws.size(); i++)
			{
				while (j <= tasksnumber - 1 && ts[j] <= ws[i])
				{
					deque[right++] = j++;
				}

				if (left < right && ws[i] >= ts[deque[left]])
				{
					left++;
				}
				else
				{
					pillCount++;
					while (j <= tasksnumber - 1 && ts[j] <= ws[i]+strength)
					{
						deque[right++] = j++;
					}

					if (left < right)
					{
						right--;
					}
					else
					{
						return false;
					}
				}

			}

			return pillCount <= pills;
		}

		int maxTaskAssign(std::vector<int>& tasks, std::vector<int>& workers, int pills, int strength) {
			std::sort(tasks.begin(), tasks.end());
			std::sort(workers.begin(), workers.end());
			ts = tasks;
			ws = workers;
			deque.resize(tasks.size());
			int ans = 0;
			for (int l = 0, r = std::min(tasks.size(), workers.size()), mid; l <= r;)
			{
				mid = l + ((r - l) >> 1);
				if (f(mid,pills,strength))
				{
					ans = mid;
					l = mid + 1;
				}
				else
				{
					r = mid - 1;
				}
			}

			return ans;

		}
	};
}