// 最大数
// 给定一组非负整数nums
// 重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数
// 测试链接 : https://leetcode.cn/problems/largest-number/
#include<string>
#include<vector>
#include<algorithm>
namespace 
{
	class Solution {
	public:
		std::string largestNumber(std::vector<int>& nums) {

			std::vector<std::string> strings(nums.size());
			for (int i = 0; i < nums.size(); i++)
			{
				strings[i] = std::to_string(nums[i]);
			}

			std::sort(strings.begin(), strings.end(), [](std::string& a, std::string& b)
				{
					std::string p1 = a + b;
					std::string p2 = b + a;
					return p1 > p2;
				});

			std::string ans = "";
			for (std::string string : strings)
			{
				ans += string;
			}

			if (ans[0] == '0')
			{
				return "0";
			}
			else
			{
				return ans;
			}
			
		}
	};
}