// �����С������
// ����һ������arr��ÿ��ֵ�����������
// ÿһ��ÿ���㶼��Ե��ұ����Լ�������Լ�����С���㣬ÿ����������ֻ��һ��
// ���ǳ����������ͬʱ�����ģ�Ҳ����ͬһ����A�Ե�B��ͬʱ��AҲ���ܱ������Ե�
// ����ж������ڵ�ǰ���ҵ�����ͬһ��С�㣬��ô����һ�֣�����С��ͬʱ����Щ�����
// ���ʶ����ֺ���������͹̶���
// ���� : 8 3 1 5 6 7 2 4
// ��һ�� : 8��3��3��1��5��6��7��2��4û�б��ԡ�����ʣ�� 8 5 6 7 4
// �ڶ��� : 8��5��5��6��7��4������ʣ�� 8 6 7
// ������ : 8��6������ʣ�� 8 7
// ������ : 8��7������ʣ�� 8��
// ���̽���������4
// �������� : https://www.nowcoder.com/practice/77199defc4b74b24b8ebf6244e1793de
// �������� : https://leetcode.cn/problems/steps-to-make-array-non-decreasing/

#include<iostream>
#include<array>
#include<vector>

namespace
{
	constexpr int MAXN = 100001;
	std::vector<int> arr;
	int N;
	std::vector<std::pair<int,int>> stack;
	int size = 0;

	int totalSteps() {
		int ans = 0;
		stack[size++] = { arr[N - 1],0 };

		for (int i = N - 2; i >= 0; i--)
		{
			std::pair<int, int> cur = { arr[i],0 };

			while (size > 0 && arr[i] > stack[size - 1].first)
			{
				cur.second = std::max(stack[size - 1].second, cur.second + 1);
				size--;
			}

			stack[size++] = cur;
			ans = std::max(ans, cur.second);
		}

		return ans;
	}

	//����Ϊ���۵ĺ��ĺ����汾
	int totalSteps(std::vector<int>& nums) {

		std::vector<std::pair<int, int>> stack;
		int ans = 0;
		int size = 0;
		int N = nums.size();
		stack.resize(N);
		stack[size++] = { nums[N - 1],0 };

		for (int i = N - 2; i >= 0; i--)
		{
			std::pair<int, int> cur = { nums[i],0 };

			while (size > 0 && nums[i] > stack[size - 1].first)
			{
				cur.second = std::max(stack[size - 1].second, cur.second + 1);
				size--;
			}

			stack[size++] = cur;
			ans = std::max(ans, cur.second);
		}

		return ans;
	}
	
	//////////////////////////////////////////

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		arr.resize(MAXN);
		stack.resize(MAXN);
		while (std::cin >> N)
		{
			size = 0;
			for (int i = 0; i < N; i++)
			{
				std::cin >> arr[i];
			}

			std::cout << totalSteps() << "\n";
		}
	}
}