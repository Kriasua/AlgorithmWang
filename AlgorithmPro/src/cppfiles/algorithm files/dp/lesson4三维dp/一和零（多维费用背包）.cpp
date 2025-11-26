// 一和零(多维费用背包)
// 给你一个二进制字符串数组 strs 和两个整数 m 和 n
// 请你找出并返回 strs 的最大子集的长度
// 该子集中 最多 有 m 个 0 和 n 个 1
// 如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集
// 测试链接 : https://leetcode.cn/problems/ones-and-zeroes/

#include<vector>
#include<string>
namespace
{
    class Solution {
    public:
        int zeros;
        int ones;
        std::pair<int, int> zeroAndOne(std::string str)
        {
            int zeros = 0;
            int ones = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
            }
            return { zeros,ones };
        }

        void zeroAndOne2(const std::string& str)
        {
            zeros = 0;
            ones = 0;
            for (char c : str)
            {
                if (c == '0')
                {
                    zeros++;
                }
                else
                {
                    ones++;
                }
            }

        }

        int findMaxForm(std::vector<std::string>& strs, int m, int n) {
            int size = strs.size();
            std::vector<std::vector<std::vector<int>>> dp(m+1,std::vector<std::vector<int>>(n+1, std::vector<int>(size+1,0)));

            for (int k = 1; k <= size; k++)
            {
                for (int i = 0; i <= m; i++)
                {
                    for (int j = 0; j <= n; j++)
                    {
                        int p1 = dp[i][j][k - 1];
                        //std::pair<int, int> pair = zeroAndOne(strs[k - 1]);
                        zeroAndOne2(strs[k - 1]);
                        int p2 = 0;
                        if (zeros <= i && ones <= j)
                        {
                            p2 = dp[i - zeros][j - ones][k - 1] + 1;
                        }

                        dp[i][j][k] = std::max(p1, p2);
                    }
                }
            }

            return dp[m][n][size];
        }
    };
}