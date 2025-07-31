// 航班预订统计
// 这里有 n 个航班，它们分别从 1 到 n 进行编号。
// 有一份航班预订表 bookings ，
// 表中第 i 条预订记录 bookings[i] = [firsti, lasti, seatsi]
// 意味着在从 firsti 到 lasti 
//（包含 firsti 和 lasti ）的 每个航班 上预订了 seatsi 个座位。
// 请你返回一个长度为 n 的数组 answer，里面的元素是每个航班预定的座位总数。
// 测试链接 : https://leetcode.cn/problems/corporate-flight-bookings/

#include<vector>
namespace
{
    using std::vector;
    class Solution {
    public:
        vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
            vector<int> ans;
            ans.resize(n);
            int left,right,number;
            for (auto& row : bookings)
            {
                left = row[0]-1;
                right = row[1]-1;
                number = row[2];
                ans[left] += number;
                if (right < (n - 1))
                {
                    ans[right+1] -= number;
                }
            }

            for (int i = 1; i < n; i++)
            {
                ans[i] += ans[i - 1];
            }
            return ans;
        }
    };
}