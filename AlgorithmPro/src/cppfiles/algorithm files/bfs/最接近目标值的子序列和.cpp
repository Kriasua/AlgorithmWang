// 最接近目标值的子序列和
// 给你一个整数数组 nums 和一个目标值 goal
// 你需要从 nums 中选出一个子序列，使子序列元素总和最接近 goal
// 也就是说，如果子序列元素和为 sum ，你需要 最小化绝对差 abs(sum - goal)
// 返回 abs(sum - goal) 可能的 最小值
// 注意，数组的子序列是通过移除原始数组中的某些元素（可能全部或无）而形成的数组。
// 数据量描述:
// 1 <= nums.length <= 40
// -10^7 <= nums[i] <= 10^7
// -10^9 <= goal <= 10^9
// 测试链接 : https://leetcode.cn/problems/closest-subsequence-sum/

#include<vector>
#include<algorithm>
class Solution {
public:
	using LL = long long int;
	int MAXM = 1 << 20;
	std::vector<int> lsum;
	std::vector<int> rsum;

	int dfs(std::vector<int>& nums, int sum, std::vector<int>& sumArr, int cnt, int i, int e)
	{
		if (i == e)
		{
			sumArr[cnt++] = sum;
		}
		else
		{
			cnt = dfs(nums, sum, sumArr, cnt, i + 1, e);
			cnt = dfs(nums, sum + nums[i], sumArr, cnt, i + 1, e);
		}
		return cnt;
	}

	int dfsOptimized(std::vector<int>& nums, int sum, std::vector<int>& sumArr, int cnt, int i, int e)
	{
		if (i == e)
		{
			sumArr[cnt++] = sum;
			return cnt;
		}
		
		int cur = i;
		while (cur+1 < e && nums[cur + 1] == nums[cur])
		{
			cur++;
		}

		for (int j = 0; j <= cur - i + 1; j++)
		{
			cnt = dfsOptimized(nums, sum + j * nums[i], sumArr, cnt, cur + 1, e);
		}
		
		return cnt;
	}


    int minAbsDifference(std::vector<int>& nums, int goal) {
		int n = nums.size();
		lsum.resize(MAXM);
		rsum.resize(MAXM);
		LL max = 0;
		LL min = 0;

		for (int num : nums)
		{
			if (num > 0)
			{
				max += num;
			}
			else
			{
				min += num;
			}
		}

		if (max < goal)
		{
			return goal - max;
		}

		if (min > goal)
		{
			return min - goal;
		}
		std::sort(nums.begin(), nums.end());
		int middle = n >> 1;
		int cnt = 0;

		int lsize = dfs(nums, 0, lsum, 0, 0, middle);
		int rsize = dfs(nums, 0, rsum, 0, middle, n);
		std::sort(lsum.begin(), lsum.begin() + lsize);
		std::sort(rsum.begin(), rsum.begin() + rsize);

		int ans = INT_MAX;
		for (int i = 0,r = rsize-1; i < lsize; i++)
		{
			while (r > 0 && (std::abs(lsum[i] + rsum[r] - goal)
				>= std::abs(lsum[i] + rsum[r - 1] - goal)))
			{
				r--;
			}

			ans = std::min(ans, std::abs(lsum[i] + rsum[r] - goal));
		}

		return ans;

    }
};