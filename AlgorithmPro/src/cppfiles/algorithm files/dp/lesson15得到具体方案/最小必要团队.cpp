// 最小的必要团队
// 作为项目经理，你规划了一份需求的技能清单req_skills
// 并打算从备选人员名单people中选出些人组成必要团队
// 编号为i的备选人员people[i]含有一份该备选人员掌握的技能列表
// 所谓必要团队，就是在这个团队中
// 对于所需求的技能列表req_skills中列出的每项技能，团队中至少有一名成员已经掌握
// 请你返回规模最小的必要团队，团队成员用人员编号表示
// 你可以按 任意顺序 返回答案，题目数据保证答案存在
// 测试链接 : https://leetcode.cn/problems/smallest-sufficient-team/
#include<unordered_map>
#include<vector>
#include<string>
namespace
{
	class Solution {
	public:

		int f(int n, int m, int s, int i, std::vector<int>& status, std::vector<std::vector<int>>& dp)
		{
			if (s == (1 << m) - 1)
			{
				return 0;
			}

			if (i == n)
			{
				return INT_MAX;
			}

			if (dp[s][i] != -1)
			{
				return dp[s][i];
			}

			int p1 = f(n, m, s, i + 1, status, dp);
			int p2 = f(n, m, s | status[i], i + 1, status, dp);
			p2 = p2 == INT_MAX ? INT_MAX : p2 + 1;
			int ans = std::min(p1, p2);
			dp[s][i] = ans;
			return ans;
		}

		std::vector<int> smallestSufficientTeam(std::vector<std::string>& req_skills, std::vector<std::vector<std::string>>& people) {

			std::unordered_map<std::string, int> map;
			int n = people.size();
			std::vector<int> status(n);
			int m = req_skills.size();
			//把必要的技能编号，放入哈希表
			for (int i = 0; i < m; i++)
			{
				map[req_skills[i]] = i;
			}

			//根据前面的编号，用一个int表示一个人的技能掌握情况，比如00110就表示这个人会编号为1和2的技能
			//使用哈希表快速查询，如果一个人掌握了必要技能以外的技能，那这个技能是废的，不需要考虑
			for (int i = 0;i<n;i++)
			{
				for (std::string skill : people[i])
				{
					if (map.contains(skill))
					{
						int id = map[skill];
						status[i] |= (1 << id);
					}
				}
			}

			//状态转移很简单，就是要当前技能和不要，选择好的那一项
			std::vector<std::vector<int>> dp((1 << m), std::vector<int>(n+1, -1));
			f(n, m, 0, 0, status, dp);
			int i = 0;
			int j = 0;
			std::vector<int> ans;
			while (i != ((1 << m) - 1))
			{
				if (dp[i][j] == dp[i][j + 1])
				{
					j++;
				}
				else
				{
					i |= status[j];
					ans.push_back(j);
					j++;
				}
			}
			return ans;
		}
	};
}