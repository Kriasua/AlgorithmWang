// ��С��������·��
// ��׼���μ�һ��Զ��������һ����ά rows x columns �ĵ�ͼ heights
// ���� heights[row][col] ��ʾ���� (row, col) �ĸ߶�
// һ��ʼ���������Ͻǵĸ��� (0, 0) ������ϣ��ȥ�����½ǵĸ��� (rows-1, columns-1) 
// ��ע���±�� 0 ��ʼ��ţ�����ÿ�ο����� �ϣ��£����� �ĸ�����֮һ�ƶ�
// ����Ҫ�ҵ��ķ� ���� ��С��һ��·��
// һ��·���ķѵ�����ֵ��·���ϣ����ڸ���֮��߶Ȳ����ֵ�����ֵ
// ���㷵�ش����Ͻ��ߵ����½ǵ���С ��������ֵ
// �������� ��https://leetcode.cn/problems/path-with-minimum-effort/

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

        int minimumEffortPath(std::vector<std::vector<int>>& heights) {
            int n = heights.size();
            int m = heights[0].size();
            std::vector<std::vector<bool>> visited;
            visited.resize(n);
            for (auto& col : visited)
            {
                col.resize(m, false);
            }

            std::vector<std::vector<int>> distances(n, std::vector<int>(m, INT_MAX));
            std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;

            distances[0][0] = 0;
            heap.push({ 0,0,0 });

            while (!heap.empty())
            {
                int curX = heap.top()[0];
                int curY = heap.top()[1];
                int curDis = heap.top()[2];
                heap.pop();

                if (curX == n - 1 && curY == m - 1)
                {
                    return curDis;
                }

                if (!visited[curX][curY])
                {
                    visited[curX][curY] = true;
                    //��������ĸ���
                    if (curX > 0)
                    {
                        int diff = std::abs(heights[curX - 1][curY] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX - 1][curY])
                        {
                            distances[curX - 1][curY] = diff;
                            heap.push({ curX - 1,curY,distances[curX - 1][curY] });
                        }
                        
                    }

                    //����ĸ���
                    if (curX < n-1)
                    {
                        int diff = std::abs(heights[curX + 1][curY] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX + 1][curY])
                        {
                            distances[curX + 1][curY] = diff;
                            heap.push({ curX + 1,curY,distances[curX + 1][curY] });
                        }
                    }

                    //��ߵĸ���
                    if (curY > 0)
                    {
                        int diff = std::abs(heights[curX][curY-1] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX][curY-1])
                        {
                            distances[curX ][curY-1] = diff;
                            heap.push({ curX ,curY-1,distances[curX][curY-1] });
                        }
                    }

                    //�ұߵĸ���
                    if (curY < m-1)
                    {
                        int diff = std::abs(heights[curX][curY + 1] - heights[curX][curY]);
                        diff = std::max(diff, curDis);
                        if (diff < distances[curX][curY + 1])
                        {
                            distances[curX][curY + 1] = diff;
                            heap.push({ curX ,curY + 1,distances[curX][curY + 1] });
                        }
                    }
                }
            }

            return -1;

        }
    };
}