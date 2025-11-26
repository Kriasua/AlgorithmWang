// 矩阵中的最长递增路径
// 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度
// 对于每个单元格，你可以往上，下，左，右四个方向移动
// 你 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）
// 测试链接 : https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/

#include<vector>
namespace
{
    //暴力递归
    class Solution1 {
    public:
        int f(std::vector<std::vector<int>>& matrix, int x, int y, int last)
        {
            //越界
            if (x == matrix.size() || y == matrix[0].size() || x < 0 || y < 0)
            {
                return 0;
            }

            //不是一个递增路径
            if (matrix[x][y] <= last)
            {
                return 0;
            }

            
            int p1 = f(matrix,x-1,y, matrix[x][y]);
            int p2 = f(matrix, x + 1, y, matrix[x][y]);
            int p3 = f(matrix, x, y-1, matrix[x][y]);
            int p4 = f(matrix, x, y + 1, matrix[x][y]);

            int ans = std::max(std::max(p1, p2), std::max(p3, p4)) + 1;

            return ans;
        }

        int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
            int ans = 0;
            int n = matrix.size();
            int m = matrix[0].size();
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    ans = std::max(ans,f(matrix, i, j, -1));
                }
            }
            return ans;
        }
    };

    //记忆化搜索
    class Solution2 {
    public:
        int f(std::vector<std::vector<int>>& matrix, int x, int y, int last, std::vector<std::vector<int>>& dp)
        {
            //越界
            if (x == matrix.size() || y == matrix[0].size() || x < 0 || y < 0)
            {
                return 0;
            }

            //不是一个递增路径
            if (matrix[x][y] <= last)
            {
                return 0;
            }

            if (dp[x][y] != -1)
            {
                return dp[x][y];
            }

            int p1 = f(matrix, x - 1, y, matrix[x][y],dp);
            int p2 = f(matrix, x + 1, y, matrix[x][y],dp);
            int p3 = f(matrix, x, y - 1, matrix[x][y],dp);
            int p4 = f(matrix, x, y + 1, matrix[x][y],dp);

            int ans = std::max(std::max(p1, p2), std::max(p3, p4)) + 1;
            dp[x][y] = ans;
            return ans;
        }

        int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
            int ans = 0;
            int n = matrix.size();
            int m = matrix[0].size();
            std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    ans = std::max(ans, f(matrix, i, j, -1,dp));
                }
            }
            return ans;
        }
    };
}