// 最短无序连续子数组
// 给你一个整数数组nums，你需要找出一个 连续子数组
// 如果对这个子数组进行升序排序，那么整个数组都会变为升序排序
// 请你找出符合题意的最短子数组，并输出它的长度
// 测试链接 : https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/

#include<vector>
#include<algorithm>
namespace
{
	//贪心解法
	class Solution {
	public:
		int findUnsortedSubarray(std::vector<int>& nums) {
			int n = nums.size();
			int Rno = -1;
			int Lno = n;
			int Maxi = (-2147483647 - 1);
			int Mini = 2147483647;

			for (int i = 0; i < n; i++)
			{
				if (nums[i] >= Maxi)
				{
					Maxi = nums[i];
				}
				else
				{
					Rno = i;
				}
			}

			for (int i = n - 1; i >= 0; i--)
			{
				if (nums[i] <= Mini)
				{
					Mini = nums[i];
				}
				else
				{
					Lno = i;
				}
			}

			return Rno == -1 ? 0 : Rno - Lno + 1;
		}
	};

	//排序解法
	class Solution2 {
	public:
		int findUnsortedSubarray(std::vector<int>& nums) {
			int n = nums.size();
			std::vector<int> duplication = nums;
			std::sort(duplication.begin(),duplication.end());
			int L = -1;
			int R = n;

			for (int i = 0; i < n; i++)
			{
				L = i;
				if (duplication[i] != nums[i])
				{
					break;
				}
				
			}

			for (int i = n-1; i >= 0; i--)
			{
				R = i;
				if (duplication[i] != nums[i])
				{
					break;
				}
			}

			if (L >= R)
			{
				return 0;
			}
			else
			{
				return R - L + 1;
			}


		}
	};
}