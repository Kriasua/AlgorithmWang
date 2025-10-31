// 最小体力消耗路径
// 你准备参加一场远足活动。给你一个二维 rows x columns 的地图 heights
// 其中 heights[row][col] 表示格子 (row, col) 的高度
// 一开始你在最左上角的格子 (0, 0) ，且你希望去最右下角的格子 (rows-1, columns-1) 
// （注意下标从 0 开始编号）。你每次可以往 上，下，左，右 四个方向之一移动
// 你想要找到耗费 体力 最小的一条路径
// 一条路径耗费的体力值是路径上，相邻格子之间高度差绝对值的最大值
// 请你返回从左上角走到右下角的最小 体力消耗值
// 测试链接 ：https://leetcode.cn/problems/path-with-minimum-effort/

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

        int minimumEffortPath(std::vector<std::vector<int>>& heights) {
            int n = heights.size();
            int m = heights[0].size();
            std::vector<std::vector<bool>> visited;
            visited.resize(n);
            for (auto& col : visited)
            {
                col.resize(m, false);
            }

            std::vector<std::vector<int>> distances(n, std::vector<int>(m, INT_MAX));
            std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;

            distances[0][0] = 0;
            heap.push({ 0,0,0 });

            while (!heap.empty())
            {
                int curX = heap.top()[0];
                int curY = heap.top()[1];
                int curDis = heap.top()[2];
                heap.pop();

                if (curX == n - 1 && curY == m - 1)
                {
                    return curDis;
                }

                if (!visited[curX][curY])
                {
                    visited[curX][curY] = true;
                    //先是上面的格子
                    if (curX > 0)
                    {
                        int diff = std::abs(heights[curX - 1][curY] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX - 1][curY])
                        {
                            distances[curX - 1][curY] = diff;
                            heap.push({ curX - 1,curY,distances[curX - 1][curY] });
                        }
                        
                    }

                    //下面的格子
                    if (curX < n-1)
                    {
                        int diff = std::abs(heights[curX + 1][curY] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX + 1][curY])
                        {
                            distances[curX + 1][curY] = diff;
                            heap.push({ curX + 1,curY,distances[curX + 1][curY] });
                        }
                    }

                    //左边的格子
                    if (curY > 0)
                    {
                        int diff = std::abs(heights[curX][curY-1] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX][curY-1])
                        {
                            distances[curX ][curY-1] = diff;
                            heap.push({ curX ,curY-1,distances[curX][curY-1] });
                        }
                    }

                    //右边的格子
                    if (curY < m-1)
                    {
                        int diff = std::abs(heights[curX][curY + 1] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX][curY + 1])
                        {
                            distances[curX][curY + 1] = diff;
                            heap.push({ curX ,curY + 1,distances[curX][curY + 1] });
                        }
                    }
                }
            }

            return -1;

        }
    };
}