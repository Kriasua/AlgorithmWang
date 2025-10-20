// 二维接雨水
// 给你一个 m * n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度
// 请计算图中形状最多能接多少体积的雨水。
// 测试链接 : https://leetcode.cn/problems/trapping-rain-water-ii/

#include<vector>
#include<array>
#include<queue>
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

        void push(std::priority_queue < std::array<int, 3>, std::vector<std::array<int, 3>>, compare>& heap, std::vector<std::vector<int>>& heightMap, std::vector<std::vector<int>>& visited, int i, int j, int line, int m, int n)
        {
            int z;
            if (i > 0 && visited[i - 1][j] == false)
            {
                z = std::max(line, heightMap[i - 1][j]);
                heap.push({ i - 1,j,z });
                visited[i - 1][j] = true;
            }

            if (i < m-1 && visited[i + 1][j] == false)
            {
                z = std::max(line, heightMap[i + 1][j]);
                heap.push({ i + 1,j,z });
                visited[i + 1][j] = true;
            }

            if (j > 0 && visited[i][j-1] == false)
            {
                z = std::max(line, heightMap[i][j-1]);
                heap.push({ i,j-1,z });
                visited[i][j - 1] = true;
            }

            if (j < n-1 && visited[i][j+1] == false)
            {
                z = std::max(line, heightMap[i][j+1]);
                heap.push({ i,j+1,z });
                visited[i][j + 1] = true;
            }
        }

        int trapRainWater(std::vector<std::vector<int>>& heightMap) {
            int m = heightMap.size();
            int n = heightMap[0].size();
            std::vector<std::vector<int>> visited(m);
            for (auto& col : visited)
            {
                col.resize(n,false);
            }

            std::priority_queue < std::array<int, 3>, std::vector<std::array<int, 3>>, compare> heap;
            for (int i = 0; i < n; i++)
            {
                visited[0][i] = true;
                visited[m - 1][i] = true;
                heap.push({ 0,i,heightMap[0][i] });
                heap.push({ m-1,i,heightMap[m-1][i] });
            }
            for (int i = 1; i < m - 1; i++)
            {
                visited[i][0] = true;
                visited[i][n-1] = true;
                heap.push({ i,0,heightMap[i][0] });
                heap.push({ i,n-1,heightMap[i][n-1] });
            }

            int ans = 0;

            while (!heap.empty())
            {
                int x = heap.top()[0];
                int y = heap.top()[1];
                int line = heap.top()[2];
                heap.pop();
                ans += std::max(line - heightMap[x][y], 0);
                push(heap, heightMap, visited, x, y, line, m, n);

            }

            return ans;
        }
    };
}