// 单词接龙 II
// 按字典 wordList 完成从单词 beginWord 到单词 endWord 转化
// 一个表示此过程的 转换序列 是形式上像 
// beginWord -> s1 -> s2 -> ... -> sk 这样的单词序列，并满足：
// 每对相邻的单词之间仅有单个字母不同
// 转换过程中的每个单词 si（1 <= i <= k）必须是字典 wordList 中的单词
// 注意，beginWord 不必是字典 wordList 中的单词
// sk == endWord
// 给你两个单词 beginWord 和 endWord ，以及一个字典 wordList
// 请你找出并返回所有从 beginWord 到 endWord 的 最短转换序列
// 如果不存在这样的转换序列，返回一个空列表
// 每个序列都应该以单词列表 [beginWord, s1, s2, ..., sk] 的形式返回
// 测试链接 : https://leetcode.cn/problems/word-ladder-ii/
#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<string>
namespace
{
    using namespace std;
    class Solution {
    public:
        //反向图
        unordered_map<string, vector<string>> graph;

        //把单词表转成哈希表
        unordered_set<string> dict;

        //bfs用哈希表
        unordered_set<string> curLevel;
        unordered_set<string> nextLevel;

        //提交答案用
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