// ��ͼ����
// ������������һ�ݴ�СΪ n x n �� ���� grid
// �����ÿ�� ��Ԫ�� ���� 0 �� 1 ��Ǻ������� 0 ������1 ����½�ء�
// �����ҳ�һ������Ԫ���������Ԫ�����������½�ص�Ԫ��ľ���������
// �����ظþ��롣���������ֻ��½�ػ��ߺ����뷵�� -1��
// ��������˵�ľ����ǡ������پ��롹�� Manhattan Distance����
// (x0, y0) �� (x1, y1) ��������Ԫ��֮��ľ����� |x0 - x1| + |y0 - y1| ��
// �������� : https://leetcode.cn/problems/as-far-from-land-as-possible/

#include<vector>

namespace
{
    class Solution {
    public:

        std::vector<std::pair<int, int>> queue;
        std::vector<std::vector<bool>> help;
        int l, r;
        void search(std::vector<std::vector<int>>& grid, int i, int j)
        {
            int n = grid.size();
            //���Ͼͼ���
            if (i > 0 && help[i - 1][j] == false)
            {
                queue[r++] = { i - 1,j };
                help[i - 1][j] = true;
            }
            //���¾ͼ���
            if (i < n - 1 && help[i + 1][j] == false)
            {
                queue[r++] = { i + 1,j };
                help[i + 1][j] = true;
            }
            //����ͼ���
            if (j > 0 && help[i][j - 1] == false)
            {
                queue[r++] = { i,j-1 };
                help[i][j - 1] = true;
            }
            //���Ҿͼ���
            if (j < n - 1 && help[i][j + 1] == false)
            {
                queue[r++] = { i,j + 1 };
                help[i][j + 1] = true;
            }
        }

        int maxDistance(std::vector<std::vector<int>>& grid) {
           

            l = 0;
            r = 0;
            int n = grid.size();

            queue.resize(n * n);
            help.resize(n);
            for (auto& col : help)
            {
                col.resize(n);
            }

            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (grid[i][j] == 1)
                    {
                        queue[r++] = { i,j };
                        help[i][j] = true;
                    }
                    else
                    {
                        help[i][j] = false;
                    }
                }
            }

            //ȫ�Ǻ���
            if (r == 0)
            {
                return -1;
            }

            int level = 0;
            int cnt;
            while (l < r)
            {
                cnt = r - l;
                for (int i = 0; i < cnt; i++)
                {
                    search(grid, queue[l].first, queue[l++].second);
                }
                level++;
            }

            //ȫ��½�ط���-1
            return level == 1 ? -1 : level-1;
        }
    };
}