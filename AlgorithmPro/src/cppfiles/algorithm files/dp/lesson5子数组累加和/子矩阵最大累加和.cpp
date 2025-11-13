// 子矩阵最大累加和问题
// 给定一个二维数组grid，找到其中子矩阵的最大累加和
// 返回拥有最大累加和的子矩阵左上角和右下角坐标
// 如果有多个子矩阵都有最大累加和，返回哪一个都可以
// 测试链接 : https://leetcode.cn/problems/max-submatrix-lcci/

#include<vector>
#include<array>
#include <algorithm>
namespace
{
    class Solution {
    public:
        std::vector<int> getMaxMatrix(std::vector<std::vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();
            int left, right, sum;
            std::vector<std::vector<std::array<int,3>>> dp(n, std::vector<std::array<int, 3>>(n,{0,0,0}));
            std::vector<int> dpAssist(m);
            std::vector<std::pair<int, int>> dpAssistdp(m);
            for (int i = 0; i < n; i++)
            {
                std::fill(dpAssist.begin(), dpAssist.end(), 0);
                for (int j = i; j < n; j++)
                {
                    //数组压缩
                    for (int k = 0; k < m; k++)
                    {
                        dpAssist[k] += matrix[j][k];
                    }
                    dpAssistdp[0] = { 0,dpAssist[0] };

                    for (int k = 1; k < dpAssistdp.size(); k++)
                    {
                        if (dpAssist[k] < dpAssistdp[k - 1].second + dpAssist[k])
                        {
                            dpAssistdp[k] = { dpAssistdp[k - 1].first, dpAssistdp[k - 1].second + dpAssist[k] };
                        }
                        else
                        {
                            dpAssistdp[k] = { k,dpAssist[k] };
                        }
                    }

                    sum = INT_MIN;

                    for (int k = 0; k < dpAssistdp.size(); k++)
                    {
                        if (dpAssistdp[k].second > sum)
                        {
                            sum = dpAssistdp[k].second;
                            right = k;
                            left = dpAssistdp[k].first;
                        }
                    }
                    dp[i][j] = { left,right,sum };
                }
            }

            std::array<int, 3> ans = {0,0,INT_MIN};
            int l1;
            int l2;
            for (int i = 0; i < n; i++)
            {
                for (int j = i; j < n; j++)
                {
                    if (dp[i][j][2] > ans[2])
                    {
                        ans = dp[i][j];
                        l1 = i;
                        l2 = j;
                    }
                }
            }

            std::vector<int> realAns = { l1,ans[0],l2,ans[1] };

            return realAns;
        }
    };
}