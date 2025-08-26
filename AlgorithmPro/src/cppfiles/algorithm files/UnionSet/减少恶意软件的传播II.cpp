// �������ٶ�������Ĵ��� II
// ����һ���� n ���ڵ���ɵ����磬�� n x n ���ڽӾ��� graph ��ʾ
// �ڽڵ������У�ֻ�е� graph[i][j] = 1 ʱ���ڵ� i �ܹ�ֱ�����ӵ���һ���ڵ� j��
// һЩ�ڵ� initial ��������������Ⱦ��ֻҪ�����ڵ�ֱ�����ӣ�
// ����������һ���ڵ��ܵ���������ĸ�Ⱦ����ô�����ڵ㶼�������������Ⱦ��
// ���ֶ�������Ĵ�����������ֱ��û�и���Ľڵ���Ա����ַ�ʽ��Ⱦ��
// ���� M(initial) ���ڶ������ֹͣ����֮�����������и�Ⱦ������������սڵ�����
// ���ǿ��Դ� initial ��ɾ��һ���ڵ㣬
// ����ȫ�Ƴ��ýڵ��Լ��Ӹýڵ㵽�κ������ڵ���κ����ӡ�
// �뷵���Ƴ����ܹ�ʹ M(initial) ��С���Ľڵ㡣
// ����ж���ڵ������������������� ��С�Ľڵ� ��
// initial ��ÿ����������ͬ
// �������� : https://leetcode.cn/problems/minimize-malware-spread-ii/

#include<vector>
#include<unordered_set>
#include<algorithm>
namespace
{
	using std::vector;
	class Solution {
	public:
		int n;
		vector<int> father;
		vector<int> size;
		vector<int> origin;
		vector<int> cnts;
		std::unordered_set<int> set;
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

			father[fa] = fb;
			size[fb] += size[fa];
		}

		int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
			std::sort(initial.begin(), initial.end());
			n = graph.size();
			father.resize(n);
			size.resize(n,1);
			origin.resize(n,-1);
			cnts.resize(initial.size());

			//�Ѹ�Ⱦ�ڵ�����ϣ��
			for (int num : initial)
			{
				set.emplace(num);
			}

			//��ʼ�����鼯
			for (int i = 0; i < n; i++)
			{
				father[i] = i;
			}

			//��һ�����Ȱѷ�initial�ڵ�ϲ�
			for (int i = 0; i < n; i++)
			{
				if (set.find(i) != set.end())
				{
					continue;
				}

				for (int j = 0; j <= i; j++)
				{
					if (graph[i][j] == 1 && set.find(j) == set.end())
					{
						Union(i,j);
					}
				}
			}


			//����ÿһ��initial�ڵ㣬�����������ӵļ��ϣ����Դͷ���������������������Դͷ����Ϊ-2
			for (int num : initial)
			{
				for (int i = 0; i < n; i++)
				{
					if (graph[num][i] == 1 && set.find(i) == set.end())
					{
						int root = find(i);
						if (origin[root] == -1)
						{
							origin[root] = num;
						}
						else if(origin[root] != num)
						{
							origin[root] = -2;
						}
					}
				}
			}

			//ͳ��ÿһ��initial�ڵ����նԴ𰸵Ĺ���
			for (int j = 0;j<initial.size();j++)
			{
				std::unordered_set<int> roots;
				for (int i = 0; i < n; i++)
				{
					if (graph[initial[j]][i] == 1 && set.find(i) == set.end())
					{
						int root = find(i);
						if (origin[root] != -2 && roots.find(root) == roots.end())
						{
							cnts[j] += size[root];
							roots.emplace(root);
						}
					}
				}
			}

			int ans = initial.size() - 1;
			for (int i = initial.size() - 1; i >= 0; i--)
			{
				if (cnts[i] >= cnts[ans])
				{
					ans = i;
				}
			}

			return initial[ans];
			
		}
	};
}