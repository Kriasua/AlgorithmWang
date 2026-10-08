#include<vector>
#include "pch.h"
//翻转对
//https://leetcode.cn/problems/reverse-pairs/description/


namespace {
    using std::vector;
    vector<int> help;
    void Counts(vector<int>& nums, int L, int R, int& ans)
    {

        if (L >= R)
            return;


        int m = (L + R) >> 1;

        Counts(nums, L, m, ans);
        Counts(nums, m + 1, R, ans);

        int a = L;
        int b = m + 1;

        int counts = 0;
        for (int i = a; i <= m; i++)
        {

            while ((nums[i] > (2 * nums[b])) && (b <= R))
            {
                b++;
                counts++;

            }
            ans += counts;
        }

        b = m + 1;
        int i = L;
        while (a <= m && b <= R)
        {
            help[i++] = nums[a] <= nums[b] ? nums[a++] : nums[b++];
        }

        while (a <= m)
        {
            help[i++] = nums[a++];
        }

        while (b <= R)
        {
            help[i++] = nums[b++];
        }

        for (int i = L; i <= R; i++)
        {
            nums[i] = help[i];
        }
    }

    int reversePairs(vector<int>& nums) {

        int ans = 0;
        help.resize(nums.size(), 0);
        Counts(nums, 0, nums.size() - 1, ans);
        return ans;
    }

	class Solution {
	public:

        int count(std::vector<int>& nums, std::vector<int>& help, int l, int r)
        {
            if (l >= r)
            {
                return 0;//只剩一个数或越界，自然是没有翻转对
            }


            int middle = l + (r - l) / 2;
            int leftCnt = count(nums, help, l, middle);//切成两边，各自去算，收答案上来
            int rightCnt = count(nums, help, middle + 1, r);
            int ans = leftCnt + rightCnt;

            int a = l;
            int b = middle + 1;
            while (a <= middle && b <= r)
            {
                if (nums[a] <= (long long int)2 * nums[b])
                {
                    a++;
                }
                else
                {
                    ans += (middle - a + 1);
                    b++;
                }
            }



			a = l;
			b = middle + 1;
            int i = a;
			while (a <= middle && b <= r)
			{
				if (nums[a] <= nums[b])
				{
                    help[i] = nums[a];
					a++;
                    i++;
				}
				else
				{
                    help[i] = nums[b];
					b++;
                    i++;
				}
			}

            while (a <= middle)
            {
                
                 help[i] = nums[a];
                 a++;
                 i++;
                
            }
            while (b <= r)
            {
				
			    help[i] = nums[b];
			    b++;
                i++;
				
            }

            for (int i = l; i <= r; i++)
            {
                nums[i] = help[i];
            }

            return ans;


        }

		int reversePairs(std::vector<int>& nums) {
            std::vector<int> help(nums.size());
            return count(nums, help, 0, nums.size() - 1);
		}
	};
}