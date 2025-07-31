#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
// 表现良好的最长时间段
// 给你一份工作时间表 hours，上面记录着某一位员工每天的工作小时数
// 我们认为当员工一天中的工作小时数大于 8 小时的时候，那么这一天就是 劳累的一天
// 所谓 表现良好的时间段 ，意味在这段时间内，「劳累的天数」是严格 大于 不劳累的天数
// 请你返回 表现良好时间段 的最大长度
// 测试链接 : https://leetcode.cn/problems/longest-well-performing-interval/
namespace
{
    class Solution {
    public:
        int longestWPI(std::vector<int>& hours) {
            std::unordered_map<int, int> map;
            map.emplace(0, 1);
            int ans = 0;
            size_t N = hours.size();
            int sum = 0;
            for (size_t i = 0; i < N; i++)
            {
                sum += hours[i] > 8 ? 1 : -1;
                if (sum > 0)
                {
                    ans = i + 1;
                }
                else
                {
                    if (map.find(sum - 1) != map.end())
                    {
                        ans = std::max((unsigned int)ans, i - map[sum - 1]);
                    }
                }

                if (map.find(sum) == map.end())
                {
                    map[sum] = i;
                }
            }
            return ans;
        }
    };
}