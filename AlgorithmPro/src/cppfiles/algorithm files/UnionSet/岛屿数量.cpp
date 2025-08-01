// 岛屿数量
// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成
// 此外，你可以假设该网格的四条边均被水包围
// 测试链接 : https://leetcode.cn/problems/number-of-islands/

#include<vector>
namespace
{

    //用并查集做的，下面还有个用洪水填充做的。
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
                        //有左边并且左边是1
                        if ((j > 0) && grid[i][j - 1] == '1')
                        {
                            Union(i * n + j, i * n + j - 1);
                        }

                        //有上边并且上边是1
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