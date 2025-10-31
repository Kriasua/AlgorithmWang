// �綯���γ���
// С���ĵ綯����������ʱ����ʻ����Ϊ cnt��ÿ��ʻ 1 ��λ�������� 1 ��λ�������һ��� 1 ��λʱ��
// С����ѡ��綯����Ϊ�������ߡ���ͼ�Ϲ��� N �����㣬������Ϊ 0 ~ N-1
// ������ͼ��Ϣ�� [���� A ���,���� B ���,�����м����] ��ʽ�������ڶ�ά���� paths��
// ��ʾ���� A��B �����˫��ͨ·��
// ��ʼ״̬���綯������Ϊ 0��ÿ�����ж����г��׮��
// charge[i] ��ʾ�� i ������ÿ�� 1 ��λ������Ҫ���ѵĵ�λʱ�䡣
// �뷵��С��������Ҫ���Ѷ��ٵ�λʱ��������� start �ִ��յ���� end
// �������� : https://leetcode.cn/problems/DFPeFJ/

#include<vector>
#include<queue>
#include<array>
namespace
{
    class Solution {
    public:
        struct compare
        {
            bool operator()(const std::array<int, 3>& a, const std::array<int, 3>& b)
            {
                return a[2] > b[2];
            }
        };

        int electricCarPlan(std::vector<std::vector<int>>& paths, int cnt, int start, int end, std::vector<int>& charge) {
            //�ڵ���
            int n = charge.size();
            std::vector < std::vector<std::array<int, 2>>> graph(n);
            std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;

            //����ͼ������������Ҫ��
            for (auto& col : paths)
            {
                graph[col[0]].push_back({ col[1],col[2] });
                graph[col[1]].push_back({ col[0],col[2] });
            }

            std::vector<std::vector<int>> distances(cnt+1, std::vector<int>(n,INT_MAX));
            std::vector<std::vector<bool>> visited(cnt+1, std::vector<bool>(n,false));
            distances[0][start] = 0;

            
            heap.push({ start,0,0 });
            

            while (!heap.empty())
            {
                auto top = heap.top();
                heap.pop();
                int city = top[0];
                int batt = top[1];
                int cost = top[2];

                if (visited[batt][city])
                {
                    continue;
                }

                if (city == end)
                {
                    return cost;
                }

                visited[batt][city] = true;
                if (batt < cnt && !visited[batt+1][city] && (distances[batt + 1][city] > cost + charge[city]))
                {
                    distances[batt + 1][city] = cost + charge[city];
                    heap.push({ city,batt + 1,distances[batt + 1][city] });
                    
                }

                for (auto& edge : graph[city])
                {
                    if (batt >= edge[1] && !visited[batt-edge[1]][edge[0]])
                    {
                        if (cost + edge[1] < distances[batt - edge[1]][edge[0]])
                        {
                            distances[batt - edge[1]][edge[0]] = cost + edge[1];
                            heap.push({ edge[0],batt - edge[1],distances[batt - edge[1]][edge[0]] });
                            
                        }
                    }
                }
            }

            return -1;

        }
    };
}