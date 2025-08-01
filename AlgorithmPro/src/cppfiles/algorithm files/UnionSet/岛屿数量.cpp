// ��������
// ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά����������������е��������
// �������Ǳ�ˮ��Χ������ÿ������ֻ����ˮƽ�����/����ֱ���������ڵ�½�������γ�
// ���⣬����Լ��������������߾���ˮ��Χ
// �������� : https://leetcode.cn/problems/number-of-islands/

#include<vector>
namespace
{

    //�ò��鼯���ģ����滹�и��ú�ˮ������ġ�
    class Solution {
    public:
        std::vector<int> fathers;
        int sets;


        int find(int num)
        {
            if (num == fathers[num])
            {
                return num;
            }

            int result = find(fathers[num]);
            fathers[num] = result;
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

            fathers[fa] = fb;
            sets--;
        }

        int numIslands(std::vector<std::vector<char>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            fathers.resize(m * n);

            for (int i = 0; i < fathers.size(); i++)
            {
                fathers[i] = i;
            }

            sets = 0;
             
            for (int i = 0; i < m; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == '1')
                    {
                        sets++;
                        //����߲��������1
                        if ((j > 0) && grid[i][j - 1] == '1')
                        {
                            Union(i * n + j, i * n + j - 1);
                        }

                        //���ϱ߲����ϱ���1
                        if (i > 0 && grid[i - 1][j] == '1')
                        {
                            Union(i * n + j, i * n + j - n);
                        }

                    }
                }
            }

            return sets;
        }
    };
}