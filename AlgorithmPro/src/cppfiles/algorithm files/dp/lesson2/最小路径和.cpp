// 最小路径和
// 给定一个包含非负整数的 m x n 网格 grid
// 请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。
// 测试链接 : https://leetcode.cn/problems/minimum-path-sum/

#include<queue>
#include<vector>
#include<array>
namespace
{
    //使用dij算法解
    class Solution1 {
    public:

        struct compare
        {
            bool operator()(const std::array<int, 3>& a, const std::array<int, 3>& b)
            {
                return a[2] > b[2];
            }
        };

        int minPathSum(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;
            std::vector<std::vector<int>> distances(m, std::vector<int>(n,INT_MAX));
            std::vector<std::vector<bool>> visited(m);
            for (auto& col : visited)
            {
                col.resize(n, false);
            }

            distances[0][0] = grid[0][0];
            heap.push({ 0, 0, grid[0][0] });

            while (!heap.empty())
            {
                int x = heap.top()[0];
                int y = heap.top()[1];
                int dis = heap.top()[2];

                heap.pop();
                if (visited[x][y])
                {
                    continue;
                }

                if (x == m - 1 && y == n - 1)
                {
                    return dis;
                }

                visited[x][y] = true;
                if (x < m - 1)
                {
                    if (dis + grid[x + 1][y] < distances[x + 1][y])
                    {
                        distances[x + 1][y] = dis + grid[x + 1][y];
                        heap.push({ x + 1,y,distances[x + 1][y] });
                    }

                }

                if (y < n - 1)
                {
                    if (dis + grid[x][y + 1] < distances[x][y + 1])
                    {
                        distances[x][y + 1] = dis + grid[x][y + 1];
                        heap.push({ x,y+1,distances[x][y+1] });
                    }
                }
            }
            return -1;
        }
    };

    //暴力递归法
    class Solution2 {
    public:

        //从(x,y)这个点出发，到右下角的最短路径和
        int f(std::vector<std::vector<int>>& grid, int x, int y)
        {
            //两个basecase : 到了右下角和越界
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
            {
                return grid[x][y];
            }

            if (x == grid.size() || y == grid[0].size())
            {
                return INT_MAX;
            }

            int right = f(grid, x, y + 1);
            int left = f(grid, x + 1, y);

            return grid[x][y] + std::min(right, left);
        }

        int minPathSum(std::vector<std::vector<int>>& grid) {
            return f(grid, 0, 0);
        }
    };

    //记忆化搜索法
    class Solution3 {
    public:

        //从(x,y)这个点出发，到右下角的最短路径和
        int f(std::vector<std::vector<int>>& grid, int x, int y, std::vector<std::vector<int>>& dp)
        {
            //两个basecase : 到了右下角和越界
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
            {
                return grid[x][y];
            }

            if (x == grid.size() || y == grid[0].size())
            {
                return INT_MAX;
            }

            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }

            int right = f(grid, x, y + 1,dp);
            int left = f(grid, x + 1, y,dp);
            int ans = grid[x][y] + std::min(right, left);
            dp[x][y] = ans;
            return ans;
        }

        int minPathSum(std::vector<std::vector<int>>& grid) {
            std::vector<std::vector<int>> dp(grid.size(), std::vector<int>(grid[0].size(), -1));
            return f(grid, 0, 0, dp);
        }
    };

    //正宗动态规划法
    class Solution4 {
    public:

        int minPathSum(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            std::vector<std::vector<int>> dp(m, std::vector<int>(n, -1));
            dp[m - 1][n - 1] = grid[m - 1][n - 1];

            //先填最下面一行
            for (int i = n-2; i >= 0; i--)
            {
                dp[m-1][i] = grid[m-1][i] + dp[m-1][i+1];
            }

            //再填最右边一列
            for (int i = m-2; i >=0 ; i--)
            {
                dp[i][n-1] = grid[i][n-1] + dp[i+1][n-1];
            }

            //最后填剩余的表格
            for (int i = m - 2; i >= 0; i--)
            {
                for (int j = n - 2; j >= 0; j--)
                {
                    dp[i][j] = grid[i][j] + std::min(dp[i + 1][j], dp[i][j + 1]);
                }
            }

            return dp[0][0];
        }
    };
}