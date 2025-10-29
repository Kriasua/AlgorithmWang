// Dijkstra算法模版（Leetcode）
// 网络延迟时间
// 有 n 个网络节点，标记为 1 到 n
// 给你一个列表 times，表示信号经过 有向 边的传递时间
// times[i] = (ui, vi, wi)，表示从ui到vi传递信号的时间是wi
// 现在，从某个节点 s 发出一个信号
// 需要多久才能使所有节点都收到信号
// 如果不能使所有节点收到信号，返回 -1
// 测试链接 : https://leetcode.cn/problems/network-delay-time

#include<vector>
#include<array>
#include<queue>
namespace
{
    class Solution {
    public:

        struct compare
        {
            bool operator()(const std::array<int, 2>& a, const std::array<int, 2>& b)
            {
                return a[1] > b[1];
            }
        };

        int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
            std::vector < std::vector<std::array<int,2>>> graph(n + 1);
            std::priority_queue<std::array<int, 2>, std::vector<std::array<int, 2>>, compare> heap;

            for (auto& col : times)
            {
                graph[col[0]].push_back({ col[1],col[2] });
            }

            std::vector<int> distances(n + 1,INT_MAX);
            std::vector<bool> visited(n + 1, false);

            heap.push({ k,0 });
            distances[k] = 0;
            while (!heap.empty())
            {
                auto cur = heap.top();
                heap.pop();
                if (!visited[cur[0]])
                {
                    visited[cur[0]] = true;

                    for (auto& i : graph[cur[0]])
                    {
                        if (!visited[i[0]])
                        {
                            if (distances[cur[0]] + i[1] < distances[i[0]])
                            {
                                distances[i[0]] = distances[cur[0]] + i[1];
                                heap.push({ i[0], distances[i[0]] });
                            }

                        }
                    }
                }
            }

            int ans = 0;
            for (int i=1;i<=n;i++)
            {
                if (distances[i] == INT_MAX)
                {
                    return -1;
                }
                ans = std::max(ans,distances[i]);
            }

            return ans;
        }
    };

    class Solution2 {
    public:
        class IndexHeap
        {
        public:
            std::vector<std::array<int,2>> m_heap;
            std::vector<int> m_set;
            
        public:
            IndexHeap(int setSize)
            {
                m_set.resize(setSize,-1);
                
            }

            void swap(int a, int b)
            {
                int seta = m_heap[a][0];
                int setb = m_heap[b][0];
                m_set[seta] = b;
                m_set[setb] = a;

                auto tmp = m_heap[a];
                m_heap[a] = m_heap[b];
                m_heap[b] = tmp;
            }

            void heapify(int i)
            {
                int l = 2 * i + 1;

                while (l < m_heap.size())
                {
                    int smaller = l + 1 < m_heap.size() && m_heap[l][1] > m_heap[l + 1][1] ? l + 1 : l;

                    if (m_heap[i][1] > m_heap[smaller][1])
                    {
                        swap(i, smaller);
                        i = smaller;
                        l = 2 * i + 1;
                    }
                    else
                    {
                        break;
                    }
                }
            }

            void heapInsert(int i)
            {
                while (m_heap[(i - 1) / 2][1] > m_heap[i][1])
                {
                    swap(i, (i - 1) / 2);
                    i = (i - 1) / 2;
                }
            }

            //想改变的节点，以及改成多少
            void changeNumber(int node, int num)
            {
                int location = m_set[node];
                //只能改小，不能改大
                if (num > m_heap[location][1])
                {
                    return;
                }

                m_heap[location][1] = num;
                heapInsert(location);
            }

            void push(std::array<int, 2> arr)
            {
                m_heap.push_back(arr);
                int curPos = m_heap.size() - 1;
                m_set[arr[0]] = curPos;

                heapInsert(curPos);
            }  

            bool empty()
            {
                return m_heap.empty();
            }

            std::array<int, 2> top()
            {
                if (!empty())
                {
                    return m_heap.front();
                }
                else
                {
                    return {};
                }
            }

            void pop()
            {
                if (!empty())
                {
                    m_set[m_heap[0][0]] = -2;
                    m_heap.front() = m_heap.back();
                    m_heap.pop_back();
                    if (m_heap.size() > 1)
                    {
                        m_set[m_heap[0][0]] = 0;
                        heapify(0);
                    }
                }
            }

        };

        int networkDelayTime(std::vector<std::vector<int>>& times, int n, int k) {
            IndexHeap heap(n + 1);
            std::vector < std::vector<std::array<int, 2>>> graph(n + 1);
            for (auto& col : times)
            {
                graph[col[0]].push_back({ col[1],col[2] });
            }
            std::vector<int> distances(n + 1, INT_MAX);

            heap.push({ k,0 });
            distances[k] = 0;

            while (!heap.empty())
            {
                auto col = heap.top();
                int node = col[0];
                int Dis = col[1];
                
                heap.pop();
                if (Dis > distances[node])
                {
                    continue;
                }

                for (auto& edge : graph[col[0]])
                {
                    int curNode = edge[0];
                    int curDis = edge[1];
                    if (heap.m_set[curNode] == -1)
                    {
                        distances[curNode] = distances[node] + curDis;
                        heap.push({ curNode,distances[node] + curDis });
                       
                    }
                    else if (heap.m_set[curNode] > -1)
                    {
                        if (distances[node] + curDis < distances[curNode])
                        {
                            distances[curNode] = distances[node] + curDis;
                            heap.changeNumber(curNode, distances[node] + curDis);

                        }
                    }
                    else
                    { }
                }
            }

            int ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (distances[i] == INT_MAX)
                {
                    return -1;
                }
                ans = std::max(ans, distances[i]);
            }

            return ans;


        }
    };
}