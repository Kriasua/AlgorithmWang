// 获取所有钥匙的最短路径
// 给定一个二维网格 grid ，其中：
// '.' 代表一个空房间、'#' 代表一堵、'@' 是起点
// 小写字母代表钥匙、大写字母代表锁
// 从起点开始出发，一次移动是指向四个基本方向之一行走一个单位空间
// 不能在网格外面行走，也无法穿过一堵墙
// 如果途经一个钥匙，我们就把它捡起来。除非我们手里有对应的钥匙，否则无法通过锁。
// 假设 k 为 钥匙/锁 的个数，且满足 1 <= k <= 6，
// 字母表中的前 k 个字母在网格中都有自己对应的一个小写和一个大写字母
// 换言之，每个锁有唯一对应的钥匙，每个钥匙也有唯一对应的锁
// 另外，代表钥匙和锁的字母互为大小写并按字母顺序排列
// 返回获取所有钥匙所需要的移动的最少次数。如果无法获取所有钥匙，返回 -1 。
// 测试链接：https://leetcode.cn/problems/shortest-path-to-get-all-keys

#include<vector>
#include<string>
#include<queue>
#include<math.h>
namespace
{
    class Solution {
    public:

        bool haveKey(char lock, int curKey)
        {
            int move = lock - 'A';
            return curKey & (1 << move);
        }

        void addToQueue(int n, int m,std::vector<std::string>& grid, std::vector<std::vector<std::vector<bool>>>& visited, int i , int j , int curKey,int key, std::vector<int[3]>& queue, int& l, int& r)
        {


            int dirs[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

            for (auto& dir : dirs)
            {
                int nextI = i + dir[0];
                int nextJ = j + dir[1];

                // 2. 只检查边界和墙
                if (nextI >= 0 && nextI < n && nextJ >= 0 && nextJ < m && grid[nextI][nextJ] != '#')
                {
                    char cell = grid[nextI][nextJ];
                    int newKey = curKey; // 默认为当前 key

                    // A. 检查是否是锁
                    if (cell >= 'A' && cell <= 'F')
                    {
                        if (!haveKey(cell, curKey))
                        {
                            continue; // 没有钥匙，不能通过，跳过这个方向
                        }
                    }
                    // B. 检查是否是钥匙
                    else if (cell >= 'a' && cell <= 'f')
                    {
                        newKey |= (1 << (cell - 'a')); // 拾取钥匙，更新 newKey
                    }
                    // (C. 如果是 . 或 @，newKey 保持为 curKey)

                    // 3. **核心的 visited 检查**
                    // 检查 (nextI, nextJ, newKey) 这个 *新状态* 是否被访问过
                    if (!visited[nextI][nextJ][newKey])
                    {
                        // 4. 先标记，再入队
                        visited[nextI][nextJ][newKey] = true;
                        queue[r][0] = nextI;
                        queue[r][1] = nextJ;
                        queue[r++][2] = newKey;
                    }
                }
            }
        }

        int shortestPathAllKeys(std::vector<std::string>& grid) {
            int n = grid.size();
            int m = grid[0].size();
            int key = 0;
            int l = 0;
            int r = 0;
            int level = 0;
            std::pair<int, int> startpoint;
            for (int i = 0; i < n; i++)
            {
                
                for (int j = 0; j < m; j++)
                {
                    char cur = grid[i][j];
                    if (cur == '@')
                    {
                        startpoint = { i,j };
                    }

                    if (cur - 'a' >= 0 && cur - 'a' <= 5)
                    {
                        key |= 1 << (cur - 'a');
                    }
                }
            }
            std::vector<std::vector<std::vector<bool>>> visited(n);
            std::vector<int[3]> queue(m * n * 64 + 5);
            for (auto& col : visited)
            {
                col.resize(m);
                for (auto& row : col)
                {
                    row.resize(64, false);
                }
            }

            queue[r][0] = startpoint.first;
            queue[r][1] = startpoint.second;
            queue[r++][2] = 0;
            visited[startpoint.first][startpoint.second][0] = true;
            while (l < r)
            {
                int size = r - l;
                for (int i = 0; i < size; i++)
                {
                    auto& cur = queue[l++];
                    if (cur[2] == key)
                    {
                        return level;
                    }
                    addToQueue(n,m,grid, visited, cur[0], cur[1], cur[2], key,queue,l,r);
                }
                level++;
            }

            return -1;
        }
    };
}