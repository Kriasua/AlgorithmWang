// 找出知晓秘密的所有专家
// 给你一个整数 n ，表示有 n 个专家从 0 到 n - 1 编号
// 另外给你一个下标从 0 开始的二维整数数组 meetings
// 其中 meetings[i] = [xi, yi, timei] 表示专家 xi 和专家 yi 在时间 timei 要开一场会
// 一个专家可以同时参加 多场会议 。最后，给你一个整数 firstPerson
// 专家 0 有一个 秘密 ，最初，他在时间 0 将这个秘密分享给了专家 firstPerson
// 接着，这个秘密会在每次有知晓这个秘密的专家参加会议时进行传播
// 更正式的表达是，每次会议，如果专家 xi 在时间 timei 时知晓这个秘密
// 那么他将会与专家 yi 分享这个秘密，反之亦然。秘密共享是 瞬时发生 的
// 也就是说，在同一时间，一个专家不光可以接收到秘密，还能在其他会议上与其他专家分享
// 在所有会议都结束之后，返回所有知晓这个秘密的专家列表
// 你可以按 任何顺序 返回答案
// 链接测试 : https://leetcode.cn/problems/find-all-people-with-secret/

#include<vector>
#include<algorithm>
namespace
{
    using std::vector;
    class Solution {
    public:
        vector<int> fathers;
        vector<bool> isKnow;

        int find(int num)
        {
            if (fathers[num] == num)
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

            if (isKnow[fa] == true || isKnow[fb] == true)
            {
                isKnow[fb] = true;
            }

        }

        vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
            vector<int> ans;
            fathers.resize(n);
            isKnow.resize(n,false);
            int meetingsCnt = meetings.size();
            for (int i = 0; i < n; i++)
            {
                fathers[i] = i;
            }

            //合并0号专家和firstPerson
            Union(0, firstPerson);
            isKnow[0] = true;
            isKnow[firstPerson] = true;

            //按照会议时间排序
            std::sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b)
                {
                    return a[2] < b[2];
                });

            int left = 0;
            int right = 0;
            int curTime;
            while (left < meetingsCnt)
            {
                curTime = meetings[left][2];
                while (right < meetingsCnt && meetings[right][2] == curTime)
                {
                    right++;
                }

                //合并专家
                for (int i = left; i < right; i++)
                {
                    Union(meetings[i][0], meetings[i][1]);
                }

                //拆散不知道秘密的专家
                for (int i = left; i < right; i++)
                {
                    if (isKnow[find(meetings[i][0])] == false)
                    {
                        fathers[meetings[i][0]] = meetings[i][0];
                        fathers[meetings[i][1]] = meetings[i][1];
                    }
                }

                left = right;
            }

            //符合条件的加入最终答案数组
            for (int i = 0; i < n; i++)
            {
                if (isKnow[find(i)] == true)
                {
                    ans.push_back(i);
                }
            }

            return ans;

        }
    };
}