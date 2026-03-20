//À¨ºÅÉú³É
//https://leetcode.cn/problems/generate-parentheses/description/?envType=study-plan-v2&envId=top-100-liked
#include<vector>
#include<string>

namespace
{
	class Solution {
	public:
		std::vector<std::string> ans;

		void f(int i, int cnt, std::string& path, int n, int rest)
		{
			if (i == n)
			{
				ans.push_back(path);
				return;
			}

			if (rest > 0)
			{
				path.push_back('(');
				f(i + 1, cnt + 1, path, n, rest-1);
				path.pop_back();
			}

			if (cnt > 0)
			{
				path.push_back(')');
				f(i + 1, cnt - 1, path, n, rest);
				path.pop_back();
			}
		}

		std::vector<std::string> generateParenthesis(int n) {
			n = n << 1;
			ans.clear();
			std::string path;
			f(0, 0, path, n, n/2);
			return ans;
		}
	};

	class Solution {
	public:
		std::vector<std::vector<int>> ans;

		void f(std::vector<int>& nums, std::vector<int>& path, int i, int status)
		{
			if (i == nums.size())
			{
				ans.push_back(path);
				return;
			}

			for (int j = 0; j < nums.size(); j++)
			{
				if (((1 << j) & status) != 0)
				{
					path.push_back(nums[j]);
					f(nums, path, i + 1, (1 << j) ^ status);
					path.pop_back();
				}
			}

		}

		std::vector<std::vector<int>> permute(std::vector<int>& nums) {
			std::vector<int> path;
			ans.clear();
			int n = nums.size();
			int status = (1 << n) - 1;
			f(nums, path, 0, status);
			return ans;
		}
	};
}