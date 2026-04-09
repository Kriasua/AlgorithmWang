// 连接棒材的最低费用(leetcode测试)
// 你有一些长度为正整数的棍子
// 这些长度以数组sticks的形式给出
// sticks[i]是第i个木棍的长度
// 你可以通过支付x+y的成本将任意两个长度为x和y的棍子连接成一个棍子
// 你必须连接所有的棍子，直到剩下一个棍子
// 返回以这种方式将所有给定的棍子连接成一个棍子的最小成本
// 测试链接 : https://leetcode.cn/problems/minimum-cost-to-connect-sticks/

#include<vector>
#include<queue>
namespace 
{
	class Solution {
	public:
		int connectSticks(std::vector<int>& sticks) {
			std::priority_queue<int, std::vector<int>, std::greater<int>> heap;
			for (int num : sticks)
			{
				heap.push(num);
			}

			int ans = 0;
			while (heap.size() > 1)
			{
				int p1 = heap.top();
				heap.pop();
				int p2 = heap.top();
				heap.pop();
				ans += p1 + p2;
				heap.push(p1 + p2);
			}
			return ans;
		}
	};
}

int main()
{
	std::vector<int> nums = { 2,4,3 };
	Solution sol;
	int cost = sol.connectSticks(nums);
	int a = 2;
}