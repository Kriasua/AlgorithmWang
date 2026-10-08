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

	class MyQueue2 {
	public:
		std::vector<int> s1;
		std::vector<int> s2;

		MyQueue2()
		{

		}

		void push(int x) {
			s1.push_back(x);
		}

		int pop() {

			if (!s2.empty())
			{
				int ans = s2.back();
				s2.pop_back();
				return ans;
			}
			else
			{
				while (!s1.empty())
				{
					int tmp = s1.back();
					s1.pop_back();
					s2.push_back(tmp);
				}

				int ans = s2.back();
				s2.pop_back();
				return ans;
			}
			
		}

		int peek() {

			if (!s2.empty())
			{
				return s2.back();
			}
			else
			{
				while (!s1.empty())
				{
					int tmp = s1.back();
					s1.pop_back();
					s2.push_back(tmp);
				}
;
				return s2.back();
			}

		}

		bool empty() {
			return s1.empty() && s2.empty();
		}
	};

	/**
	 * Your MyQueue object will be instantiated and called as such:
	 * MyQueue* obj = new MyQueue();
	 * obj->push(x);
	 * int param_2 = obj->pop();
	 * int param_3 = obj->peek();
	 * bool param_4 = obj->empty();
	 */
}