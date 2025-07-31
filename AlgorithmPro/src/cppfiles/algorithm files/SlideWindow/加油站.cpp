// ����վ
// ��һ����·���� n ������վ�����е� i ������վ������ gas[i] ����
// ����һ�������������޵ĵ��������ӵ� i ������վ������ i+1 ������վ��Ҫ�������� cost[i] ��
// ������е�һ������վ��������ʼʱ����Ϊ�ա�
// ���������������� gas �� cost ���������԰�˳���ƻ�·��ʻһ��
// �򷵻س���ʱ����վ�ı�ţ����򷵻� -1
// ������ڽ⣬�� ��֤ ���� Ψһ �ġ�
// �������� : https://leetcode.cn/problems/gas-station/

#include<vector>
namespace
{
    class Solution {
    public:
        int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
            int n = gas.size();
            std::vector<int> rest(n);
            long long total_rest = 0;
            for (int i = 0; i < n; i++)
            {
                rest[i] = gas[i] - cost[i];
                total_rest += rest[i];
            }
            if (total_rest < 0) {
                return -1;
            }
            int i = 0;
            int sum = 0;
            int j = i;
            while (i < n)
            {
                sum = 0;
                while (sum >= 0 && j-i < n)
                {
                    sum += rest[j%n];
                    j++;
                }

                if (j - i == n)
                {
                    return i;
                }
                else
                {
                    i = j % n;
                }
            }

            return -1;
        }
    };
}

