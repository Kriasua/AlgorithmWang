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






	class MinStack2 {
	public:

		std::vector<int> stack;
		std::vector<int> Min;
		int size;
		MinStack2() : size(0)
		{
			stack.resize(30004);
			Min.resize(30004);
		}

		void push(int value) {
			if (size == 0)
			{
				stack[size] = value;
				Min[size++] = value;
			}
			else
			{
				stack[size] = value;
				Min[size] = value >= getMin() ? getMin() : value;
				size++;
			}
		}

		void pop() {
			size--;
		}

		int top() {
			return stack[size - 1];
		}

		int getMin() {
			return Min[size - 1];
		}
	};


}