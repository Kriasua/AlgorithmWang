// 预测赢家
// 给你一个整数数组 nums 。玩家 1 和玩家 2 基于这个数组设计了一个游戏
// 玩家 1 和玩家 2 轮流进行自己的回合，玩家 1 先手
// 开始时，两个玩家的初始分值都是 0
// 每一回合，玩家从数组的任意一端取一个数字
// 取到的数字将会从数组中移除，数组长度减1
// 玩家选中的数字将会加到他的得分上
// 当数组中没有剩余数字可取时游戏结束
// 如果玩家 1 能成为赢家，返回 true
// 如果两个玩家得分相等，同样认为玩家 1 是游戏的赢家，也返回 true
// 你可以假设每个玩家的玩法都会使他的分数最大化
// 测试链接 : https://leetcode.cn/problems/predict-the-winner/

#include<vector>
namespace
{
	using std::vector;
	class Solution {
	public:
		bool predictTheWinner(vector<int>& nums) {
			int n = nums.size();
			vector<vector<int>> dp(n, vector<int>(n));
			for (int l = n - 1; l >= 0; l--)
			{
				for (int r = l; r < n; r++)
				{
					if (l == r)
					{
						dp[l][r] = nums[l];
					}
					else
					{
						int p1 = nums[l] - dp[l + 1][r];
						int p2 = nums[r] - dp[l][r - 1];
						dp[l][r] = std::max(p1, p2);
					}
				}
			}

			return dp[0][n - 1] >= 0;
		}
	};
}