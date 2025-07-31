// 同时运行N台电脑的最长时间
// 你有 n 台电脑。给你整数 n 和一个下标从 0 开始的整数数组 batteries
// 其中第 i 个电池可以让一台电脑 运行 batteries[i] 分钟
// 你想使用这些电池让 全部 n 台电脑 同时 运行。
// 一开始，你可以给每台电脑连接 至多一个电池
// 然后在任意整数时刻，你都可以将一台电脑与它的电池断开连接，并连接另一个电池，你可以进行这个操作 任意次
// 新连接的电池可以是一个全新的电池，也可以是别的电脑用过的电池
// 断开连接和连接新的电池不会花费任何时间。
// 注意，你不能给电池充电。
// 请你返回你可以让 n 台电脑同时运行的 最长 分钟数。
// 测试链接 : https://leetcode.cn/problems/maximum-running-time-of-n-computers/
#include<vector>
namespace
{
	class Solution {
		using LL = long long;
	public:
		bool f(std::vector<int>& batteries, LL limit, LL sum, int n)
		{
			for (int num : batteries)
			{
				if (num > limit)
				{
					sum -= num;
					n--;
				}
			}

			if (sum >= ((LL)n * limit))
			{
				return true;  
			}
			else
			{
				return false;
			}

		}

		LL maxRunTime(int n, std::vector<int>& batteries) {
			LL l = 0;
			LL r = 0;
			LL m = 0;
			LL ans = 0;
			for (int num : batteries)
			{
				r += num;
			}

			LL sum = r;

			while (l <= r)
			{
				m = l + ((r - l) >> 1);
				if (f(batteries, m,sum,n))
				{
					ans = m;
					l = m + 1;
				}
				else
				{
					r = m - 1;
				}
			}

			return ans;
		}
	};
}