// �����ַ�����
// ��������ַ��� X �е�������ͬλ�õ���ĸ��ʹ�������ַ��� Y ���
// ��ô�� X �� Y �����ַ�������
// ����������ַ�����������ȵģ�������Ҳ�����Ƶ�
// ���磬"tars" �� "rats" �����Ƶ� (���� 0 �� 2 ��λ��)��
// "rats" �� "arts" Ҳ�����Ƶģ����� "star" ���� "tars"��"rats"���� "arts" ����
// ��֮������ͨ���������γ������������飺{"tars", "rats", "arts"} �� {"star"}
// ע�⣬"tars" �� "arts" ����ͬһ���У���ʹ���ǲ�������
// ��ʽ�ϣ���ÿ������ԣ�Ҫȷ��һ�����������У�ֻ��Ҫ����ʺ͸���������һ���������ơ�
// ����һ���ַ����б� strs�б��е�ÿ���ַ������� strs �����������ַ�����һ����ĸ��λ�ʡ�
// ���� strs ���ж����ַ�����
// �������� : https://leetcode.cn/problems/similar-string-groups/

#include<string>
#include<vector>
namespace
{
    class Solution {
    public:
        std::vector<int> fathers;
        int sets;

        bool isSimilar(std::vector<std::string>& strs, int a, int b)
        {
            int cnt = 0;
            for (int i = 0; i < strs[a].size() && cnt < 3; i++)
            {
                if (strs[a][i] != strs[b][i])
                {
                    cnt++;
                }
            }

            return cnt == 2 || cnt == 0;
        }

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

        int numSimilarGroups(std::vector<std::string>& strs) {
            fathers.resize(strs.size());
            sets = strs.size();
            for (int i = 0; i < fathers.size(); i++)
            {
                fathers[i] = i;
            }

            for (int i = 0; i < strs.size(); i++)
            {
                for (int j = i + 1; j < strs.size(); j++)
                {
                    if (isSimilar(strs, i, j))
                    {
                        Union(i, j);
                    }
                }
            }

            return sets;
        }
    };
}