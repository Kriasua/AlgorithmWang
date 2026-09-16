// 按奇偶排序数组II
// 给定一个非负整数数组 nums。nums 中一半整数是奇数 ，一半整数是偶数
// 对数组进行排序，以便当 nums[i] 为奇数时，i也是奇数
// 当 nums[i] 为偶数时， i 也是 偶数
// 你可以返回 任何满足上述条件的数组作为答案
// 测试链接 : https://leetcode.cn/problems/sort-array-by-parity-ii/
#include<vector>
namespace
{
    class Solution {
    public:

        void swap(std::vector<int>& nums, int a, int b)
        {
            int temp = nums[a];
            nums[a] = nums[b];
            nums[b] = temp;
        }

        std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
            int last = nums.size() - 1;
            int even = 0;
            int odd = 1;
            while (even < nums.size() && odd < nums.size())
            {
                if ((nums[last] & 1) != 1)
                {
                    swap(nums, even, last);
                    even += 2;
                }
                else
                {
                    swap(nums, odd, last);
                    odd += 2;
                }
            }

            return nums;
        }
    };

	class Solution2 {
	public:
		void swap(std::vector<int>& nums, int a, int b)
		{
			int temp = nums[a];
			nums[a] = nums[b];
			nums[b] = temp;
		}

		std::vector<int> sortArrayByParityII(std::vector<int>& nums) {
            int odd = 1;
            int even = 0;
            int n = nums.size() - 1;

            while (even <= n && odd <= n)
            {
				if (nums[n] % 2 == 0)
				{
					swap(nums, n, even);
					even += 2;
				}
                else
                {
                    swap(nums, n, odd);
                    odd += 2;
                }
            }

            return nums;
		}
	};
}

int main()
{
    std::vector<int> nums = { 4,2,5,7 };
    Solution2 sol;
    sol.sortArrayByParityII(nums);
    int i = 1;
}