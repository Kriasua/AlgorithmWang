// 使网格图至少有一条有效路径的最小代价
// 给你一个 m * n 的网格图 grid 。 grid 中每个格子都有一个数字
// 对应着从该格子出发下一步走的方向。 grid[i][j] 中的数字可能为以下几种情况：
// 1 ，下一步往右走，也就是你会从 grid[i][j] 走到 grid[i][j + 1]
// 2 ，下一步往左走，也就是你会从 grid[i][j] 走到 grid[i][j - 1]
// 3 ，下一步往下走，也就是你会从 grid[i][j] 走到 grid[i + 1][j]
// 4 ，下一步往上走，也就是你会从 grid[i][j] 走到 grid[i - 1][j]
// 注意网格图中可能会有 无效数字 ，因为它们可能指向 grid 以外的区域
// 一开始，你会从最左上角的格子 (0,0) 出发
// 我们定义一条 有效路径 为从格子 (0,0) 出发，每一步都顺着数字对应方向走
// 最终在最右下角的格子 (m - 1, n - 1) 结束的路径
// 有效路径 不需要是最短路径
// 你可以花费1的代价修改一个格子中的数字，但每个格子中的数字 只能修改一次
// 请你返回让网格图至少有一条有效路径的最小代价
// 测试链接 : https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

#include<vector>
#include<deque>
#include<array>
namespace
{
    class Solution {
    public:

        void push(std::vector<std::vector<int>>& grid, std::deque<std::array<int, 2>>& queue, std::vector<std::vector<int>>& distances, int i, int j)
        {
            int cost;
            if (i > 0)
            {
                cost = grid[i][j] == 4 ? 0 : 1;
                if (distances[i][j] + cost < distances[i - 1][j])
                {
                    distances[i - 1][j] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i - 1,j });
                    }
                    else
                    {
                        queue.push_back({ i - 1,j });
                    }
                }
            }

            if (i < grid.size()-1)
            {
                cost = grid[i][j] == 3 ? 0 : 1;
                if (distances[i][j] + cost < distances[i + 1][j])
                {
                    distances[i + 1][j] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i + 1,j });
                    }
                    else
                    {
                        queue.push_back({ i + 1,j });
                    }
                }
            }

            if (j > 0)
            {
                cost = grid[i][j] == 2 ? 0 : 1;
                if (distances[i][j] + cost < distances[i][j-1])
                {
                    distances[i][j-1] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i,j-1 });
                    }
                    else
                    {
                        queue.push_back({ i ,j -1 });
                    }
                }
            }

            if (j < grid[0].size() -1 )
            {
                cost = grid[i][j] == 1 ? 0 : 1;
                if (distances[i][j] + cost < distances[i][j + 1])
                {
                    distances[i][j+1] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i,j + 1 });
                    }
                    else
                    {
                        queue.push_back({ i ,j + 1 });
                    }
                }
            }

        }

        int minCost(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            std::deque<std::array<int, 2>> queue;
            std::vector<std::vector<int>> distances;
            distances.resize(m);
            for (auto& col : distances)
            {
                col.resize(n,INT_MAX);
            }

            distances[0][0] = 0;
            queue.push_front({ 0,0 });

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
                    push(grid, queue, distances,x,y);
                }

            }

            return -1;
        }
    };
}