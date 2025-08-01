// ����ǣ��
// n�����������������е� 2n ����λ�ϣ���Ҫǣ���Է�����
// �˺���λ��һ���������� row ��ʾ������ row[i] �����ڵ� i ����λ�ϵ��˵�ID
// �����ǰ�˳���ţ���һ���� (0, 1)���ڶ����� (2, 3)���Դ����ƣ����һ���� (2n-2, 2n-1)
// ���� ���ٽ�����λ�Ĵ������Ա�ÿ�����¿��Բ�������һ��
// ÿ�ν�����ѡ���������ˣ�������վ����������λ
// �������� : https://leetcode.cn/problems/couples-holding-hands/

#include<vector>
#include<unordered_set>
namespace
{
    class Solution {
    public:
        std::vector<int> fathers;
        int sets;
        int find(int num)
        {
            if (num == fathers[num])
            {
                return num;
            }

            int result = find(fathers[num]);
            fathers[num] = result;
            return result;
        }

        void Union(int a, int b)
        {
            int fa = find(a);
            int fb = find(b);

            if (fa == fb)
            {
                return;
            }

            fathers[fa] = fb;
            sets--;
        }

        int minSwapsCouples(std::vector<int>& row) {
            sets = row.size() >> 1;
            int n = sets;
            fathers.resize(n);
            for (int i = 0; i < n; i++)
            {
                fathers[i] = i;
            }

            for (int i = 0; i < row.size(); i += 2)
            {
                Union(row[i] / 2, row[i + 1] / 2);
            }
            return n - sets;

        }
    };
}