// ʢ���ˮ������
// ����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵��� (i, 0) �� (i, height[i]) ��
// �ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ
// �����������Դ�������ˮ��
// ˵�����㲻����б����
// �������� : https://leetcode.cn/problems/container-with-most-water/
#include<vector>
namespace
{
    class Solution {
    public:
        int maxArea(std::vector<int>& height) {
            int l = 0;
            int r = height.size() - 1;
            int ans = 0;
            while (l < r)
            {
                ans = std::max(ans,(r - l) * std::min(height[l], height[r]));
                if (height[l] < height[r])
                {
                    l++;
                }
                else
                {
                    r--;
                }
            }
            return ans;
        }
    };
}