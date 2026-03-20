//×îÐ¡Õ»
//https://leetcode.cn/problems/min-stack/description/
#include<vector>

namespace
{
	class MinStack {
	public:
		const int MAX = 30005;
		std::vector<int> stack;
		std::vector<int> min;
		int size = 0;

		MinStack() {
			stack.resize(MAX);
			min.resize(MAX);
		}

		void push(int val) {

			if (size == 0)
			{
				stack[size] = val;
				min[size++] = val;
			}
			else
			{
				int curMin = min[size - 1];
				if (val <= curMin)
				{
					stack[size] = val;
					min[size++] = val;
				}
				else
				{
					stack[size] = val;
					min[size++] = curMin;
				}
			}

		}

		void pop() {

			size--;

		}

		int top() {
			return stack[size - 1];
		}

		int getMin() {
			return min[size - 1];
		}
	};
}