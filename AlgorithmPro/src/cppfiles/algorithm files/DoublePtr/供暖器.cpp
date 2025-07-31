// ��ů��
// �����Ѿ����١� ������������һ���й̶����Ȱ뾶�Ĺ�ů�������з��ݹ�ů��
// �ڼ������ļ��Ȱ뾶��Χ�ڵ�ÿ�����ݶ����Ի�ù�ů��
// ���ڣ�����λ��һ��ˮƽ���ϵķ��� houses �͹�ů�� heaters ��λ��
// �����ҳ������ؿ��Ը������з��ݵ���С���Ȱ뾶��
// ˵�������й�ů������ѭ��İ뾶��׼�����ȵİ뾶Ҳһ����
// �������� : https://leetcode.cn/problems/heaters/

#include<vector>
#include<cmath>
#include<algorithm>
namespace
{
    class Solution {
    public:
        int findRadius(std::vector<int>& houses, std::vector<int>& heaters) {
            std::sort(houses.begin(), houses.end());
            std::sort(heaters.begin(), heaters.end());
            int l = 0;
            int r = 0;
            int ans = 0;
            int radius;
            for (; l < houses.size(); l++)
            {
                radius = std::abs(houses[l] - heaters[r]);
                while (r+1 < heaters.size() && std::abs(houses[l] - heaters[r + 1]) <= radius)
                {
                    radius = std::abs(houses[l] - heaters[++r]);
                }
                ans = std::max(ans, radius);
            }
            return ans;
        }
    };
}