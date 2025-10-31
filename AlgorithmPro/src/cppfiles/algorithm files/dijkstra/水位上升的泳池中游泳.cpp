// ˮλ������Ӿ������Ӿ
// ��һ�� n x n ���������� grid ��
// ÿһ�������ֵ grid[i][j] ��ʾλ�� (i, j) ��ƽ̨�߶�
// ����ʼ����ʱ����ʱ��Ϊ t ʱ��ˮ���е�ˮλΪ t
// ����Դ�һ��ƽ̨�����������ڵ�����һ��ƽ̨������ǰ���Ǵ�ʱˮλ����ͬʱ��û������ƽ̨
// �ٶ������˲���ƶ����޾��룬Ҳ����Ĭ���ڷ����ڲ��ζ��ǲ���ʱ��
// ��Ȼ��������Ӿ��ʱ�������������귽�����档
// ������귽�������ƽ̨ (0��0) ����
// ���� �㵽�����귽�������ƽ̨ (n-1, n-1) ���������ʱ��
// �������� : https://leetcode.cn/problems/swim-in-rising-water/

#include<vector>
#include<queue>
#include<array>
namespace
{
    class Solution {
    public:
        struct compare
        {
            bool operator()(const auto& a, const auto& b)
            {
                return a[2] > b[2];
            }
        };

        int swimInWater(std::vector<std::vector<int>>& grid) {
            int n = grid.size();
            std::vector<std::vector<bool>> visited;
            visited.resize(n);
            for (auto& col : visited)
            {
                col.resize(n, false);
            }

            std::vector<std::vector<int>> distances(n, std::vector<int>(n, INT_MAX));
            std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;

            distances[0][0] = grid[0][0];
            heap.push({ 0,0,grid[0][0] });

            while (!heap.empty())
            {
                int curX = heap.top()[0];
                int curY = heap.top()[1];
                int curDis = heap.top()[2];
                heap.pop();

                if (curX == n - 1 && curY == n - 1)
                {
                    return curDis;
                }

                if (!visited[curX][curY])
                {
                    visited[curX][curY] = true;
                    //��������ĸ���
                    if (curX > 0)
                    {
                        int time = std::max(grid[curX-1][curY], curDis);
                        if (time < distances[curX - 1][curY])
                        {
                            distances[curX - 1][curY] = time;
                            heap.push({ curX - 1,curY,distances[curX - 1][curY] });
                        }

                    }

                    if (curX < n-1)
                    {
                        int time = std::max(grid[curX + 1][curY], curDis);
                        if (time < distances[curX + 1][curY])
                        {
                            distances[curX + 1][curY] = time;
                            heap.push({ curX + 1,curY,distances[curX + 1][curY] });
                        }

                    }

                    if (curY > 0)
                    {
                        int time = std::max(grid[curX][curY-1], curDis);
                        if (time < distances[curX][curY-1])
                        {
                            distances[curX ][curY-1] = time;
                            heap.push({ curX ,curY-1,distances[curX ][curY-1] });
                        }
                    }

                    if (curY < n-1)
                    {
                        int time = std::max(grid[curX][curY + 1], curDis);
                        if (time < distances[curX][curY + 1])
                        {
                            distances[curX][curY + 1] = time;
                            heap.push({ curX ,curY + 1,distances[curX][curY + 1] });
                        }
                    }
                }
            }

            return -1;

        }
};
}