// 使数组K递增的最少操作次数
// 给你一个下标从0开始包含n个正整数的数组arr，和一个正整数k
// 如果对于每个满足 k <= i <= n-1 的下标 i
// 都有 arr[i-k] <= arr[i] ，那么称 arr 是K递增的
// 每一次操作中，你可以选择一个下标i并将arr[i]改成任意正整数
// 请你返回对于给定的 k ，使数组变成K递增的最少操作次数
// 测试链接 : https://leetcode.cn/problems/minimum-operations-to-make-the-array-k-increasing/

#include<vector>
namespace
{
    class Solution {
    public:
		int lengthOfLIS(std::vector<int>& nums, int n) {
			if (n == 1)
			{
				return 1;
			}
			std::vector<int> ends(n);
			int endsSize = 1;
			ends[0] = nums[0];
			int l, r;
			for (int i = 1; i < n; i++)
			{
				l = 0;
				r = endsSize - 1;
				int pos = endsSize - 1;
				if (nums[i] >= ends[endsSize - 1])
				{
					ends[endsSize++] = nums[i];
				}
				else
				{
					//二分
					while (l <= r)
					{
						int middle = l + ((r - l) >> 1);
						if (ends[middle] > nums[i])
						{
							r = middle - 1;
							pos = middle;
						}
						else
						{
							l = middle + 1;
						}
					}
					ends[pos] = nums[i];
				}
			}
			return endsSize;
		}

        int kIncreasing(std::vector<int>& arr, int k) {
            int ans = 0;
			int n = arr.size();
			std::vector<int> dp(n);
            for (int i = 0; i < k; i++)
            {
				int j = i;
				int index = 0;
				while (j < n)
				{
					dp[index++] = arr[j];
					j += k;
				}
				int lis = lengthOfLIS(dp,index);
				ans += index - lis;
            }
            return ans;
        }
    };
}