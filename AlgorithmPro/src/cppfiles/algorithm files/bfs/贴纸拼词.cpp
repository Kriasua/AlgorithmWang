// 贴纸拼词
// 我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
// 您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们
// 如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
// 返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1
// 注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的
// 并且 target 被选择为两个随机单词的连接。
// 测试链接 : https://leetcode.cn/problems/stickers-to-spell-word/

#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
namespace
{
    class Solution {  
    public:
        //算a减去b剩下什么，其实就是归并排序merge的思想
        std::string findNext(const std::string& a, const std::string& b)
        {
            std::string ans = "";
            int l = 0;
            int r = 0;
            while (l < a.size() && r < b.size())
            {
                if (a[l] == b[r])
                {
                    l++;
                    r++;
                }
                else if (a[l] < b[r])
                {
                    ans += a[l++];
                }
                else
                {
                    r++;
                }
            }

            while (l < a.size())
            {
                ans += a[l++];
            }

            return ans;
        }

        int minStickers(std::vector<std::string>& stickers, std::string target) {
            std::unordered_set<std::string> visited;  //用哈希表来标记走过的节点，在这里就是已经出现过的字符串

            //用于剪枝
            std::vector<std::vector<std::string>> graph;
            std::vector<std::string> queue;
            queue.resize(401);
            graph.resize(26);
            int l = 0;
            int r = 0;

            //给字符串排序，然后建图，方便做题
            for (std::string& str : stickers)
            {
                std::sort(str.begin(), str.end());
                for (int i = 0; i < str.size(); i++)
                {
                    if (i == 0 || str[i] != str[i - 1])
                    {
                        graph[str[i] - 'a'].push_back(str);
                    }
                }
            }

            std::sort(target.begin(), target.end());
            visited.emplace(target);
            queue[r++] = target;
            int level = 1;

            //还是用一次弹一整层的方式
            while (l < r)
            {               
                int size = r - l;
                for (int i = 0; i < size; i++)
                {
                    std::string cur = queue[l++];
                    for (std::string& str : graph[cur[0] - 'a'])
                    {
                        std::string next = findNext(cur, str);
                        if (next.empty())
                        {
                            return level;
                        }
                        else if (visited.find(next) == visited.end())
                        {
                            queue[r++] = next;
                            visited.emplace(next);
                        }
                    }
                }
                level++;
            }
            return -1;
        }
    };
}