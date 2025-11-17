// 删掉1个数字后长度为k的子数组最大累加和
// 给定一个数组nums，求必须删除一个数字后的新数组中
// 长度为k的子数组最大累加和，删除哪个数字随意

#include<vector>
namespace
{
	int l = 0;
	int r = 0;
	std::vector<int> queue;
	std::vector<int> numCopy;

	void addNum(int num)
	{
		while (l < r && numCopy[num] <= numCopy[queue[r - 1]])
		{
			r--;
		}

		queue[r++] = num;
	}

	void popNum(int num)
	{
		if (num == queue[l])
		{
			l++;
		}
	}


	int delete1numKLenMaxSubArrSum(std::vector<int>& nums, int k)
	{
		l = 0;
		r = 0;
		int ans = INT_MIN;
		int n = nums.size() - k;
		queue.resize(nums.size());
		numCopy = nums;

		int sum = 0;
		for (int i = 0; i < k; i++)
		{
			addNum(i);
			sum += nums[i];
		}

		for (int i = 0; i < n; i++)
		{
			
			addNum(i + k);
			sum += nums[i + k];
			ans = std::max(ans, sum - nums[queue[l]]);
			popNum(i);
			sum -= nums[i];
		}

		return ans;
	}
}