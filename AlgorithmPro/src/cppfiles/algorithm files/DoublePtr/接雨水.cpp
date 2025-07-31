// ����ˮ
// ���� n ���Ǹ�������ʾÿ�����Ϊ 1 �����ӵĸ߶�ͼ�����㰴�����е����ӣ�����֮���ܽӶ�����ˮ
// �������� : https://leetcode.cn/problems/trapping-rain-water/
#include<vector>
namespace
{
    class Solution {
    public:
        int trap(std::vector<int>& height) {
            int n = height.size();
            std::vector<int> left(n);
            std::vector<int> right(n);
            left[0] = height[0];
            right[n - 1] = height[n - 1];
            for (int i = 1; i < n; i++)
            {
                left[i] = height[i] > left[i - 1] ? height[i] : left[i - 1];
            }
            for (int i = n - 2; i >= 0; i--)
            {
                right[i] = height[i] > right[i + 1] ? height[i] : right[i + 1];
            }

            int ans = 0;
            for (int i = 1, lmax = 0, rmax = 0; i < n - 1; i++)
            {
                lmax = left[i - 1];
                rmax = right[i + 1];
                ans += std::max(std::min(lmax, rmax) - height[i], 0);
            }
            return ans;
        } 

        //˫ָ���Ż���
        int trap2(std::vector<int>& height) {
            int n = height.size();
            int ans = 0;
            int lmax = height[0];
            int rmax = height[n - 1];
            int l = 1;
            int r = n - 2;
            while (l <= r)
            {
                if (lmax < rmax)
                {
                    ans += std::max(lmax - height[l], 0);
                    lmax = std::max(lmax, height[l]);
                    l++;
                }
                else
                {
                    ans += std::max(rmax - height[r], 0);
                    rmax = std::max(rmax, height[r]);
                    r--;
                }
            }
            return ans;
        }

    };
}