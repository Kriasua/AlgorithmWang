// 森林中的兔子
// 森林中有未知数量的兔子
// 你问兔子们一个问题: "还有多少只兔子与你颜色相同?"
// 你将答案收集到了一个数组answers中
// 你可能没有收集到所有兔子的回答，可能只是一部分兔子的回答
// 其中answers[i]是第i只兔子的答案
// 所有兔子都不会说错，返回森林中兔子的最少数量
// 测试链接 : https://leetcode.cn/problems/rabbits-in-forest/

#include<vector>
#include<unordered_map>
namespace
{
	class Solution {
	public:
		int numRabbits(std::vector<int>& answers) {
			for (auto& num : answers)
			{
				num++;
			}

			int ans = 0;
			std::unordered_map<int, int> map;
			for (int i = 0; i < answers.size(); i++)
			{
				if (map.contains(answers[i]))
				{
					map[answers[i]]++;
				}
				else
				{
					map.emplace(answers[i], 1);
				}
			}

			for (auto it = map.begin(); it != map.end(); it++)
			{
				ans += ((it->second + (it->first - 1)) / it->first) * it->first;
			}
			return ans;
		}
	};
}