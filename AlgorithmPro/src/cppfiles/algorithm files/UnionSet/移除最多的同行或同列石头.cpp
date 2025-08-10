// �Ƴ�����ͬ�л�ͬ��ʯͷ
// n ��ʯͷ�����ڶ�άƽ���е�һЩ����������ϡ�ÿ������������ֻ����һ��ʯͷ
// ���һ��ʯͷ�� ͬ�л���ͬ�� ��������ʯͷ���ڣ���ô�Ϳ����Ƴ����ʯͷ
// ����һ������Ϊ n ������ stones ������ stones[i] = [xi, yi] ��ʾ�� i ��ʯͷ��λ��
// ���� �����Ƴ���ʯ�� �����������
// �������� : https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/

#include<vector>
#include<unordered_map>
namespace
{
    class Solution {
    public:
        std::vector<int> father;
        std::unordered_map<int, int> row;
        std::unordered_map<int, int> col;
        int sets;

        int find(int num)
        {
            if (father[num] == num)
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
            sets--;
            father[fa] = fb;
        }

        int removeStones(std::vector<std::vector<int>>& stones) {
           
            int n = stones.size();
            father.resize(n);
            sets = n;
            for (int i = 0; i < n; i++)
            {
                father[i] = i;
            }

            for (int i = 0; i < n; i++)
            {
                auto itcol = col.find(stones[i][1]);
                auto itrow = row.find(stones[i][0]);

                if (itcol != col.end())
                {
                    Union(itcol->second, i);
                }
                else
                {
                    col.emplace(stones[i][1], i);
                }

                if (itrow != row.end())
                {
                    Union(itrow->second, i);
                }
                else
                {
                    row.emplace(stones[i][0], i);
                }

            }

            return n - sets;

        }
    };
}