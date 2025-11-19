// 俄罗斯套娃信封问题
// 给你一个二维整数数组envelopes ，其中envelopes[i]=[wi, hi]
// 表示第 i 个信封的宽度和高度
// 当另一个信封的宽度和高度都比这个信封大的时候
// 这个信封就可以放进另一个信封里，如同俄罗斯套娃一样
// 请计算 最多能有多少个信封能组成一组“俄罗斯套娃”信封
// 即可以把一个信封放到另一个信封里面，注意不允许旋转信封
// 测试链接 : https://leetcode.cn/problems/russian-doll-envelopes/

#include<vector>
#include<algorithm>
namespace
{
	class Solution {
	public:
		int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
			int n = envelopes.size();
			std::sort(envelopes.begin(), envelopes.end(), [](auto& a, auto& b)
				{
					if (a[0] != b[0])
					{
						return a[0] < b[0];
					}
					else
					{
						return a[1] > b[1];
					}
				});

			std::vector<int> ends(n);
			int endsSize = 1;
			ends[0] = envelopes[0][1];
			int l, r;

			for (int i = 1; i < n; i++)
			{
				if (envelopes[i][1] > ends[endsSize-1])
				{
					ends[endsSize++] = envelopes[i][1];
				}
				else
				{
					l = 0;
					r = endsSize - 1;
					int pos = r;
					while (l <= r)
					{
						int middle = l + ((r - l) >> 1);
						if (envelopes[i][1] <= ends[middle])
						{
							r = middle - 1;
							pos = middle;
						}
						else
						{
							l = middle + 1;
						}
					}
					ends[pos] = envelopes[i][1];
				}
			}	

			return endsSize;
		}
	};
}