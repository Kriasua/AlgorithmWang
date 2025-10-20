// ʹ����ͼ������һ����Ч·������С����
// ����һ�� m * n ������ͼ grid �� grid ��ÿ�����Ӷ���һ������
// ��Ӧ�ŴӸø��ӳ�����һ���ߵķ��� grid[i][j] �е����ֿ���Ϊ���¼��������
// 1 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i][j + 1]
// 2 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i][j - 1]
// 3 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i + 1][j]
// 4 ����һ�������ߣ�Ҳ�������� grid[i][j] �ߵ� grid[i - 1][j]
// ע������ͼ�п��ܻ��� ��Ч���� ����Ϊ���ǿ���ָ�� grid ���������
// һ��ʼ�����������Ͻǵĸ��� (0,0) ����
// ���Ƕ���һ�� ��Ч·�� Ϊ�Ӹ��� (0,0) ������ÿһ����˳�����ֶ�Ӧ������
// �����������½ǵĸ��� (m - 1, n - 1) ������·��
// ��Ч·�� ����Ҫ�����·��
// ����Ի���1�Ĵ����޸�һ�������е����֣���ÿ�������е����� ֻ���޸�һ��
// ���㷵��������ͼ������һ����Ч·������С����
// �������� : https://leetcode.cn/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

#include<vector>
#include<deque>
#include<array>
namespace
{
    class Solution {
    public:

        void push(std::vector<std::vector<int>>& grid, std::deque<std::array<int, 2>>& queue, std::vector<std::vector<int>>& distances, int i, int j)
        {
            int cost;
            if (i > 0)
            {
                cost = grid[i][j] == 4 ? 0 : 1;
                if (distances[i][j] + cost < distances[i - 1][j])
                {
                    distances[i - 1][j] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i - 1,j });
                    }
                    else
                    {
                        queue.push_back({ i - 1,j });
                    }
                }
            }

            if (i < grid.size()-1)
            {
                cost = grid[i][j] == 3 ? 0 : 1;
                if (distances[i][j] + cost < distances[i + 1][j])
                {
                    distances[i + 1][j] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i + 1,j });
                    }
                    else
                    {
                        queue.push_back({ i + 1,j });
                    }
                }
            }

            if (j > 0)
            {
                cost = grid[i][j] == 2 ? 0 : 1;
                if (distances[i][j] + cost < distances[i][j-1])
                {
                    distances[i][j-1] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i,j-1 });
                    }
                    else
                    {
                        queue.push_back({ i ,j -1 });
                    }
                }
            }

            if (j < grid[0].size() -1 )
            {
                cost = grid[i][j] == 1 ? 0 : 1;
                if (distances[i][j] + cost < distances[i][j + 1])
                {
                    distances[i][j+1] = distances[i][j] + cost;
                    if (cost == 0)
                    {
                        queue.push_front({ i,j + 1 });
                    }
                    else
                    {
                        queue.push_back({ i ,j + 1 });
                    }
                }
            }

        }

        int minCost(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();
            std::deque<std::array<int, 2>> queue;
            std::vector<std::vector<int>> distances;
            distances.resize(m);
            for (auto& col : distances)
            {
                col.resize(n,INT_MAX);
            }

            distances[0][0] = 0;
            queue.push_front({ 0,0 });

            while (!queue.empty())
            {
                int x = queue.front()[0];
                int y = queue.front()[1];
                queue.pop_front();

                if (x == m - 1 && y == n - 1)
                {
                    return distances[x][y];
                }
                else
                {
                    push(grid, queue, distances,x,y);
                }

            }

            return -1;
        }
    };
}