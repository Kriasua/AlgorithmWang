// ��·������Ŀ
// ����һ�� n ���ڵ��������ͨ�����޻���ͼ��
// �ڵ��Ŵ�0��n-1����ǡ����n-1����
// ����һ������Ϊ n �±�� 0 ��ʼ���������� vals
// �ֱ��ʾÿ���ڵ��ֵ��ͬʱ����һ����ά�������� edges
// ���� edges[i] = [ai, bi] ��ʾ�ڵ� ai �� bi ֮����һ�� ���� ��
// ��·����Ҫ����������������ʼ�ͽ����ڵ��ֵ��ͬ�� ·��������ֵ��С�ڵ��ڿ�ʼ��ֵ
// ���㷵�ز�ͬ��·������Ŀ
// ע�⣬һ��·�����������·������ ͬһ ·��
// �ȷ�˵�� 0 -> 1 �� 1 -> 0 ��Ϊͬһ��·���������ڵ�Ҳ��Ϊһ���Ϸ�·��
// �������� : https://leetcode.cn/problems/number-of-good-paths/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:
		int n;
		std::vector<int> father;
		std::vector<int> max;
		std::vector<int> maxCnts;
		int ans;
		int find(int num)
		{
			if (num == father[num])
			{
				return num;
			}

			int result = find(father[num]);
			father[num] = result;
			return result;
		}

		void Union(int a, int b)
		{
			int fa = find(a);
			int fb = find(b);

			if (fa == fb)
			{
				return;
			}

			if (max[fa] == max[fb])
			{
				ans += maxCnts[fa] * maxCnts[fb];
				maxCnts[fb] += maxCnts[fa];
			}
			else if (max[fa] > max[fb])
			{
				max[fb] = max[fa];
				maxCnts[fb] = maxCnts[fa];
			}
			else
			{

			}

			father[fa] = fb;
			
		}

		int numberOfGoodPaths(std::vector<int>& vals, std::vector<std::vector<int>>& edges) {
			//��ʼ�����鼯�������
			ans = 0;
			n = vals.size();
			father.resize(n);
			max.resize(n);
			maxCnts.resize(n,1);
			for (int i = 0; i < n; i++)
			{
				father[i] = i;
				max[i] = vals[i];
			}

			//�������ֵ������edges����
			std::sort(edges.begin(), edges.end(), [&](std::vector<int>& a, std::vector<int>& b)
				{
					return std::max(vals[a[0]], vals[a[1]]) < std::max(vals[b[0]], vals[b[1]]);
				});

			for (auto& edge : edges)
			{
				Union(edge[0], edge[1]);
			}

			//����һ���ڵ�Ҳ�Ǻ�·�������Լ�n
			return ans + n;
		}
	};
}