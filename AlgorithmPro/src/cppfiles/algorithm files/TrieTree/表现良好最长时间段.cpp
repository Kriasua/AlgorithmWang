#include<vector>
#include<iostream>
#include<cmath>
#include<unordered_map>
// �������õ��ʱ���
// ����һ�ݹ���ʱ��� hours�������¼��ĳһλԱ��ÿ��Ĺ���Сʱ��
// ������Ϊ��Ա��һ���еĹ���Сʱ������ 8 Сʱ��ʱ����ô��һ����� ���۵�һ��
// ��ν �������õ�ʱ��� ����ζ�����ʱ���ڣ������۵����������ϸ� ���� �����۵�����
// ���㷵�� ��������ʱ��� ����󳤶�
// �������� : https://leetcode.cn/problems/longest-well-performing-interval/
namespace
{
    class Solution {
    public:
        int longestWPI(std::vector<int>& hours) {
            std::unordered_map<int, int> map;
            map.emplace(0, 1);
            int ans = 0;
            size_t N = hours.size();
            int sum = 0;
            for (size_t i = 0; i < N; i++)
            {
                sum += hours[i] > 8 ? 1 : -1;
                if (sum > 0)
                {
                    ans = i + 1;
                }
                else
                {
                    if (map.find(sum - 1) != map.end())
                    {
                        ans = std::max((unsigned int)ans, i - map[sum - 1]);
                    }
                }

                if (map.find(sum) == map.end())
                {
                    map[sum] = i;
                }
            }
            return ans;
        }
    };
}