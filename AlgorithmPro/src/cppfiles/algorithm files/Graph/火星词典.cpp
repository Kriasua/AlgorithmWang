// ���Ǵʵ�
// ����һ��ʹ��Ӣ����ĸ�Ļ�������
// �������Ե���ĸ˳�������˵��δ֪�ġ�
// ����һ�������������������ֵ���ַ����б� words
// words �е��ַ����Ѿ� �����������Ե���ĸ˳����������� ��
// �������˵���Ǵ���ģ����Ҹ����� words ���ܶ�Ӧ�κ���ĸ��˳���򷵻� ""
// ���򣬷���һ���������Թ���� �ֵ����˳�� ����Ķ����ַ���
// ����ж������������򷵻���������һ��
// words�еĵ���һ������СдӢ����ĸ��ɵ�
// �������� : https://leetcode.cn/problems/alien-dictionary/
// ��������(����Ҫ��Ա) : https://leetcode.cn/problems/Jf1JuT/

#include<vector>
#include<string>
namespace
{
	using std::string;
	using std::vector;
	class Solution {
	public:
		string alienOrder(vector<string>& words) {

			//if (words.size() == 1)
			//{
			//	return words[0];
			//}

			string ans;
			vector<vector<int>> graph;
			vector<int> inDegree;
			vector<int> queue;
			graph.resize(26);

			//��Щ��ĸ���ܴ���û���ֹ���ʹ��-1��ʾδ���ֹ�����ĸ,0��ʾ���ֹ���
			inDegree.resize(26,-1);
			for (string str : words)
			{
				for (char c : str)
				{
					inDegree[c - 'a'] = 0;
				}
			}


			queue.resize(26);
			int l = 0;
			int r = 0;



			//��ͼ
			for (int i = 0, j , len; i < words.size() - 1; i++)
			{
				string cur = words[i];
				string next = words[i + 1];
				len = std::min(cur.size(), next.size());
				j = 0;
				for (; j < len; j++)
				{
					if (cur[j] != next[j])
					{
						graph[cur[j] - 'a'].push_back(next[j] - 'a');
						inDegree[next[j] - 'a']++;
						break;
					}
				}

				if (j < cur.size() && j == next.size())
				{
					return "";
				}
			}

			//���Ϊ0���Ƚ�����
			int kinds=0;//ͳ�Ƴ��ֹ�����ĸ�м���
			for (int i = 0; i < 26; i++)
			{
				if (inDegree[i] != -1)
				{
					kinds++;
				}

				if (inDegree[i] == 0)
				{
					queue[r++] = i;
				}
			}

			int cur;
			//ѭ�����������в�Ϊ��
			while (l < r)
			{
				cur = queue[l++];
				ans.push_back(cur + 'a');
				for (int letter : graph[cur])
				{
					if (--inDegree[letter] == 0)
					{
						queue[r++] = letter;
					}
				}
			}
			
			return kinds == ans.size() ? ans : "";
		
		}
	};
}