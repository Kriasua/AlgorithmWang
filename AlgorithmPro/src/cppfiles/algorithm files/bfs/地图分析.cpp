// 地图分析
// 你现在手里有一份大小为 n x n 的 网格 grid
// 上面的每个 单元格 都用 0 和 1 标记好了其中 0 代表海洋，1 代表陆地。
// 请你找出一个海洋单元格，这个海洋单元格到离它最近的陆地单元格的距离是最大的
// 并返回该距离。如果网格上只有陆地或者海洋，请返回 -1。
// 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：
// (x0, y0) 和 (x1, y1) 这两个单元格之间的距离是 |x0 - x1| + |y0 - y1| 。
// 测试链接 : https://leetcode.cn/problems/as-far-from-land-as-possible/

#include<vector>

namespace
{
    class Solution {
    public:

        std::vector<std::pair<int, int>> queue;
        std::vector<std::vector<bool>> help;
        int l, r;
        void search(std::vector<std::vector<int>>& grid, int i, int j)
        {
            int n = grid.size();
            //有上就加上
            if (i > 0 && help[i - 1][j] == false)
            {
                queue[r++] = { i - 1,j };
                help[i - 1][j] = true;
            }
            //有下就加下
            if (i < n - 1 && help[i + 1][j] == false)
            {
                queue[r++] = { i + 1,j };
                help[i + 1][j] = true;
            }
            //有左就加左
            if (j > 0 && help[i][j - 1] == false)
            {
                queue[r++] = { i,j-1 };
                help[i][j - 1] = true;
            }
            //有右就加右
            if (j < n - 1 && help[i][j + 1] == false)
            {
                queue[r++] = { i,j + 1 };
                help[i][j + 1] = true;
            }
        }

        int maxDistance(std::vector<std::vector<int>>& grid) {
           

            l = 0;
            r = 0;
            int n = grid.size();

            queue.resize(n * n);
            help.resize(n);
            for (auto& col : help)
            {
                col.resize(n);
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        queue[r++] = { i,j };
                        help[i][j] = true;
                    }
                    else
                    {
                        help[i][j] = false;
                    }
                }
            }

            //全是海洋
            if (r == 0)
            {
                return -1;
            }

            int level = 0;
            int cnt;
            while (l < r)
            {
                cnt = r - l;
                for (int i = 0; i < cnt; i++)
                {
                    search(grid, queue[l].first, queue[l++].second);
                }
                level++;
            }

            //全是陆地返回-1
            return level == 1 ? -1 : level-1;
        }
    };
}