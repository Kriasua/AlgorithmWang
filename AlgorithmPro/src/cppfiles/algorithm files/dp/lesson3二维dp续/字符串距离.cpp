// 编辑距离
// 给你两个单词 word1 和 word2
// 请返回将 word1 转换成 word2 所使用的最少代价
// 你可以对一个单词进行如下三种操作：
// 插入一个字符，代价a
// 删除一个字符，代价b
// 替换一个字符，代价c
// 测试链接 : https://leetcode.cn/problems/edit-distance/

#include<vector>
#include<string>

namespace
{
    class Solution2 {
    public:
        int minDistance(std::string word1, std::string word2) {
            int n = word1.size();
            int m = word2.size();
            std::vector<std::vector<int>> dp(n + 1, std::vector<int>(m + 1));
            for (int i = 1; i <= n; i++)
            {
                dp[i][0] = i;
            }

            for (int i = 1; i <= m; i++)
            {
                dp[0][i] = i;
            }

            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= m; j++)
                {
                    //第一种情况，直接相等
                    if (word1[i-1] == word2[j-1])
                    {
                        dp[i][j] = dp[i-1][j-1];
                    }
                    else
                    {
                        //替换
                        int p1 = dp[i - 1][j - 1] + 1;

                        //删除
                        int p2 = dp[i - 1][j] + 1;

                        //添加
                        int p3 = dp[i][j - 1] + 1;
                        dp[i][j] = std::min(p2, std::min(p3, p1));
                    }

                }
            }
            return dp[n][m];
        }
    };

}