// �ҳ�֪�����ܵ�����ר��
// ����һ������ n ����ʾ�� n ��ר�Ҵ� 0 �� n - 1 ���
// �������һ���±�� 0 ��ʼ�Ķ�ά�������� meetings
// ���� meetings[i] = [xi, yi, timei] ��ʾר�� xi ��ר�� yi ��ʱ�� timei Ҫ��һ����
// һ��ר�ҿ���ͬʱ�μ� �ೡ���� ����󣬸���һ������ firstPerson
// ר�� 0 ��һ�� ���� �����������ʱ�� 0 ��������ܷ������ר�� firstPerson
// ���ţ�������ܻ���ÿ����֪��������ܵ�ר�Ҳμӻ���ʱ���д���
// ����ʽ�ı���ǣ�ÿ�λ��飬���ר�� xi ��ʱ�� timei ʱ֪���������
// ��ô��������ר�� yi ����������ܣ���֮��Ȼ�����ܹ����� ˲ʱ���� ��
// Ҳ����˵����ͬһʱ�䣬һ��ר�Ҳ�����Խ��յ����ܣ�����������������������ר�ҷ���
// �����л��鶼����֮�󣬷�������֪��������ܵ�ר���б�
// ����԰� �κ�˳�� ���ش�
// ���Ӳ��� : https://leetcode.cn/problems/find-all-people-with-secret/

#include<vector>
#include<algorithm>
namespace
{
    using std::vector;
    class Solution {
    public:
        vector<int> fathers;
        vector<bool> isKnow;

        int find(int num)
        {
            if (fathers[num] == num)
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

            if (isKnow[fa] == true || isKnow[fb] == true)
            {
                isKnow[fb] = true;
            }

        }

        vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
            vector<int> ans;
            fathers.resize(n);
            isKnow.resize(n,false);
            int meetingsCnt = meetings.size();
            for (int i = 0; i < n; i++)
            {
                fathers[i] = i;
            }

            //�ϲ�0��ר�Һ�firstPerson
            Union(0, firstPerson);
            isKnow[0] = true;
            isKnow[firstPerson] = true;

            //���ջ���ʱ������
            std::sort(meetings.begin(), meetings.end(), [](const auto& a, const auto& b)
                {
                    return a[2] < b[2];
                });

            int left = 0;
            int right = 0;
            int curTime;
            while (left < meetingsCnt)
            {
                curTime = meetings[left][2];
                while (right < meetingsCnt && meetings[right][2] == curTime)
                {
                    right++;
                }

                //�ϲ�ר��
                for (int i = left; i < right; i++)
                {
                    Union(meetings[i][0], meetings[i][1]);
                }

                //��ɢ��֪�����ܵ�ר��
                for (int i = left; i < right; i++)
                {
                    if (isKnow[find(meetings[i][0])] == false)
                    {
                        fathers[meetings[i][0]] = meetings[i][0];
                        fathers[meetings[i][1]] = meetings[i][1];
                    }
                }

                left = right;
            }

            //���������ļ������մ�����
            for (int i = 0; i < n; i++)
            {
                if (isKnow[find(i)] == true)
                {
                    ans.push_back(i);
                }
            }

            return ans;

        }
    };
}