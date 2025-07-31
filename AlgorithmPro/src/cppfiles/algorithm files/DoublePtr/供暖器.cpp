// 供暖器
// 冬季已经来临。 你的任务是设计一个有固定加热半径的供暖器向所有房屋供暖。
// 在加热器的加热半径范围内的每个房屋都可以获得供暖。
// 现在，给出位于一条水平线上的房屋 houses 和供暖器 heaters 的位置
// 请你找出并返回可以覆盖所有房屋的最小加热半径。
// 说明：所有供暖器都遵循你的半径标准，加热的半径也一样。
// 测试链接 : https://leetcode.cn/problems/heaters/

#include<vector>
#include<cmath>
#include<algorithm>
namespace
{
    class Solution {
    public:
        int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
            std::sort(houses.begin(), houses.end());
            std::sort(heaters.begin(), heaters.end());
            int l = 0;
            int r = 0;
            int ans = 0;
            int radius;
            for (; l < houses.size(); l++)
            {
                radius = std::abs(houses[l] - heaters[r]);
                while (r+1 < heaters.size() && std::abs(houses[l] - heaters[r + 1]) <= radius)
                {
                    radius = std::abs(houses[l] - heaters[++r]);
                }
                ans = std::max(ans, radius);
            }
            return ans;
        }
    };
}