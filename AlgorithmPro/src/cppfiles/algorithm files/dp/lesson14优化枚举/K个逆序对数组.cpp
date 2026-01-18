// K个逆序对数组
// 逆序对的定义如下：
// 对于数组nums的第i个和第j个元素
// 如果满足0<=i<j<nums.length 且 nums[i]>nums[j]，则为一个逆序对
// 给你两个整数n和k，找出所有包含从1到n的数字
// 且恰好拥有k个逆序对的不同的数组的个数
// 由于答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/k-inverse-pairs-array/

#include<vector>
#include<iostream>
namespace
{
	static bool calculated = false;
	static std::vector<std::vector<int>> dp;
	class Solution {
	public:
		const int MAXN = 1001;
		void f()
		{
			dp.resize(MAXN, std::vector<int>(MAXN));
			const int mod = 1000000007;
			dp[1][0] = 1;
			dp[2][0] = 1;
			dp[2][1] = 1;
			for (int i = 3; i <= 1000; i++)
			{
				dp[i][0] = dp[i - 1][0];
				//edge表示i个数最多只能组成这么多个对，多于edge就没有意义了
				int edge = i * (i - 1) / 2;
				edge = std::min(edge, 1000);
				for (int j = 1; j <= edge; j++)
				{
					if (i > j)
					{
						dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] % mod) % mod;
					}
					else
					{

						dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] % mod) % mod;
						dp[i][j] = ((dp[i][j] + mod) - dp[i - 1][j - i]) % mod;
					}
				}
			}
			calculated = true;
		}

		int kInversePairs(int n, int k) {
			if (!calculated)
			{
				f();
			}
			return dp[n][k];
		}
	};
}
