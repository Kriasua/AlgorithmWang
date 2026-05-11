// 最小区间
// 你有k个非递减排列的整数列表
// 找到一个最小区间，使得k个列表中的每个列表至少有一个数包含在其中
// 测试链接 : https://leetcode.cn/problems/smallest-range-covering-elements-from-k-lists/

#include<vector>
#include<set>

namespace
{
	using std::vector;
	class Solution {
	public:
		struct node
		{
			int v;
			int i;
			int j;

			node(int val, int iii, int jjj) : v(val), i(iii), j(jjj)
			{

			}

			bool operator<(const node& other) const
			{
				if (v != other.v) return v < other.v;
				return i < other.i;
			}
		};

		vector<int> smallestRange(vector<vector<int>>& nums) {
			std::set<node> set;
			for (int i = 0; i < nums.size(); i++)
			{
				set.emplace(nums[i][0], i, 0);
			}

			std::vector<int> ans = { set.begin()->v,set.rbegin()->v };
			int topi = set.begin()->i;
			int topj = set.begin()->j + 1;
			while (topj < nums[topi].size())
			{
				set.erase(set.begin());
				set.emplace(nums[topi][topj], topi, topj);
				if ((set.rbegin()->v - set.begin()->v) < (ans[1] - ans[0]))
				{
					ans = { set.begin()->v,set.rbegin()->v };
				}
				topi = set.begin()->i;
				topj = set.begin()->j + 1;
			}

			return ans;
		}
	};
}