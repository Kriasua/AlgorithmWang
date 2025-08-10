// 移除最多的同行或同列石头
// n 块石头放置在二维平面中的一些整数坐标点上。每个坐标点上最多只能有一块石头
// 如果一块石头的 同行或者同列 上有其他石头存在，那么就可以移除这块石头
// 给你一个长度为 n 的数组 stones ，其中 stones[i] = [xi, yi] 表示第 i 块石头的位置
// 返回 可以移除的石子 的最大数量。
// 测试链接 : https://leetcode.cn/problems/most-stones-removed-with-same-row-or-column/

#include<vector>
#include<unordered_map>
namespace
{
    class Solution {
    public:
        std::vector<int> father;
        std::unordered_map<int, int> row;
        std::unordered_map<int, int> col;
        int sets;

        int find(int num)
        {
            if (father[num] == num)
            {
                return num;
            }

            int result = find(father[num]);
            father[num] = result;
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
            sets--;
            father[fa] = fb;
        }

        int removeStones(std::vector<std::vector<int>>& stones) {
           
            int n = stones.size();
            father.resize(n);
            sets = n;
            for (int i = 0; i < n; i++)
            {
                father[i] = i;
            }

            for (int i = 0; i < n; i++)
            {
                auto itcol = col.find(stones[i][1]);
                auto itrow = row.find(stones[i][0]);

                if (itcol != col.end())
                {
                    Union(itcol->second, i);
                }
                else
                {
                    col.emplace(stones[i][1], i);
                }

                if (itrow != row.end())
                {
                    Union(itrow->second, i);
                }
                else
                {
                    row.emplace(stones[i][0], i);
                }

            }

            return n - sets;

        }
    };
}