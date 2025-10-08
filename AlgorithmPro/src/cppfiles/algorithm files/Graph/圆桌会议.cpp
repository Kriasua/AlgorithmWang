// �μӻ�������Ա����
// һ����˾׼����֯һ�����飬������������ n λԱ��
// ��˾׼����һ�� Բ�� �����ӣ��������� ������Ŀ ��Ա��
// Ա�����Ϊ 0 �� n - 1 ��ÿλԱ������һλ ϲ�� ��Ա��
// ÿλԱ�� ���ҽ��� ����������ϲ��Ա�����Աߣ����Ż�μӻ���
// ÿλԱ��ϲ����Ա�� ���� �����Լ�������һ���±�� 0 ��ʼ���������� favorite
// ���� favorite[i] ��ʾ�� i λԱ��ϲ����Ա�������㷵�زμӻ���� ���Ա����Ŀ
// �������� : https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/

#include<vector>
namespace
{
	using std::vector;
	class Solution {
	public:
		int maximumInvitations(vector<int>& favorite) {
			int n = favorite.size();
			vector<int> queue;
			vector<int> inDegree;
			vector<int> deep;
			queue.resize(n);
			inDegree.resize(n);
			deep.resize(n);

			int l = 0;
			int r = 0;

			for (int num : favorite)
			{
				inDegree[num]++;
			}

			for (int i = 0; i < n; i++)
			{
				if (inDegree[i] == 0)
				{
					queue[r++] = i;
				}
			}

			int cur,next;
			while (l < r)
			{
				cur = queue[l++];
				next = favorite[cur];
				if (--inDegree[next] == 0)
				{
					queue[r++] = next;
				}

				deep[next] = std::max(deep[next], deep[cur] + 1);
			}

			int sumOfSmall = 0;
			int Big = 0;
			int MaxSize = 0;
			int current;
			for (int i = 0; i < n; i++)
			{
				MaxSize = 1;

				if (inDegree[i] > 0)
				{
					current = favorite[i];
					inDegree[i] = 0;
					while (current != i)
					{
						inDegree[current] = 0;
						current = favorite[current];
						MaxSize++;
					}

					if (MaxSize == 2)
					{
						sumOfSmall += deep[i] + deep[favorite[i]] + 2;
					}
					else
					{
						Big = std::max(Big, MaxSize);
					}
				}


			}
			return std::max(sumOfSmall, Big);
		}
	};
}