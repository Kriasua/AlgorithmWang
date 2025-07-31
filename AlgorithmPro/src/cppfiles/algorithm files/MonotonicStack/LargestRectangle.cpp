// ��״ͼ�����ľ���
// ���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶�
// ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 �����ڸ���״ͼ�У��ܹ����ճ����ľ��ε�������
// �������ӣ�https://leetcode.cn/problems/largest-rectangle-in-histogram


#include<vector>
namespace
{
	class Solution {
	public:
		int largestRectangleArea(std::vector<int>& heights) {
			std::vector<int> stack;
			stack.resize(heights.size());
			int ans=0;
			int size=0,cur,left;
			for (int i = 0; i < heights.size(); i++)
			{//������ȵ������������ܼ�����ȷ����ϸ�Լ�����
				while (size > 0 && heights[i] < heights[stack[size - 1]])
				{
					cur = stack[--size];
					left = size == 0 ? -1 : stack[size - 1];
					ans = std::max(ans, (i - left - 1) * heights[cur]);
				}

				stack[size++] = i;
			}

			while (size > 0)
			{
				cur = stack[--size];
				left = size == 0 ? -1 : stack[size - 1];
				ans = std::max(ans, heights[cur] * (int)(heights.size() - left - 1));
			}

			return ans;
		}
	};
}


