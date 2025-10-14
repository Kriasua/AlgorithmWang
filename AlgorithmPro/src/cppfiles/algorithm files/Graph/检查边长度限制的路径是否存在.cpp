// ���߳������Ƶ�·���Ƿ����
// ����һ�� n ������ɵ�����ͼ�߼� edgeList
// ���� edgeList[i] = [ui, vi, disi] ��ʾ�� ui �͵� vi ֮����һ������Ϊ disi �ı�
// ��ע�⣬������֮������� ����һ���� ��
// ����һ����ѯ����queries ������ queries[j] = [pj, qj, limitj]
// ��������Ƕ���ÿ����ѯ queries[j] ���ж��Ƿ���ڴ� pj �� qj ��·��
// ������·���ϵ�ÿһ���߶� �ϸ�С�� limitj ��
// ���㷵��һ�� �������� answer ������ answer.length == queries.length
// �� queries[j] �Ĳ�ѯ���Ϊ true ʱ�� answer �� j ��ֵΪ true ������Ϊ false
// �������� : https://leetcode.cn/problems/checking-existence-of-edge-length-limited-paths/

#include<vector>
#include<algorithm>
namespace
{
    using std::vector;
    class Solution {
    public:
        std::vector<int> fathers;
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

		void Union(int a, int b)
		{
			int fa = find(a);
			int fb = find(b);

			if (fa != fb)
			{
				fathers[fa] = fb;
			}
			
		}

		bool isSameSet(int a, int b)
		{
			return find(a) == find(b);
		}

        vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
			int m = queries.size();
            fathers.resize(n);
            for (int i = 0; i < n; i++)
            {
                fathers[i] = i;
            }

			//��Ϊqueries[i]��һ����ѯ�Ҫ�����Ĵ��ans[i]����
			//����Ϊ�������Ŀ����Ҫ��queries����limit���򣬻����˳������
			//��queries����ᵽhelp���飬������help[i]�������index
			vector<vector<int>> help(m);
			for (int i = 0; i < m; i++)
			{
				help[i] = queries[i];
				help[i].push_back(i);
			}

			std::sort(help.begin(), help.end(), [](std::vector<int>& a, std::vector<int>& b)
				{
					return a[2] < b[2];
				});

			std::sort(edgeList.begin(), edgeList.end(), [](std::vector<int>& a, std::vector<int>& b)
				{
					return a[2] < b[2];
				});

			vector<bool> ans;
			ans.resize(m);

			//��help��ÿһ��Ԫ�أ���edgeList���������Ȩֵ < limit�ĺϲ�
			//�ϲ���֮�������ͬһ�������˵������·��������true
			int cur = 0;
			for (auto& col : help)
			{
				while (cur < edgeList.size() && edgeList[cur][2] < col[2])
				{
					Union(edgeList[cur][0], edgeList[cur][1]);
					cur++;
				}

				ans[col[3]] = isSameSet(col[0], col[1]) ? true : false;
			}

			return ans;

        }
    };
}