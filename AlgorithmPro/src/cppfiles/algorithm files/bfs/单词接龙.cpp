//单词接龙II的简化版，只要懂那个的话这个就很简单
//测试链接 : https://leetcode.cn/problems/word-ladder/description/

#include<string>
#include<unordered_set>
#include<vector>
namespace
{
	using namespace std;
    //单bfs，时间较慢，后面有个更优解法：双向广度优先搜索，时间更快
    class Solution {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(wordList.begin(),wordList.end());
            if (!dict.contains(endWord))
            {
                return 0;
            }

            vector<string> queue(100001);
            int l = 0;
            int r = 0;
            queue[r++] = beginWord;
            int level = 1;

            while (l < r)
            {
                int size = r - l;
                for (int i = l; i < l + size; i++)
                {
                    dict.erase(queue[i]);
                }
                for (int i = 0; i < size; i++)
                {
                    string str = queue[l++];
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
                                    return level+1;
                                }
                                queue[r++] = str;
                            }
                        }
                        str[i] = original;
                    }
                }
                level++;
            }

            return 0;

        }
    };

    //双向广搜优化
    class Solution2 {
    public:
        int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set<string> dict(wordList.begin(), wordList.end());
            unordered_set<string> smallSet;
            unordered_set<string> bigSet;
            unordered_set<string> nextLevelSet;
            if (!dict.contains(endWord))
            {
                return 0;
            }

            smallSet.emplace(beginWord);
            bigSet.emplace(endWord);
            int level = 1;
   

            while (!smallSet.empty() && !bigSet.empty())
            {
                if (smallSet.size() > bigSet.size())
                {
                    smallSet.swap(bigSet);
                }

                std::erase_if(dict, [&](const string& str)
                    {
                        return smallSet.contains(str);
                    });

                for (const string& old : smallSet)
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
                                if (bigSet.contains(str))
                                {
                                    return level+1;
                                }
                                nextLevelSet.emplace(str);         
                            }
                        }
                        str[i] = original;
                    }
                }

                smallSet = std::move(nextLevelSet);
                level++;
            }

            return 0;

        }
    };
}