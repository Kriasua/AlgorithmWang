#include<stack>
#include<iostream>
#include<climits>
#include "pch.h"
namespace
{
	class reverseStack
	{
	private:
		static int bottomOut(std::stack<int>& myStack)
		{
			int ans = myStack.top();
			myStack.pop();

			if (myStack.empty())
			{
				return ans;
			}

			int last = bottomOut(myStack);
			myStack.push(ans);
			return last;
		}

	public:

		static void reverse(std::stack<int>& myStack)
		{
			if (myStack.empty())
			{
				return;
			}

			int ans = bottomOut(myStack);
			reverse(myStack);
			myStack.push(ans);
		}


	};


	class sortStack
	{
	public:

		static int deep(std::stack<int>& myStack)
		{
			if (myStack.empty())
			{
				return 0;
			}

			int node = myStack.top();
			myStack.pop();
			int Deep = deep(myStack) + 1;
			myStack.push(node);
			return Deep;
		}

		static int max(std::stack<int>& myStack, int deep)
		{
			if (deep == 0)
			{
				return INT_MIN;
			}

			int node = myStack.top();
			myStack.pop();

			int next = max(myStack, deep - 1);
			myStack.push(node);
			return node > next ? node : next;

		}

		static int cntMax(std::stack<int>& myStack, int deep, int max)
		{
			if (deep == 0)
			{
				return 0;
			}

			int node = myStack.top();
			myStack.pop();
			int cnt = node == max ? 1 : 0;
			int cntMaxNext = cntMax(myStack, deep - 1, max);
			myStack.push(node);

			return cnt + cntMaxNext;
		}

		static void down(std::stack<int>& myStack, int deep, int max, int times)
		{
			if (deep == 0)
			{
				for (int i = 0; i < times; i++)
				{
					myStack.push(max);
				}
				return;
			}

			int node = myStack.top();
			myStack.pop();
			down(myStack, deep - 1, max, times);

			if (node != max)
			{
				myStack.push(node);
			}

		}

		static void sortstack(std::stack<int>& myStack)
		{
			int deep = sortStack::deep(myStack);
			while (deep > 0)
			{
				int max = sortStack::max(myStack, deep);
				int times = sortStack::cntMax(myStack, deep, max);
				sortStack::down(myStack, deep, max, times);
				deep -= times;
			}
		}

	};

}

