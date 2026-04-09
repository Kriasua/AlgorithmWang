// 吃掉N个橘子的最少天数
// 厨房里总共有 n 个橘子，你决定每一天选择如下方式之一吃这些橘子
// 1）吃掉一个橘子
// 2) 如果剩余橘子数 n 能被 2 整除，那么你可以吃掉 n/2 个橘子
// 3) 如果剩余橘子数 n 能被 3 整除，那么你可以吃掉 2*(n/3) 个橘子
// 每天你只能从以上 3 种方案中选择一种方案
// 请你返回吃掉所有 n 个橘子的最少天数
// 测试链接 : https://leetcode.cn/problems/minimum-number-of-days-to-eat-n-oranges/

#include<vector>
#include<unordered_map>

namespace 
{
	class Solution {
	public:
		int f(int n, std::unordered_map<int, int>& map)
		{
			if (n <= 1)
			{
				return 1;
			}

			if (map.contains(n))
			{
				return map[n];
			}

			int p1 = INT_MAX;
			int p2 = INT_MAX;

			int a = n % 2;
			int b = n % 3;
			
			p1 = a + f((n - a) / 2, map) + 1;
			p2 = b + f((n - b) / 3, map) + 1;
			

			int ans = std::min(p1, p2);
			map[n] = ans;
			return ans;
		}

		int minDays(int n) {
			std::unordered_map<int, int> map;
			return f(n, map);
		}
	};
}