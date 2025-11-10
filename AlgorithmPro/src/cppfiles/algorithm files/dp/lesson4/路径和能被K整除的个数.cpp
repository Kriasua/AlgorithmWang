// 矩阵中和能被 K 整除的路径
// 给一个下标从0开始的 n * m 整数矩阵 grid 和一个整数 k
// 从起点(0,0)出发，每步只能往下或者往右，你想要到达终点(m-1, n-1)
// 请你返回路径和能被 k 整除的路径数目
// 答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/paths-in-matrix-whose-sum-is-divisible-by-k/

#include<vector>
namespace
{
    //暴力递归
    class Solution1 {
    public:
        const int mod = 1000000007;

        int f(std::vector<std::vector<int>>& grid, int k, int x, int y, int yu)
        {
            //越界
            if (x == grid.size() || y == grid[0].size())
            {
                return 0;
            }

            //到了右下角，并且之前做的选择的和能被k整除
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
            {
                if (grid[x][y] % k == yu)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

            int need = yu + k - (grid[x][y] % k);

            int p1 = f(grid, k, x + 1, y, need);
            int p2 = f(grid, k, x, y + 1, need);
            return (p1 % mod + p2 % mod) % mod;
        }

        int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
            
            return f(grid, k, 0, 0, 0);
        }
    };

    //记忆化搜索
    class Solution2 {
    public:
        const int mod = 1000000007;

        int f(std::vector<std::vector<int>>& grid, int k, int x, int y, int yu, std::vector<std::vector<std::vector<int>>>& dp)
        {
            //越界
            if (x == grid.size() || y == grid[0].size())
            {
                return 0;
            }

            //到了右下角，并且之前做的选择的和能被k整除
            if (x == grid.size() - 1 && y == grid[0].size() - 1)
            {
                if (grid[x][y] % k == yu)
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }

            if (dp[x][y][yu] != -1)
            {
                return dp[x][y][yu];
            }

            int need = (yu + k - (grid[x][y] % k))%k;

            int p1 = f(grid, k, x + 1, y, need,dp);
            int p2 = f(grid, k, x, y + 1, need,dp);
            int ans = (p1 % mod + p2 % mod) % mod;
            dp[x][y][yu] = ans;
            return ans;
        }

        int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
            int n = grid.size();
            int m = grid[0].size();
            std::vector<std::vector<std::vector<int>>> dp(n, std::vector<std::vector<int>>(m, std::vector<int>(k + 1,-1)));

            return f(grid, k, 0, 0, 0,dp);
        }
    };

    //动态规划
    class Solution3 {
    public:
        const int mod = 1000000007;

        int numberOfPaths(std::vector<std::vector<int>>& grid, int k) {
            int n = grid.size();
            int m = grid[0].size();
            std::vector<std::vector<std::vector<int>>> dp(n+1, std::vector<std::vector<int>>(m+1, std::vector<int>(k + 1)));

            //填dp[n-1][m-1]那一列
            for (int i = 0; i <= k; i++)
            {
                if (grid[n-1][m-1] % k == i)
                {
                    dp[n - 1][m - 1][i] = 1;
                }
                else
                {
                    dp[n - 1][m - 1][i] = 0;
                }
            }


            for (int i = m - 2; i >= 0; i--)
            {
                for (int j = 0; j <= k; j++)
                {
                    int need = (j + k - (grid[n-1][i] % k)) % k;

                    int p1 = dp[n][i][need];
                    int p2 = dp[n-1][i+1][need];
                    int ans = (p1 % mod + p2 % mod) % mod;
                    dp[n-1][i][j] = ans;
                }
            }

            for (int i = n - 2; i >= 0; i--)
            {
                for (int j = m - 1; j >= 0; j--)
                {
                    for (int layer = 0; layer <= k; layer++)
                    {
                        int need = (layer + k - (grid[i][j] % k)) % k;

                        int p1 = dp[i+1][j][need];
                        int p2 = dp[i][j + 1][need];
                        int ans = (p1 % mod + p2 % mod) % mod;
                        dp[i][j][layer] = ans;
                    }
                }
            }
            return dp[0][0][0];
        }
    };
}