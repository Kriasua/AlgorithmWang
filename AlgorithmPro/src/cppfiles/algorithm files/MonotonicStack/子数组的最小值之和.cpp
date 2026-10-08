// 子数组的最小值之和
// 给定一个整数数组 arr，找到 min(b) 的总和，其中 b 的范围为 arr 的每个（连续）子数组。
// 由于答案可能很大，答案对 1000000007 取模
// 测试链接 : https://leetcode.cn/problems/sum-of-subarray-minimums/

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
				//无论相等弹不弹出，都能正确计算。详细自己分析。
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

	class Solution2 {
	public:
		int sumSubarrayMins(std::vector<int>& arr) {
			int n = arr.size();
			std::vector<int> stack(n);
			int ans = 0;
			int mod = 1e9 + 7;
			int size = 0;

			for (int i = 0; i < n; i++)
			{
				if (size == 0)
				{
					stack[size++] = i;
				}
				else
				{
					while (size != 0 && arr[i] <= arr[stack[size - 1]])
					{
						int top = stack[--size];
						int left = size == 0 ? -1 : stack[size - 1];
						int start = top - left;
						int end = i - top;
						long long int p = start * end;
						p %= mod;
						ans = ans + (p * arr[top]) % mod;
						ans %= mod;
					}
					stack[size++] = i;
				}
			}

			while (size != 0)
			{
				int top = stack[--size];
				int left = size == 0 ? -1 : stack[size - 1];
				int start = top - left;
				int end = n - top;
				long long int p = start * end;
				p %= mod;
				ans = ans + (p * arr[top]) % mod;
				ans %= mod;
			}

			return ans;
		}
	};
}