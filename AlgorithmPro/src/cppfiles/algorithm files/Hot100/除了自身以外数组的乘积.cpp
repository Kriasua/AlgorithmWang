//除了自身以外数组的乘积
//https://leetcode.cn/problems/product-of-array-except-self/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	class Solution {
	public:
		std::vector<int> productExceptSelf(std::vector<int>& nums) {
			int n = nums.size();
			std::vector<int> ans(n);
			std::vector<int> prefix(n + 2, 1);
			std::vector<int> suffix(n + 2, 1);

			for (int i = 1; i <= n; i++)
			{
				prefix[i] = prefix[i - 1] * nums[i - 1];
			}

			for (int i = n; i > 0; i--)
			{
				suffix[i] = suffix[i + 1] * nums[i - 1];
			}

			for (int i = 0; i < n; i++)
			{
				ans[i] = prefix[i] * suffix[i + 2];
			}
			return ans;
		}
	};
}