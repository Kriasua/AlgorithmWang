// 非负数组前k个最小的子序列累加和
// 给定一个数组nums，含有n个数字，都是非负数
// 给定一个正数k，返回所有子序列中累加和最小的前k个累加和
// 子序列是包含空集的
// 1 <= n <= 10^5
// 1 <= nums[i] <= 10^6
// 1 <= k <= 10^5
// 注意这个数据量，用01背包的解法是不行的，时间复杂度太高了
// 对数器验证

#include<queue>
#include<vector>
#include<algorithm>
#include<array>
#include<iostream>
namespace
{
	struct compare
	{
		bool operator()(std::array<int, 2>& a, std::array<int, 2>& b)
		{
			return a[1] > b[1];
		}
	};
	//准备小根堆
	std::priority_queue<std::array<int,2>, std::vector<std::array<int, 2>>, compare> heap;

	std::vector<int> topKSum(std::vector<int>& nums, int k)
	{
		//换一张新的小根堆
		std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, compare> tmp;
		std::swap(heap, tmp);

		std::sort(nums.begin(), nums.end());
		int index = 0;
		std::vector<int> ans(k--);
		ans[index++] = 0;
		std::array<int, 2> item = { 0,nums[0] };
		heap.push(item);
		while (!heap.empty() && k > 0)
		{
			auto top = heap.top();
			heap.pop();
			ans[index++] = top[1];
			k--;
			int mostRight = top[0];
			if (mostRight < nums.size() - 1)
			{

				//根据弹出的堆顶，有两种入堆策略：
				//1.直接加后面的数，入堆
				//2.把当前最右的数替换成后面的数
				//本质上就是构造所有的组合
				auto add1 = top;
				auto add2 = top;
				add1[0] =mostRight + 1;
				add1[1] += nums[mostRight + 1];
				heap.push(add1);

				add2[0] = mostRight + 1;
				add2[1] -= nums[mostRight];
				add2[1] += nums[mostRight + 1];
				heap.push(add2);
			}
		}

		return ans;
	}
}

