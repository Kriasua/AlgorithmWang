// 电动车游城市
// 小明的电动车电量充满时可行驶距离为 cnt，每行驶 1 单位距离消耗 1 单位电量，且花费 1 单位时间
// 小明想选择电动车作为代步工具。地图上共有 N 个景点，景点编号为 0 ~ N-1
// 他将地图信息以 [城市 A 编号,城市 B 编号,两城市间距离] 格式整理在在二维数组 paths，
// 表示城市 A、B 间存在双向通路。
// 初始状态，电动车电量为 0。每个城市都设有充电桩，
// charge[i] 表示第 i 个城市每充 1 单位电量需要花费的单位时间。
// 请返回小明最少需要花费多少单位时间从起点城市 start 抵达终点城市 end
// 测试链接 : https://leetcode.cn/problems/DFPeFJ/

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
            //节点数
            int n = charge.size();
            std::vector < std::vector<std::array<int, 2>>> graph(n);
            std::priority_queue<std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;

            //无向图，所以正向反向都要加
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