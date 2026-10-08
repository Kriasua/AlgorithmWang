// 每日温度
// 给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer
// 其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后
// 如果气温在这之后都不会升高，请在该位置用 0 来代替。
// 测试链接 : https://leetcode.cn/problems/daily-temperatures/

#include<vector>
namespace
{
	class Solution {
	public:
		//无需考虑重复值也无需清算阶段
		std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
			std::vector<int> ans;
			std::vector<int> stack;
			int size = 0;
			ans.resize(temperatures.size());
			stack.resize(temperatures.size());
			int cur;
			for (int i = 0; i < temperatures.size(); i++)
			{
				while (size > 0 && (temperatures[i] > temperatures[stack[size - 1]]))
				{
					cur = stack[--size];
					ans[cur] = i - cur;
				}

				stack[size++] = i;
			}

			return ans;
		}
	};

	class Solution2 {
	public:
		std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {

			std::vector<int> ans(temperatures.size());
			std::vector<int> stack(temperatures.size());
			int size = 0;

			for (int i = 0; i < temperatures.size(); i++)
			{
				if (size == 0)
				{
					stack[size++] = i;
				}
				else
				{
					while (size != 0 && temperatures[i] > temperatures[stack[size - 1]])
					{
						int top = stack[size - 1];
						size--;
						ans[top] = i;
					}

					stack[size++] = i;
				}
			}

			while (size != 0)
			{
				int top = stack[size - 1];
				ans[top] = top;
				size--;
			}

			for (int i = 0; i < temperatures.size(); i++)
			{
				ans[i] -= i;
			}

			return ans;

		}
	};
}