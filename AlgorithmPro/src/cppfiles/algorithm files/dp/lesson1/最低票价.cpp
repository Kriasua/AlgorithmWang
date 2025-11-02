// 最低票价
// 在一个火车旅行很受欢迎的国度，你提前一年计划了一些火车旅行
// 在接下来的一年里，你要旅行的日子将以一个名为 days 的数组给出
// 每一项是一个从 1 到 365 的整数
// 火车票有 三种不同的销售方式
// 一张 为期1天 的通行证售价为 costs[0] 美元
// 一张 为期7天 的通行证售价为 costs[1] 美元
// 一张 为期30天 的通行证售价为 costs[2] 美元
// 通行证允许数天无限制的旅行
// 例如，如果我们在第 2 天获得一张 为期 7 天 的通行证
// 那么我们可以连着旅行 7 天(第2~8天)
// 返回 你想要完成在给定的列表 days 中列出的每一天的旅行所需要的最低消费
// 测试链接 : https://leetcode.cn/problems/minimum-cost-for-tickets/

#include<vector>
#include<array>
namespace
{
    //暴力递归，只能过一半
    class Solution {
    public:

        int f(std::vector<int>& days, std::vector<int>& costs, int i)
        {
            if (i == days.size())
            {
                return 0;
            }

            int one = costs[0] + f(days, costs, i + 1);

            int sevenpos = i;
            while (sevenpos < days.size() && days[sevenpos] <= days[i] + 6)
            {
                sevenpos++;
            }
            int seven = costs[1] + f(days, costs, sevenpos);

            int thirtypos = sevenpos;
            while (thirtypos < days.size() && days[thirtypos] <= days[i] + 29)
            {
                thirtypos++;
            }

            int thirty = costs[2] + f(days, costs, thirtypos);

            return std::min(one, std::min(seven, thirty));
        }

        int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
            return f(days, costs, 0);
        }
    };

    //记忆化搜索
    class Solution2 {
    public:

        int f(std::vector<int>& days, std::vector<int>& costs, int i, std::vector<int>& dp)
        {
            if (i == days.size())
            {
                return 0;
            }

            if (dp[i] != -1)
            {
                return dp[i];
            }

            int one = costs[0] + f(days, costs, i + 1,dp);

            int sevenpos = i;
            while (sevenpos < days.size() && days[sevenpos] <= days[i] + 6)
            {
                sevenpos++;
            }
            int seven = costs[1] + f(days, costs, sevenpos,dp);

            int thirtypos = sevenpos;
            while (thirtypos < days.size() && days[thirtypos] <= days[i] + 29)
            {
                thirtypos++;
            }

            int thirty = costs[2] + f(days, costs, thirtypos,dp);

            int ans = std::min(one, std::min(seven, thirty));
            dp[i] = ans;
            return ans;
        }

        int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
            std::vector<int> dp(days.size(),-1);
            return f(days, costs, 0, dp);
        }
    };

    //正宗动态规划
    class Solution3 {
    public:

        int mincostTickets(std::vector<int>& days, std::vector<int>& costs) {
            int n = days.size();
            std::vector<int> dp(n+1, -1);
            dp[n] = 0;

            for (int i = n - 1; i >= 0; i--)
            {
                int one = costs[0] + dp[i+1];

                int sevenpos = i;
                while (sevenpos < n && days[sevenpos] <= days[i] + 6)
                {
                    sevenpos++;
                }
                int seven = costs[1] + dp[sevenpos];

                int thirtypos = sevenpos;
                while (thirtypos < n && days[thirtypos] <= days[i] + 29)
                {
                    thirtypos++;
                }

                int thirty = costs[2] + dp[thirtypos];

                dp[i] = std::min(one, std::min(seven, thirty));
            }

            return dp[0];
        }
    };
}