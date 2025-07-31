// ͳ��ȫ1�Ӿ��ε�����
// ����һ�� m * n �ľ��� mat������ֻ��0��1����ֵ
// ���㷵���ж��ٸ� �Ӿ��� ��Ԫ��ȫ������1
// �������� : https://leetcode.cn/problems/count-submatrices-with-all-ones/

#include<vector>
namespace
{
	class Solution {
	public:

		int numSubline(std::vector<int>& arr)
		{
			std::vector<int> stack;
			stack.resize(arr.size());
			int size = 0;
			int ans = 0;
			int cur,left;

			for (int i = 0; i < arr.size(); i++)
			{
				while (size > 0 && arr[i] <= arr[stack[size - 1]])
				{
					cur = stack[--size];
					if (arr[i] < arr[cur])
					{
						left = size == 0 ? -1 : stack[size - 1];
						int leftmin = left == -1 ? 0 : arr[left];
						int higher = std::max(arr[i], leftmin);
						ans += (((i - left) * (i - left - 1)) / 2) * (arr[cur] - higher);
					}
				}
				stack[size++] = i;
			}

			while (size > 0)
			{
				cur = stack[--size];
				left = size == 0 ? -1 : stack[size - 1];
				int higher = size == 0 ? 0 : arr[stack[size - 1]];
				ans += (((arr.size() - left) * (arr.size() - left - 1)) / 2) * (arr[cur] - higher);
			}

			return ans;
		}


		int numSubmat(std::vector<std::vector<int>>& mat) {
			int ans=0;
			std::vector<int> arr;
			arr.resize(mat[0].size());
			for (int i = 0; i < mat.size(); i++)
			{
				for (int j = 0; j < mat[0].size(); j++)
				{
					arr[j] = mat[i][j] == 1 ? arr[j]+1 : 0;
				}

				ans += numSubline(arr);

			}
			return ans;
		}
	};
}