// ţţ������������Լ����һ�׽�ͷ�ܳ�ϵͳ������ȷ�ϱ˴����
// �ܳ���һ���������б�ʾ�������ܳױ���Ϊ��һ�µģ������������������
// �ܳ� b �ĳ��Ȳ������ܳ� a �ĳ��ȡ�
// �������� 0 <= i < length(b)����b[i+1] - b[i] == a[i+1] - a[i]
// ���ڸ�����m���ܳ� b �����飬�Լ�n���ܳ� a ������
// ���㷵��һ������Ϊ m �Ľ������ ans����ʾÿ���ܳ�b���ж���һ�µ��ܳ�
// ���� a ������ b �е�Ԫ�ظ����������� 10^5
// 1 <= m, n <= 1000
// �������� : https://www.nowcoder.com/practice/c552d3b4dfda49ccb883a6371d9a6932

#include<string>
#include<vector>
namespace
{
    class Solution {
    public:
        const int MAX = 150001;
        std::vector<std::vector<int>> trie;
        std::vector<int> pass;
        std::vector<int> end;
        int cnt;

        Solution()
        {
            trie.resize(MAX, std::vector<int>(12, 0));
            pass.resize(MAX, 0);
            end.resize(MAX, 0);
            cnt = 1;
        }

        void build()
        {
            cnt = 1;
        }

        void clear()
        {
            std::fill(pass.begin(), pass.begin() + cnt, 0);
            std::fill(end.begin(), end.begin() + cnt, 0);
            for (int i=1;i<=cnt;i++)
            {
                std::fill(trie[i].begin(), trie[i].end(), 0);
            }
        }

        int path(char a)
        {
            if (a == '#')
            {
                return 10;
            }
            else if (a == '-')
            {
                return 11;
            }
            else
            {
                return a - '0';
            }
        }

        void insert(std::string& str)
        {
            int p;
            int cur = 1;
            pass[cur]++;
            for (int i = 0; i < str.size(); i++)
            {
                p = path(str[i]);
                if (trie[cur][p] == 0)
                {
                    trie[cur][p] = ++cnt;
                }
                cur = trie[cur][p];
                pass[cur]++;
            }
            end[cur]++;
        }

        int search(std::string& str)
        {
            int p;
            int cur = 1;
            for (int i = 0; i < str.size(); i++)
            {
                p = path(str[i]);
                if (trie[cur][p] == 0)
                {
                    return 0;
                }
                cur = trie[cur][p];
            }
            return pass[cur];
        }


        std::vector<int> countConsistentKeys(std::vector<std::vector<int>>& b, std::vector<std::vector<int>>& a) {
            std::vector<int> ans;
            build();
            std::string s;
            for (auto& row : a)
            {
                s.clear();
                for (int i = 1; i < row.size(); i++)
                {
                    s += std::to_string(row[i] - row[i - 1]);
                    s += '#';
                }
                insert(s);
            }
            int cnt;
            for (auto& row : b)
            {
                s.clear();

                for (int i = 1; i < row.size(); i++)
                {
                    s += std::to_string(row[i] - row[i - 1]);
                    s += '#';   
                }

                cnt = search(s);
                ans.push_back(cnt);
            }

            clear();
            return ans;
        }
    };



    
}
