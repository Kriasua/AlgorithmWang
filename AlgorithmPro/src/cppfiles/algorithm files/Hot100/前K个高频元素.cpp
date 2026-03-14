//前K个高频元素
//https://leetcode.cn/problems/top-k-frequent-elements/?envType=study-plan-v2&envId=top-100-liked
#include<unordered_map>
#include<queue>
#include<vector>

namespace
{
	class Solution {
	public:
		struct cmp {
			bool operator()(const std::vector<int>& a, const std::vector<int>& b) {
				return a[1] < b[1];
			}
		};

		std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
			std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, cmp> heap;
			std::vector<int> ans;
			std::unordered_map<int, int> map;

			for (int num : nums)
			{
				map[num]++;
			}

			for (auto pair : map)
			{
				heap.emplace(std::vector<int>{pair.first, pair.second});
			}

			for (int i = 0; i < k; i++)
			{
				ans.push_back(heap.top()[0]);
				heap.pop();
			}
			return ans;
		}
	};
}