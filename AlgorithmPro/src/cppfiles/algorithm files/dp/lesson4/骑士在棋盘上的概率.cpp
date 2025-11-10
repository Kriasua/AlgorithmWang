// 骑士在棋盘上的概率
// n * n的国际象棋棋盘上，一个骑士从单元格(row, col)开始，并尝试进行 k 次移动
// 行和列从0开始，所以左上单元格是 (0,0)，右下单元格是 (n-1, n-1)
// 象棋骑士有8种可能的走法。每次移动在基本方向上是两个单元格，然后在正交方向上是一个单元格
// 每次骑士要移动时，它都会随机从8种可能的移动中选择一种，然后移动到那里
// 骑士继续移动，直到它走了 k 步或离开了棋盘
// 返回 骑士在棋盘停止移动后仍留在棋盘上的概率 
// 测试链接 : https://leetcode.cn/problems/knight-probability-in-chessboard/

#include<vector>
namespace
{
    //暴力递归
    class Solution1 {
    public:
        std::vector<std::vector<int>> directions{ {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
        double f(int x, int y, int i, int n)
        {
            if (x < 0 || y < 0 || x > n - 1 || y > n - 1)
            {
                return 0;
            }

            if (i == 0)
            {
                return 1;
            }

            double ans = 0;
            for (const auto& step : directions)
            {
                ans += 0.125 * f(x + step[0], y + step[1], i - 1, n);
            }

            return ans;
        }

        double knightProbability(int n, int k, int row, int column) {
            return f(row, column, k, n);
        }
    };

    //动态规划
    class Solution2 {
    public:
        std::vector<std::vector<int>> directions{ {-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1} };
        double knightProbability(int n, int k, int row, int column) {
            std::vector<std::vector<std::vector<double>>> dp(n + 1, std::vector<std::vector<double>>(n + 1, std::vector<double>(k + 1)));
            for (int i = 0; i <= n; i++)
            {
                for (int j = 0; j <= n; j++)
                {
                    dp[i][j][0] = 1;
                }
            }

            for (int layer = 1; layer <= k; layer++)
            {
                for (int i = 0; i <= n; i++)
                {
                    for (int j = 0; j <= n; j++)
                    {
                        double ans = 0;
                        for (const auto& step : directions)
                        {
                            int newX = i + step[0];
                            int newY = j + step[1];
                            if (newX >= 0 && newY >= 0 && newX <= n - 1 && newY <= n - 1)
                            {
                                ans += 0.125 * dp[newX][newY][layer-1];
                            }
                        }
                        dp[i][j][layer] = ans;
                    }
                }
            }
            return dp[row][column][k];
            
        }
    };
}