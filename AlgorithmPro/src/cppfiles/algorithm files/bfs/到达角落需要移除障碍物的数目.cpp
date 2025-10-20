// ���������Ҫ�Ƴ��ϰ������С��Ŀ
// ����һ���±�� 0 ��ʼ�Ķ�ά�������� grid �������СΪ m x n
// ÿ����Ԫ��������ֵ֮һ��
// 0 ��ʾһ�� �� ��Ԫ��
// 1 ��ʾһ�������Ƴ��� �ϰ���
// ��������ϡ��¡������ƶ�����һ���յ�Ԫ���ƶ�����һ���յ�Ԫ��
// ��������Ҫ�����Ͻ� (0, 0) �ƶ������½� (m - 1, n - 1) 
// ������Ҫ�Ƴ����ϰ������С��Ŀ
// �������� : https://leetcode.cn/problems/minimum-obstacle-removal-to-reach-corner/

#include<vector>
#include<deque>
#include<array>
namespace
{
    using std::pair;
    class Solution {
    public:  
        void push(std::vector<std::vector<int>>& grid, int i, int j, std::vector<std::vector<int>>& distances, std::deque<std::array<int, 2>>& queue)
        {
            //���Ͼͼ���
            if (i > 0 && distances[i][j] + grid[i-1][j] < distances[i-1][j])
            {
                distances[i - 1][j] = distances[i][j] + grid[i - 1][j];
                if (grid[i - 1][j] == 0)
                {
                    queue.push_front({ i - 1,j });
                }
                else
                {
                    queue.push_back({ i - 1,j });
                }
            }
            //���¾ͼ���
            if (i < grid.size()-1 && distances[i][j] + grid[i + 1][j] < distances[i + 1][j])
            {
                distances[i + 1][j] = distances[i][j] + grid[i + 1][j];
                if (grid[i + 1][j] == 0)
                {
                    queue.push_front({ i + 1,j });
                }
                else
                {
                    queue.push_back({ i + 1,j });
                }
            }
            //����ͼ���
            if (j > 0 && distances[i][j] + grid[i][j-1] < distances[i][j-1])
            {
                distances[i][j-1] = distances[i][j] + grid[i][j-1];
                if (grid[i][j-1] == 0)
                {
                    queue.push_front({ i ,j-1 });
                }
                else
                {
                    queue.push_back({ i ,j -1});
                }
            }
            //���Ҿͼ���
            if (j < grid[0].size() - 1 && distances[i][j] + grid[i][j + 1] < distances[i][j + 1])
            {
                distances[i][j + 1] = distances[i][j] + grid[i][j + 1];
                if (grid[i][j + 1] == 0)
                {
                    queue.push_front({ i ,j + 1 });
                }
                else
                {
                    queue.push_back({ i ,j + 1 });
                }
            }
        }

        int minimumObstacles(std::vector<std::vector<int>>& grid) {
            int m = grid.size();
            int n = grid[0].size();

            std::vector<std::vector<int>> distances;
            distances.resize(m);

            std::deque<std::array<int,2>> queue;
            for (auto& col : distances)
            {
                col.resize(n, INT_MAX);
            }
            distances[0][0] = 0;
            queue.push_back({ 0,0 });

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
                    push(grid, x, y, distances, queue);

                }
            }

            return -1;
        }
    };
}