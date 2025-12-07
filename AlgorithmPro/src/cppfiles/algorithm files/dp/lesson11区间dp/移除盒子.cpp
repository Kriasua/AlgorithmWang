// 移除盒子
// 给出一些不同颜色的盒子boxes，盒子的颜色由不同的正数表示
// 你将经过若干轮操作去去掉盒子，直到所有的盒子都去掉为止
// 每一轮你可以移除具有相同颜色的连续 k 个盒子（k >= 1）
// 这样一轮之后你将得到 k * k 个积分
// 返回你能获得的最大积分总和
// 测试链接 : https://leetcode.cn/problems/remove-boxes/

#include<vector>
namespace
{
	class Solution {
	public:

		int f(std::vector<int>& boxes, int l, int r, int k, std::vector<std::vector<std::vector<int>>>& dp)
		{
			if (l > r)
			{
				return 0;
			}

			if (dp[l][r][k] != -1)
			{
				return dp[l][r][k];
			}

			int p1 = 0;
			int p2 = 0;
			int s = l;
			while (s < r && boxes[s] == boxes[s+1])
			{
				s++;
			}
			int cnt = s - l + 1 + k;
			p1 = cnt * cnt + f(boxes, s+1, r, 0,dp);
			
			for (int m = s + 2; m <= r; m++)
			{
				if (boxes[m] == boxes[l] && boxes[m-1] != boxes[l])
				{
					p2 = std::max(p2, f(boxes, s + 1, m - 1, 0,dp) + f(boxes, m, r, cnt,dp));
				}
			}

			int ans = std::max(p1, p2);
			dp[l][r][k] = ans;
			return ans;
		}

		int removeBoxes(std::vector<int>& boxes) {
			if (boxes.size() == 1)
			{
				return 1;
			}

			std::vector<std::vector<std::vector<int>>> dp(boxes.size(), std::vector<std::vector<int>>(boxes.size(), std::vector<int>(boxes.size(),-1)));
			return f(boxes, 0, boxes.size() - 1, 0,dp);
		}
	};
}