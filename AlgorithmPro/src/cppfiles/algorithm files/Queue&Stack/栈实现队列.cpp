//栈实现队列
//https://leetcode.cn/problems/implement-queue-using-stacks/
#include<vector>

namespace
{
	class MyQueue {
	public:
		std::vector<int> inStack;
		std::vector<int> outStack;
		int sizeIn = 0;
		int sizeOut = 0;

		MyQueue() {
			inStack.resize(101);
			outStack.resize(101);
		}

		void push(int x) {
			inStack[sizeIn++] = x;
		}

		int pop() {

			int ans = peek();
			sizeOut--;
			return ans;
		}

		int peek() {
			if (sizeOut != 0)
			{
				return outStack[sizeOut - 1];
			}

			while (sizeIn != 0)
			{
				int num = inStack[--sizeIn];
				outStack[sizeOut++] = num;
			}

			return outStack[sizeOut - 1];

		}

		bool empty() {
			return (sizeIn == 0) && (sizeOut == 0);
		}
	};
}