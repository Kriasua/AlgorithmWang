// 三个无重叠子数组的最大和
// 给你一个整数数组 nums 和一个整数 k
// 找出三个长度为 k 、互不重叠、且全部数字和（3 * k 项）最大的子数组
// 并返回这三个子数组
// 以下标的数组形式返回结果，数组中的每一项分别指示每个子数组的起始位置
// 如果有多个结果，返回字典序最小的一个
// 测试链接 : https://leetcode.cn/problems/maximum-sum-of-3-non-overlapping-subarrays/

#include<vector>
namespace
{
    class Solution {
    public:
        std::vector<int> maxSumOfThreeSubarrays(std::vector<int>& nums, int k) {
            int n = nums.size();
            int sum = 0;
            //依次求以下三个辅助数组
            std::vector<int> Ksum(n);//以i位置开头，长度为k的子数组累加和
            std::vector<int> prefix(n);//[0...i]范围上拥有最大累加和的长度为k的子数组的起始位置
            std::vector<int> suffix(n);//[i...n-1]范围上拥有最大累加和的长度为k的子数组的起始位置
            //填写Ksum数组
            for (int i = 0; i < k-1; i++)
            {
                sum += nums[i];
            }

            for (int i = k - 1; i < n; i++)
            {
                sum += nums[i];
                Ksum[i-k+1] = sum;
                sum -= nums[i - k + 1];
            }

            //填写prefix数组
            prefix[k - 1] = 0;
            for (int i = k; i < n; i++)
            {
                //由于字典序要小，所以这里是大于
                if (Ksum[i-k+1] > Ksum[prefix[i - 1]])
                {
                    prefix[i] = i - k + 1;
                }
                else
                {
                    prefix[i] = prefix[i - 1];
                }
            }

            //填写suffix数组
            suffix[n-k] = n-k;
            for (int i = n-k-1; i >=0; i--)
            {
                //由于字典序要小，所以这里是大于等于
                if (Ksum[i] >= Ksum[suffix[i + 1]])
                {
                    suffix[i] = i;
                }
                else
                {
                    suffix[i] = suffix[i + 1];
                }
            }

            std::vector<int> ans(3);
            int maxSum = INT_MIN;
            for (int i = k; i <= n - 2 * k; i++)
            {
                int curSum = Ksum[i] + Ksum[prefix[i - 1]] + Ksum[suffix[i + k]];
                if (curSum > maxSum)
                {
                    maxSum = curSum;
                    ans[0] = prefix[i - 1];
                    ans[1] = i;
                    ans[2] = suffix[i + k];
                }
            }

            return ans;

        }
    };



    int f(std::vector<int>& prices, int days, int i, int cnt)
    {
        if (i == days)
        {
            return 0;
        }

        if (cnt == 0)
        {
            return 0;
        }

        int p1 = f(prices, days, i + 1, cnt);
        int p2 = 0;
        if (cnt == 2)
        {
            p2 = f(prices, days, i + 1, cnt - 1) - prices[i];
        }
        else
        {
            p2 = f(prices, days, i + 1, cnt - 1) + prices[i];
        }

        return std::max(p1, std::max(p2, 0));
    }

    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        return f(prices, n, 0, 2);
    }
}