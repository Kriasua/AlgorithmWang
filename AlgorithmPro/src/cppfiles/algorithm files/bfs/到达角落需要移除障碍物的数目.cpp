// 到达角落需要移除障碍物的最小数目
// 给你一个下标从 0 开始的二维整数数组 grid ，数组大小为 m x n
// 每个单元格都是两个值之一：
// 0 表示一个 空 单元格，
// 1 表示一个可以移除的 障碍物
// 你可以向上、下、左、右移动，从一个空单元格移动到另一个空单元格。
// 现在你需要从左上角 (0, 0) 移动到右下角 (m - 1, n - 1) 
// 返回需要移除的障碍物的最小数目
// 测试链接 : https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/

#include<vector>
#include<deque>
#include<array>
namespace
{
    using std::pair;
    class Solution {
    public:  
        void push(std::vector<std::vector<int>>& grid, int i, int j, std::vector<std::vector<int>>& distances, std::deque<std::array<int, 2>>& queue)
        {
            //有上就加上
            if (i > 0 && distances[i][j] + grid[i-1][j] < distances[i-1][j])
            {
                distances[i - 1][j] = distances[i][j] + grid[i - 1][j];
                if (grid[i - 1][j] == 0)
                {
                    queue.push_front({ i - 1,j });
                }
                else
                {
                    queue.push_back({ i - 1,j });
                }
            }
            //有下就加下
            if (i < grid.size()-1 && distances[i][j] + grid[i + 1][j] < distances[i + 1][j])
            {
                distances[i + 1][j] = distances[i][j] + grid[i + 1][j];
                if (grid[i + 1][j] == 0)
                {
                    queue.push_front({ i + 1,j });
                }
                else
                {
                    queue.push_back({ i + 1,j });
                }
            }
            //有左就加左
            if (j > 0 && distances[i][j] + grid[i][j-1] < distances[i][j-1])
            {
                distances[i][j-1] = distances[i][j] + grid[i][j-1];
                if (grid[i][j-1] == 0)
                {
                    queue.push_front({ i ,j-1 });
                }
                else
                {
                    queue.push_back({ i ,j -1});
                }
            }
            //有右就加右
            if (j < grid[0].size() - 1 && distances[i][j] + grid[i][j + 1] < distances[i][j + 1])
            {
                distances[i][j + 1] = distances[i][j] + grid[i][j + 1];
                if (grid[i][j + 1] == 0)
                {
                    queue.push_front({ i ,j + 1 });
                }
                else
                {
                    queue.push_back({ i ,j + 1 });
                }
            }
        }

        int minimumObstacles(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            std::vector<std::vector<int>> distances;
            distances.resize(m);

            std::deque<std::array<int,2>> queue;
            for (auto& col : distances)
            {
                col.resize(n, INT_MAX);
            }
            distances[0][0] = 0;
            queue.push_back({ 0,0 });

            while (!queue.empty())
            {
                int x = queue.front()[0];
                int y = queue.front()[1];
                queue.pop_front();
                if (x == m - 1 && y == n - 1)
                {
                    return distances[x][y];
                }
                else
                {
                    push(grid, x, y, distances, queue);

                }
            }

            return -1;
        }
    };
}