// 多边形三角剖分的最低得分
// 你有一个凸的 n 边形，其每个顶点都有一个整数值
// 给定一个整数数组values，其中values[i]是第i个顶点的值(顺时针顺序)
// 假设将多边形 剖分 为 n - 2 个三角形
// 对于每个三角形，该三角形的值是顶点标记的乘积
// 三角剖分的分数是进行三角剖分后所有 n - 2 个三角形的值之和
// 返回 多边形进行三角剖分后可以得到的最低分
// 测试链接 : https://leetcode.cn/problems/minimum-score-triangulation-of-polygon/

#include<vector>
namespace
{
	using std::vector;
	class Solution {
	public:
		int minScoreTriangulation(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>> dp(n, vector<int>(n));
			for (int l = 0; l < n - 2; l++)
			{
				dp[l][l + 2] = nums[l] * nums[l + 1] * nums[l + 2];
			}

			for (int l = n - 4; l >= 0; l--)
			{
				for (int r = l + 3; r < n; r++)
				{
					int ans = INT_MAX;
					for (int i = l + 1; i < r; i++)
					{
						int curAns = dp[l][i] + dp[i][r] + nums[l] * nums[r] * nums[i];
						ans = std::min(ans, curAns);
					}
					dp[l][r] = ans;
				}
			}
			return dp[0][n - 1];


		}
	};
}