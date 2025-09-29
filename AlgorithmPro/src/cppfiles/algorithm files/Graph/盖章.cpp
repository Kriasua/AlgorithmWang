// ��ӡ����
// �������յõ�"abcbc"����Ϊ��ʼ����Ϊ"?????"��ӡ����"abc"
// ��ô��������ӡ�¸ǳ�"??abc"��״̬��
// Ȼ����ӡ�������ַ������е�0λ�ö��룬�͸ǳ���"abcbc"
// ��������У�"??abc"�е�a�ַ�����ӡ���е�c�ַ�������
// ÿ�θ��µ�ʱ��ӡ�±�����ȫ����������
// ����һ���ַ���target�����յ�Ŀ�꣬����Ϊn����Ϊ��ʼ����Ϊn��'?'
// ����һ��ӡ���ַ���stamp��Ŀ�������ոǳ�target
// ����ӡ�µ�ʹ�ô���������10*n������
// ����һ�����飬��������ÿ���غ��б�ӡ�µ��������ĸ���������
// ��������ӷ���[2,0]����ʾӡ�������ַ����κ�����2λ�á�����0λ�ö������ȥ���͵õ���target
// ���������10*n����ӡ�����У��ͷ���һ��������
// �������� : https://leetcode.cn/problems/stamping-the-sequence/

#include<string>
#include<vector>
namespace
{
	class Solution {
	public:
		std::vector<int> movesToStamp(std::string stamp, std::string target) {
			int m = stamp.size();
			int n = target.size();
			std::vector<int> inDegree;
			std::vector<int> queue;
			std::vector<std::vector<int>> graph;
			inDegree.resize(n - m + 1, m);
			queue.resize(n - m + 1);
			graph.resize(n);

			int left = 0;
			int right = 0;

			for (int i = 0 ; i < n - m + 1; i++)
			{
				
				for (int j = 0; j < m; j++)
				{
					if (target[j+i] == stamp[j])
					{
						if (--inDegree[i] == 0)
						{
							queue[right++] = i;
						}
					}
					else
					{
						graph[i + j].push_back(i);
					}
					
				}
			}

			std::vector<bool> visted;
			visted.resize(n,false);

			std::vector<int> ans;
			int cur;
			while (left < right)
			{
				cur = queue[left++];
				ans.push_back(cur);
				for (int i = 0; i < m; i++)
				{
					if (!visted[cur + i])
					{
						visted[cur + i] = true;
						for (int num : graph[cur + i])
						{
							if (--inDegree[num] == 0)
							{
								queue[right++] = num;
							}
						}
					}
				}
			}

			if (ans.size() != n - m + 1)
			{
				return {};
			}

			for (int i = 0,temp; i < ans.size() >> 1; i++)
			{
				temp = ans[i];
				ans[i] = ans[ans.size() - i - 1];
				ans[ans.size() - i - 1] = temp;
			}

			return ans;

		}
	};
}