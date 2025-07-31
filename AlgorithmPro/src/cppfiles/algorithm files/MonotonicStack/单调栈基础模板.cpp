// ����ջ��ÿ��λ���������࣬�뵱ǰλ���������ֵ�ϸ�С�ڵ�λ��
// ����һ�����ܺ����ظ�ֵ������ arr
// �ҵ�ÿһ�� i λ����ߺ��ұ��� i λ�������ֵ�� arr[i] С��λ��
// ��������λ����Ӧ����Ϣ��
// ����������
// ��һ������һ������ n����ʾ���� arr �ĳ��ȡ�
// ����һ������ n �����֣���ʾ�����ֵ
// ���������
// ���n�У�ÿ���������� L �� R����������ڣ���ֵΪ -1���±�� 0 ��ʼ��
// �������� : https://www.nowcoder.com/practice/2a2c00e7a88a498693568cef63a4b7bb


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