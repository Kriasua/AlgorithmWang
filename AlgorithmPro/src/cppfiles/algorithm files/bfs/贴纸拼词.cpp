// ��ֽƴ��
// ������ n �ֲ�ͬ����ֽ��ÿ����ֽ�϶���һ��Сд��Ӣ�ĵ��ʡ�
// ����Ҫƴд���������ַ��� target �������Ǵ��ռ�����ֽ���и����ĸ��������������
// �����Ը�⣬����Զ��ʹ��ÿ����ֽ��ÿ����ֽ�����������޵ġ�
// ��������Ҫƴ�� target ����С��ֽ������������񲻿��ܣ��򷵻� -1
// ע�⣺�����еĲ��������У����еĵ��ʶ��Ǵ� 1000 �����������Ӣ�ﵥ�������ѡ���
// ���� target ��ѡ��Ϊ����������ʵ����ӡ�
// �������� : https://leetcode.cn/problems/stickers-to-spell-word/

#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
namespace
{
    class Solution {  
    public:
        //��a��ȥbʣ��ʲô����ʵ���ǹ鲢����merge��˼��
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
            std::unordered_set<std::string> visited;  //�ù�ϣ��������߹��Ľڵ㣬����������Ѿ����ֹ����ַ���

            //���ڼ�֦
            std::vector<std::vector<std::string>> graph;
            std::vector<std::string> queue;
            queue.resize(401);
            graph.resize(26);
            int l = 0;
            int r = 0;

            //���ַ�������Ȼ��ͼ����������
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

            //������һ�ε�һ����ķ�ʽ
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