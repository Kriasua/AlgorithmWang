// ����ͧ
// �������� people
// people[i]��ʾ�� i ���˵����� �������������ޣ�ÿ�Ҵ����Գ��ص��������Ϊ limit
// ÿ�Ҵ�����ͬʱ�����ˣ�����������Щ�˵�����֮�����Ϊ limit
// ���� �����������������С����
// �������� : https://leetcode.cn/problems/boats-to-save-people/��

#include<vector>
#include<algorithm>
namespace
{
    class Solution {
    public:
        int numRescueBoats(std::vector<int>& people, int limit) {

            std::sort(people.begin(), people.end());
            int l = 0;
            int r = people.size() - 1;
            int boats = 0;
            while (l <= r)
            {
                if (people[l] + people[r] > limit)
                {
                    r--;
                    boats++;
                }
                else
                {
                    l++;
                    r--;
                    boats++;
                }
            }
            return boats;
        }

        //��չ��������һ��������֮�ͱ������ż��
        int numRescueBoats2(std::vector<int>& people, int limit)
        {
            std::vector<int> even;
            std::vector<int> odd;
            std::sort(people.begin(), people.end());
            for (int num : people)
            {
                if ((num & 1) == 1)
                {
                    odd.push_back(num);
                }
                else
                {
                    even.push_back(num);
                }
            }
            int ans = numRescueBoats(odd, limit) + numRescueBoats(even, limit);  //�����ˣ���Ϊ�Ѿ��ź�����������ʵ�������Ǹ��������������򣬵���Ϊ�˷������ôд�ˡ�
            return ans;
        }
    };
}