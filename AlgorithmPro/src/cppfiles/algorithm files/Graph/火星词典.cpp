// 火星词典
// 现有一种使用英语字母的火星语言
// 这门语言的字母顺序对你来说是未知的。
// 给你一个来自这种外星语言字典的字符串列表 words
// words 中的字符串已经 按这门新语言的字母顺序进行了排序 。
// 如果这种说法是错误的，并且给出的 words 不能对应任何字母的顺序，则返回 ""
// 否则，返回一个按新语言规则的 字典递增顺序 排序的独特字符串
// 如果有多个解决方案，则返回其中任意一个
// words中的单词一定都是小写英文字母组成的
// 测试链接 : https://leetcode.cn/problems/alien-dictionary/
// 测试链接(不需要会员) : https://leetcode.cn/problems/Jf1JuT/

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

			//有些字母可能从来没出现过，使用-1表示未出现过的字母,0表示出现过的
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



			//建图
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

			//入度为0的先进队列
			int kinds=0;//统计出现过的字母有几个
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
			//循环条件，队列不为空
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