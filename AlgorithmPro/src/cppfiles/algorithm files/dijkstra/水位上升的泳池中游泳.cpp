// 水位上升的泳池中游泳
// 在一个 n x n 的整数矩阵 grid 中
// 每一个方格的值 grid[i][j] 表示位置 (i, j) 的平台高度
// 当开始下雨时，在时间为 t 时，水池中的水位为 t
// 你可以从一个平台游向四周相邻的任意一个平台，但是前提是此时水位必须同时淹没这两个平台
// 假定你可以瞬间移动无限距离，也就是默认在方格内部游动是不耗时的
// 当然，在你游泳的时候你必须待在坐标方格里面。
// 你从坐标方格的左上平台 (0，0) 出发
// 返回 你到达坐标方格的右下平台 (n-1, n-1) 所需的最少时间
// 测试链接 : https://leetcode.cn/problems/swim-in-rising-water/

#include<vector>
#include<queue>
#include<array>
namespace
{
    class Solution {
    public:
        struct compare
        {
            bool operator()(const auto& a, const auto& b)
            {
                return a[2] > b[2];
            }
        };

        int swimInWater(std::vector<std::vector<int>>& grid) {
            int n = grid.size();
            std::vector<std::vector<bool>> visited;
            visited.resize(n);
            for (auto& col : visited)
            {
                col.resize(n, false);
            }

            std::vector<std::vector<int>> distances(n, std::vector<int>(n, INT_MAX));
            std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;

            distances[0][0] = grid[0][0];
            heap.push({ 0,0,grid[0][0] });

            while (!heap.empty())
            {
                int curX = heap.top()[0];
                int curY = heap.top()[1];
                int curDis = heap.top()[2];
                heap.pop();

                if (curX == n - 1 && curY == n - 1)
                {
                    return curDis;
                }

                if (!visited[curX][curY])
                {
                    visited[curX][curY] = true;
                    //先是上面的格子
                    if (curX > 0)
                    {
                        int time = std::max(grid[curX-1][curY], curDis);
                        if (time < distances[curX - 1][curY])
                        {
                            distances[curX - 1][curY] = time;
                            heap.push({ curX - 1,curY,distances[curX - 1][curY] });
                        }

                    }

                    if (curX < n-1)
                    {
                        int time = std::max(grid[curX + 1][curY], curDis);
                        if (time < distances[curX + 1][curY])
                        {
                            distances[curX + 1][curY] = time;
                            heap.push({ curX + 1,curY,distances[curX + 1][curY] });
                        }

                    }

                    if (curY > 0)
                    {
                        int time = std::max(grid[curX][curY-1], curDis);
                        if (time < distances[curX][curY-1])
                        {
                            distances[curX ][curY-1] = time;
                            heap.push({ curX ,curY-1,distances[curX ][curY-1] });
                        }
                    }

                    if (curY < n-1)
                    {
                        int time = std::max(grid[curX][curY + 1], curDis);
                        if (time < distances[curX][curY + 1])
                        {
                            distances[curX][curY + 1] = time;
                            heap.push({ curX ,curY + 1,distances[curX][curY + 1] });
                        }
                    }
                }
            }

            return -1;

        }
};
}