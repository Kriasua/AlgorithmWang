// ���ʽ��� II
// ���ֵ� wordList ��ɴӵ��� beginWord ������ endWord ת��
// һ����ʾ�˹��̵� ת������ ����ʽ���� 
// beginWord -> s1 -> s2 -> ... -> sk �����ĵ������У������㣺
// ÿ�����ڵĵ���֮����е�����ĸ��ͬ
// ת�������е�ÿ������ si��1 <= i <= k���������ֵ� wordList �еĵ���
// ע�⣬beginWord �������ֵ� wordList �еĵ���
// sk == endWord
// ������������ beginWord �� endWord ���Լ�һ���ֵ� wordList
// �����ҳ����������д� beginWord �� endWord �� ���ת������
// ���������������ת�����У�����һ�����б�
// ÿ�����ж�Ӧ���Ե����б� [beginWord, s1, s2, ..., sk] ����ʽ����
// �������� : https://leetcode.cn/problems/word-ladder-ii/
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
namespace
{
    using namespace std;
    class Solution {
    public:
        //����ͼ
        unordered_map<string, vector<string>> graph;

        //�ѵ��ʱ�ת�ɹ�ϣ��
        unordered_set<string> dict;

        //bfs�ù�ϣ��
        unordered_set<string> curLevel;
        unordered_set<string> nextLevel;

        //�ύ����
        vector<vector<string>> ans;
        vector<string> path;

        void build(vector<string>& wordList)
        {
            ans.clear();
            curLevel.clear();
            path.clear();
            nextLevel.clear();
            graph.clear();
            dict.insert(wordList.begin(), wordList.end());
        }

        bool bfs(string beginWord, string endWord)
        {
            int find = false;
            curLevel.emplace(beginWord);
            while (!curLevel.empty())
            {
                std::erase_if(dict, [&](const string& str)
                    {
                        return curLevel.contains(str);
                    });

                for (const string& old : curLevel)
                {
                    string str = old;
                    for (int i = 0; i < str.size(); i++)
                    {
                        char original = str[i];
                        for (char c = 'a'; c <= 'z'; c++)
                        {
                            str[i] = c;
                            if (dict.contains(str))
                            {
                                if (str == endWord)
                                {
                                    find = true;
                                }
                                nextLevel.emplace(str);
                                graph[str].push_back(old);
                            }
                        }
                        str[i] = original;
                    }
                }

                if (find)
                {
                    return true;
                }
                else
                {
                    curLevel = std::move(nextLevel);
                }
            }
            return find;
        }

        void dfs(string endWord, string beginWord)
        {
            path.push_back(endWord);
            if (endWord == beginWord)
            {
                ans.push_back(path); 
            }
            else
            {
                for (string str : graph[endWord])
                {
                    dfs(str, beginWord); 
                }
            }

            path.pop_back();
        }

        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            build(wordList);
            if (!dict.contains(endWord))
            {
                return ans;
            }

            if (bfs(beginWord, endWord))
            {
                dfs(endWord, beginWord);
            }
            
            for (vector<string>& stringList : ans)
            {
                std::reverse(stringList.begin(), stringList.end());
            }

            return ans;
        }
    };
}