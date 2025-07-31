// 救生艇
// 给定数组 people
// people[i]表示第 i 个人的体重 ，船的数量不限，每艘船可以承载的最大重量为 limit
// 每艘船最多可同时载两人，但条件是这些人的重量之和最多为 limit
// 返回 承载所有人所需的最小船数
// 测试链接 : https://leetcode.cn/problems/boats-to-save-people/‘

#include<vector>
#include<algorithm>
namespace
{
    class Solution {
    public:
        int numRescueBoats(std::vector<int>& people, int limit) {

            std::sort(people.begin(), people.end());
            int l = 0;
            int r = people.size() - 1;
            int boats = 0;
            while (l <= r)
            {
                if (people[l] + people[r] > limit)
                {
                    r--;
                    boats++;
                }
                else
                {
                    l++;
                    r--;
                    boats++;
                }
            }
            return boats;
        }

        //拓展，若两人一船则体重之和必须得是偶数
        int numRescueBoats2(std::vector<int>& people, int limit)
        {
            std::vector<int> even;
            std::vector<int> odd;
            std::sort(people.begin(), people.end());
            for (int num : people)
            {
                if ((num & 1) == 1)
                {
                    odd.push_back(num);
                }
                else
                {
                    even.push_back(num);
                }
            }
            int ans = numRescueBoats(odd, limit) + numRescueBoats(even, limit);  //冗余了，因为已经排好序了所以其实调上面那个函数不用再排序，但是为了方便就这么写了。
            return ans;
        }
    };
}