// 单调栈求每个位置左右两侧，离当前位置最近、且值严格小于的位置
// 给定一个可能含有重复值的数组 arr
// 找到每一个 i 位置左边和右边离 i 位置最近且值比 arr[i] 小的位置
// 返回所有位置相应的信息。
// 输入描述：
// 第一行输入一个数字 n，表示数组 arr 的长度。
// 以下一行输入 n 个数字，表示数组的值
// 输出描述：
// 输出n行，每行两个数字 L 和 R，如果不存在，则值为 -1，下标从 0 开始。
// 测试链接 : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb


#include<array>
#include<vector>
#include<iostream>
namespace
{
	constexpr int MAX = 1000001;
	std::vector<int> arr;
	std::vector<std::array<int,2>> ans;
	std::vector<int> stack;
	int n;
	int size;

	void reset()
	{
		size = 0;
	}

	void fillStack()
	{
		int process;
		for (int i = 0; i < n; i++)
		{

			while (size > 0 && (arr[i] <= arr[stack[size - 1]]))
			{
				process = stack[--size];
				ans[process][0] = size == 0 ? -1 : stack[size - 1];
				ans[process][1] = i;
			}

			stack[size++] = i;
			
		}

		while (size != 0)
		{
			process = stack[--size];
			ans[process][0] = size == 0 ? -1 : stack[size - 1];
			ans[process][1] = -1;
		}

		for (int i = n - 1; i >= 0; i--)
		{
			if (ans[i][1] != -1 && (arr[i] == arr[ans[i][1]]))
			{
				ans[i][1] = ans[ans[i][1]][1];
			}
		}
	}

	int main()
	{
		arr.resize(MAX,0);
		stack.resize(MAX,0);
		ans.resize(MAX, { 0,0 });
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		while (std::cin >> n)
		{
			reset();
			for (int i = 0; i < n; i++)
			{
				std::cin >> arr[i];
			}

			fillStack();

			for (int i=0;i<n;i++)
			{
				std::cout << ans[i][0] << " " << ans[i][1] << "\n";
			}
		}
	}
}