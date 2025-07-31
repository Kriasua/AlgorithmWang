// ���㲻��ʽ�����ֵ
// ����һ������ points ��һ������ k
// ������ÿ��Ԫ�ض���ʾ��άƽ���ϵĵ�����꣬�����պ����� x ��ֵ��С��������
// Ҳ����˵ points[i] = [xi, yi]
// ������ 1 <= i < j <= points.length ��ǰ���£�xi < xj �ܳ���
// �����ҳ� yi + yj + |xi - xj| �� ���ֵ��
// ���� |xi - xj| <= k �� 1 <= i < j <= points.length
// ��Ŀ�������ݱ�֤���ٴ���һ���ܹ����� |xi - xj| <= k �ĵ㡣
// �������� : https://leetcode.cn/problems/max-value-of-equation/

#include<vector>
namespace
{
	class Solution {
	public:
		int findMaxValueOfEquation(std::vector<std::vector<int>>& points, int k) {
			std::vector<int> deque;
			deque.resize(points.size(),0);
			int left = 0;
			int right = 1;
			int ans = INT_MIN;
			for (int i = 1,x,y; i < points.size(); i++)
			{
				x = points[i][0];
				y = points[i][1];
				while (left < right && x - points[deque[left]][0] > k)
				{
					left++;
				}

				if (left < right)
				{
					ans = std::max(ans, x + y + points[deque[left]][1] - points[deque[left]][0]);
				}

				while (left < right && ((y - x) >= (points[deque[right - 1]][1] - points[deque[right - 1]][0])))
				{
					right--;
				}

				deque[right++] = i;
				
			}
			
			return ans;
		}
	};
}
