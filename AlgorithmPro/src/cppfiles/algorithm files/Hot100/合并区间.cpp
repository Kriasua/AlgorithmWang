//合并区间
//https://leetcode.cn/problems/merge-intervals/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
#include<algorithm>
namespace
{
	using std::vector;
	class Solution {
	public:
		vector<vector<int>> merge(vector<vector<int>>& intervals) {
			vector<vector<int>> ans;
			std::sort(intervals.begin(), intervals.end(), [](auto& a, auto& b)
				{
					return a[0] < b[0];
				});

			int n = intervals.size();
			int left = intervals[0][0];
			int right = intervals[0][1];
			for (int i = 1; i < n; i++)
			{
				if (right < intervals[i][0])
				{
					ans.push_back({ left,right });
					left = intervals[i][0];
					right = intervals[i][1];
				}
				else
				{
					if (right < intervals[i][1])
					{
						right = intervals[i][1];
					}
				}
			}
			ans.push_back({ left,right });
			return ans;
		}
	};
}