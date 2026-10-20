// 数组的最小偏移量
// 给你一个由n个正整数组成的数组nums
// 你可以对数组的任意元素执行任意次数的两类操作：
// 如果元素是偶数，除以2
// 例如如果数组是[1,2,3,4]
// 那么你可以对最后一个元素执行此操作，使其变成[1,2,3,2]
// 如果元素是奇数，乘上2
// 例如如果数组是[1,2,3,4]
// 那么你可以对第一个元素执行此操作，使其变成[2,2,3,4]
// 数组的偏移量是数组中任意两个元素之间的最大差值
// 返回数组在执行某些操作之后可以拥有的最小偏移量
// 测试链接 : https://leetcode.cn/problems/minimize-deviation-in-array/

#include<vector>
#include<set>
namespace
{
	//暴力解
	class Solution1 {
	public:
		struct node
		{
			int index;
			int val;

			node(int i, int v):index(i), val(v)
			{

			}

			bool operator<(const node& other) const
			{
				if (val != other.val)
				{
					return val < other.val;
				}
				return index < other.index;
			}
		};

		int ans;

		std::vector<int> getCandidates(int num)
		{
			std::vector<int> ans;
			if (num % 2 != 0)
			{
				ans.push_back(num);
				ans.push_back(num * 2);
			}
			else
			{
				while (num % 2 == 0)
				{
					ans.push_back(num);
					num /= 2;
				}
				ans.push_back(num);
			}

			return ans;
		}

		void f(std::set<node>& set, std::vector<int>& nums, int i)
		{
			if (i == nums.size())
			{
				int curAns = set.rbegin()->val - set.begin()->val;
				ans = std::min(ans, curAns);
				return;
			}

			int original = nums[i];
			std::vector<int> candidates = getCandidates(nums[i]);
			for (auto num : candidates)
			{
				set.erase(node(i, nums[i]));
				nums[i] = num;
				set.emplace(i, nums[i]);
				f(set, nums, i + 1);
			}

			set.erase(node(i, nums[i]));
			nums[i] = original;
			set.emplace(i, nums[i]);
		}

		int minimumDeviation(std::vector<int>& nums) {
			ans = 2147483647;
			std::set<node> set;
			for (int i = 0; i < nums.size(); i++)
			{
				set.emplace(i, nums[i]);
			}

			f(set, nums, 0);
			return ans;
		}
	};

	//贪心
	class Solution {
	public:

		struct node
		{
			int index;
			int val;

			node(int i, int v) :index(i), val(v)
			{

			}

			bool operator<(const node& other) const
			{
				if (val != other.val)
				{
					return val < other.val;
				}
				return index < other.index;
			}
		};

		int minimumDeviation(std::vector<int>& nums) {
			std::set<node> set;
			int ans = 2147483647;
			for (int i = 0; i < nums.size(); i++)
			{
				if (nums[i] % 2 != 0)
				{
					nums[i] *= 2;
				}
				set.emplace(i, nums[i]);
			}

			int curAns = set.rbegin()->val - set.begin()->val;
			ans = std::min(ans, curAns);

			while (set.rbegin()->val % 2 == 0)
			{
				node cur = *set.rbegin();
				set.erase(cur);
				cur.val /= 2;
				set.insert(cur);
				curAns = set.rbegin()->val - set.begin()->val;
				ans = std::min(ans, curAns);

			}

			return ans;

		}
	};
}