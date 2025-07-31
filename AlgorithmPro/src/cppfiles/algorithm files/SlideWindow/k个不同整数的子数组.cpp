// K个不同整数的子数组
// 给定一个正整数数组 nums和一个整数 k，返回 nums 中 「好子数组」 的数目。
// 如果 nums 的某个子数组中不同整数的个数恰好为 k
// 则称 nums 的这个连续、不一定不同的子数组为 「好子数组 」。
// 例如，[1,2,3,1,2] 中有 3 个不同的整数：1，2，以及 3。
// 子数组 是数组的 连续 部分。
// 测试链接 : https://leetcode.cn/problems/subarrays-with-k-different-integers/

#include<vector>
#include<unordered_map>
namespace
{
    class Solution {
    public:

        int subarrayUnderKDistinct(std::vector<int>& nums, int k)
        {
            std::unordered_map<int, int> map;
            int left = 0;
            int right = 0;
            int ans = 0;
            for (; right < nums.size(); right++)
            {
                map[nums[right]]++;

                while (map.size() > k)
                {
                    if (--map[nums[left]] == 0)
                    {
                        map.erase(nums[left]);
                    }
                    left++;
                }

                ans += right - left + 1;
            }
            return ans;
        }
        std::vector<int> map;
        Solution()
        {
            map.resize(20001, 0);
        }

        //使用数组代替哈希表优化
        int subarrayUnderKDistinct2(std::vector<int>& nums, int k)
        {
            int counts = k;
            int left = 0;
            int right = 0;
            int ans = 0;
            for (; right < nums.size(); right++)
            {
                if (++map[nums[right]] == 1)
                {
                    counts--;
                }

                while (counts < 0)
                {
                    if (--map[nums[left++]] == 0)
                    {
                        counts++;
                    }
                }

                ans += right - left + 1;
            }
            return ans;
        }

        int subarraysWithKDistinct(std::vector<int>& nums, int k) {
            
            return subarrayUnderKDistinct(nums, k) - subarrayUnderKDistinct(nums, k - 1);
        }
    };
}