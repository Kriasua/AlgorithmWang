// ���ֺ͸���
// �� 0 �� n - 1 ��ţ�����ÿ���˶��в�ͬ��Ŀ��Ǯ���Լ���ͬ�̶ȵİ���ֵ
// ����һ������richer������richer[i] = [ai, bi] ��ʾ 
// person ai �� person bi ����Ǯ
// ����һ���������� quiet ������ quiet[i] �� person i �İ���ֵ
// richer �������������� �߼���Ǣ
// Ҳ����˵���� person x �� person y ����Ǯ��ͬʱ���������
// person y �� person x ����Ǯ�����
// ���ڣ�����һ���������� answer ��Ϊ�𰸣����� answer[x] = y ��ǰ����,
// ������ӵ�е�Ǯ�϶������� person x �����У�
// person y ��������ˣ�Ҳ���ǰ���ֵ quiet[y] ��С���ˣ���
// �������� : https://leetcode.cn/problems/loud-and-rich/

#include<vector>

namespace
{
	using std::vector;
	class Solution {
	public:
		vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
			int n = quiet.size();

			vector<vector<int>> graph;
			vector<int> queue;
			vector<int> inDegree;
			vector<int> ans;

			graph.resize(n);
			queue.resize(n);
			inDegree.resize(n);
			ans.resize(n);

			int l = 0;
			int r = 0;		

			//��ͼ����ȱ�
			for (auto& relation : richer)
			{
				inDegree[relation[1]]++;
				graph[relation[0]].push_back(relation[1]);
			}

			//��ʼ��������
			for (int i = 0; i < n; i++)
			{
				ans[i] = i;
				if (inDegree[i] == 0)
				{
					queue[r++] = i;
				}
			}

			int cur;

			while (l < r)
			{
				cur = queue[l++];
				for (int num : graph[cur])
				{
					if (--inDegree[num] == 0)
					{
						queue[r++] = num;
					}

					if (quiet[ans[cur]] < quiet[ans[num]])
					{
						ans[num] = ans[cur];
					}
				}
			}

			return ans;
		}
	};
}