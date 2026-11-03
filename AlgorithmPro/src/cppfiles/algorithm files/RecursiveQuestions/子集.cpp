//https://leetcode.cn/problems/subsets/
#include<vector>
using std::vector;

class Solution {
public:
	void f(vector<vector<int>>& ans, vector<int>& path, vector<int>& nums, int i)
	{
		if (i == nums.size())
		{
			ans.push_back(path);
			return;
		}

		f(ans, path, nums, i + 1);

		path.push_back(nums[i]);
		f(ans, path, nums, i + 1);
		path.pop_back();
	}

	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> path;
		f(ans, path, nums, 0);
		return ans;
	}
};