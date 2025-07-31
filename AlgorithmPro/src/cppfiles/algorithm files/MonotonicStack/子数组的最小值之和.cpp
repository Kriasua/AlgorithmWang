// ���������Сֵ֮��
// ����һ���������� arr���ҵ� min(b) ���ܺͣ����� b �ķ�ΧΪ arr ��ÿ���������������顣
// ���ڴ𰸿��ܴܺ󣬴𰸶� 1000000007 ȡģ
// �������� : https://leetcode.cn/problems/sum-of-subarray-minimums/

#include<vector>
#include<array>
namespace
{
	class Solution {
	public:
		int sumSubarrayMins(std::vector<int>& arr) {
			std::vector<int> stack;
			int n = arr.size();
			stack.resize(n);
			long long int ans = 0;
			int size = 0;
			int cur;
			int left,right;
			for (int i = 0; i < n; i++)
			{
				//������ȵ���������������ȷ���㡣��ϸ�Լ�������
				while (size > 0 && (arr[i] < arr[stack[size - 1]]))
				{
					cur = stack[--size];
					left = size == 0 ? -1 : stack[size - 1];
					right = i;
					ans = (ans + static_cast<long long int>(cur - left) * static_cast<long long int>(right - cur) * static_cast<long long int>(arr[cur])) % 1000000007;
				}
				stack[size++] = i;
			}

			while (size > 0)
			{
				cur = stack[--size];
				left = size == 0 ? -1 : stack[size - 1];
				right = n;
				ans = (ans + static_cast<long long int>(cur - left) * static_cast<long long int>(right - cur) * static_cast<long long int>(arr[cur])) % 1000000007;
			}

			return (int)ans;
		}
	};
}