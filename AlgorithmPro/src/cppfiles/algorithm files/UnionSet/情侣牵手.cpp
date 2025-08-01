// 情侣牵手
// n对情侣坐在连续排列的 2n 个座位上，想要牵到对方的手
// 人和座位由一个整数数组 row 表示，其中 row[i] 是坐在第 i 个座位上的人的ID
// 情侣们按顺序编号，第一对是 (0, 1)，第二对是 (2, 3)，以此类推，最后一对是 (2n-2, 2n-1)
// 返回 最少交换座位的次数，以便每对情侣可以并肩坐在一起
// 每次交换可选择任意两人，让他们站起来交换座位
// 测试链接 : https://leetcode.cn/problems/couples-holding-hands/

#include<vector>
#include<unordered_set>
namespace
{
    class Solution {
    public:
        std::vector<int> fathers;
        int sets;
        int find(int num)
        {
            if (num == fathers[num])
            {
                return num;
            }

            int result = find(fathers[num]);
            fathers[num] = result;
            return result;
        }

        void Union(int a, int b)
        {
            int fa = find(a);
            int fb = find(b);

            if (fa == fb)
            {
                return;
            }

            fathers[fa] = fb;
            sets--;
        }

        int minSwapsCouples(std::vector<int>& row) {
            sets = row.size() >> 1;
            int n = sets;
            fathers.resize(n);
            for (int i = 0; i < n; i++)
            {
                fathers[i] = i;
            }

            for (int i = 0; i < row.size(); i += 2)
            {
                Union(row[i] / 2, row[i + 1] / 2);
            }
            return n - sets;

        }
    };
}