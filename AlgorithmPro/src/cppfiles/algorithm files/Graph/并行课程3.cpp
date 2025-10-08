// ���пγ� III
// ����һ������ n ����ʾ�� n �ڿΣ��γ̱�Ŵ� 1 �� n
// ͬʱ����һ����ά�������� relations ��
// ���� relations[j] = [prevCoursej, nextCoursej]
// ��ʾ�γ� prevCoursej �����ڿγ� nextCoursej ֮ǰ ��ɣ����޿εĹ�ϵ��
// ͬʱ����һ���±�� 0 ��ʼ���������� time
// ���� time[i] ��ʾ��ɵ� (i+1) �ſγ���Ҫ���ѵ� �·� ����
// ����������¹������������пγ�����Ҫ�� ���� �·�����
// ���һ�ſε��������޿ζ��Ѿ���ɣ�������� ���� ʱ�俪ʼ���ſγ̡�
// ����� ͬʱ �� �����ſγ� �����㷵��������пγ�����Ҫ�� ���� �·�����
// ע�⣺�������ݱ�֤һ������������пγ̣�Ҳ�������޿εĹ�ϵ����һ�������޻�ͼ��
// �������� : https://leetcode.cn/problems/parallel-courses-iii/

#include<vector>

namespace
{
	using std::vector;
	class Solution {
	public:
		int minimumTime(int n, std::vector<std::vector<int>>& relations, std::vector<int>& time) {

			vector<vector<int>> graph;
			vector<int> queue;
			vector<int> inDegree;
			vector<int> message;
			int ans = 0;

			graph.resize(n+1);
			queue.resize(n+1);
			inDegree.resize(n+1);
			message.resize(n + 1);

			int l = 0;
			int r = 0;

			//��ͼ
			for (auto& relation : relations)
			{
				inDegree[relation[1]]++;
				graph[relation[0]].push_back(relation[1]);
			}

			for (int i = 1; i <=n; i++)
			{
				if (inDegree[i] == 0)
				{
					queue[r++] = i;
				}

				message[i] = time[i - 1];
			}


			int cur;
			while (l < r)
			{
				cur = queue[l++];
				if (graph[cur].empty())
				{
					ans = std::max(ans, message[cur]);
				}
				else
				{
					for (int num : graph[cur])
					{
						if (--inDegree[num] == 0)
						{
							queue[r++] = num;
						}

						if ((message[cur] + time[num - 1]) > message[num])
						{
							message[num] = message[cur] + time[num - 1];
						}
					}
				}
			}

			return ans;

		}
	};
}