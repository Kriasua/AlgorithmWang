// 最长数对链
// 给你一个由n个数对组成的数对数组pairs
// 其中 pairs[i] = [lefti, righti] 且 lefti < righti
// 现在，我们定义一种 跟随 关系，当且仅当 b < c 时
// 数对 p2 = [c, d] 才可以跟在 p1 = [a, b] 后面
// 我们用这种形式来构造 数对链
// 找出并返回能够形成的最长数对链的长度
// 测试链接 : https://leetcode.cn/problems/maximum-length-of-pair-chain/

#include<vector>
#include<algorithm>
namespace
{
    class Solution {
    public:
        int findLongestChain(std::vector<std::vector<int>>& pairs) {
            int n = pairs.size();
			std::sort(pairs.begin(), pairs.end(), [](auto& a, auto& b){return a[0] < b[0];});
            std::vector<int> ends(n);
            int endsSize = 1;
            ends[0] = pairs[0][1];
            int l, r;

            for (int i = 1; i < n; i++)
            {
                int head = pairs[i][0];
                int tail = pairs[i][1];
                if (head > ends[endsSize - 1])
                {
                    ends[endsSize++] = tail;
                }
                else
                {
                    ends[endsSize - 1] = std::min(ends[endsSize - 1], tail);
                }
            }
            return endsSize;
        }
    };
}