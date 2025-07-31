// ÿ���¶�
// ����һ���������� temperatures ����ʾÿ����¶ȣ�����һ������ answer
// ���� answer[i] ��ָ���ڵ� i �죬��һ�������¶ȳ����ڼ����
// �����������֮�󶼲������ߣ����ڸ�λ���� 0 �����档
// �������� : https://leetcode.cn/problems/daily-temperatures/

#include<vector>
namespace
{
	class Solution {
	public:
		//���迼���ظ�ֵҲ��������׶�
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
}