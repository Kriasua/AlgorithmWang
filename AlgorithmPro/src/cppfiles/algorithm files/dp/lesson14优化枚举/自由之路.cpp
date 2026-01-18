// 自由之路
// 题目描述比较多，打开链接查看
// 测试链接 : https://leetcode.cn/problems/freedom-trail/

#include<vector>
#include<string>
#include<unordered_map>
namespace
{
	//使用哈希表，遍历所有key[j]的字符
	class Solution1 {
	public:
		int findRotateSteps(std::string ring, std::string key) {
			int n = ring.size();
			int m = key.size();
			std::unordered_map<char, std::vector<int>> map;
			for (int i = 0; i < n; i++)
			{
				map[ring[i]].push_back(i);
			}

			std::vector<std::vector<int>> dp(n, std::vector<int>(m));
			char last = key[m-1];
			for (int i = 0; i < n; i++)
			{
				int ans = INT_MAX;
				for (int pos : map[last])
				{
					ans = std::min(ans, std::abs(i-pos));
					ans = std::min(ans, std::abs(i + n - pos));
					ans = std::min(ans, std::abs(i - n - pos));
				}
				ans++;
				dp[i][m - 1] = ans;
			}

			for (int j = m - 2; j >= 0; j--)
			{
				char target = key[j];
				for (int i = 0; i < n; i++)
				{
					int ans = INT_MAX;
					for (int pos : map[target])
					{
						int dis = std::min(std::abs(i - pos), std::abs(i + n - pos));
						dis = std::min(dis, std::abs(i - n - pos));
						ans = std::min(dis + 1 + dp[pos][j + 1], ans);
					}
					dp[i][j] = ans;
				}
			}
			return dp[0][0];
		}
	};

	//左神二分优化版，只需遍历i的左右两边最近的key[j]字符就行了
}