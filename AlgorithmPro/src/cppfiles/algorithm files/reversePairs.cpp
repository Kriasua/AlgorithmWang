#include<vector>
#include "pch.h"

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
}