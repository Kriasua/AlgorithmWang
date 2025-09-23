// 拓扑排序模版（Leetcode）
// 邻接表建图（动态方式）
// 课程表II
// 现在你总共有 numCourses 门课需要选，记为 0 到 numCourses - 1
// 给你一个数组 prerequisites ，其中 prerequisites[i] = [ai, bi]
// 表示在选修课程 ai 前 必须 先选修 bi
// 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示：[0,1]
// 返回你为了学完所有课程所安排的学习顺序。可能会有多个正确的顺序
// 你只要返回 任意一种 就可以了。如果不可能完成所有课程，返回 一个空数组
// 测试链接 : https://leetcode.cn/problems/course-schedule-ii/

#include<vector>
namespace
{
    class Solution {
    public:
        std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {

            std::vector<std::vector<int>> graph;// 建图
            std::vector<int> indegree; //入度表
            std::vector<int> queue;//使用队列模拟数组
            std::vector<int> ans;

            graph.resize(numCourses);
            indegree.resize(numCourses);
            queue.resize(numCourses);
            int left = 0;
            int right = 0;

            for (auto& course : prerequisites)
            {
                graph[course[1]].push_back(course[0]);
                indegree[course[0]]++;
            }

            for (int i = 0; i < numCourses; i++)
            {
                if (indegree[i] == 0)
                {
                    queue[right++] = i;
                }
            }

            int temp;

            while (left < right)
            {
                temp = queue[left++];
                for (int num : graph[temp])
                {
                    if (--indegree[num] == 0)
                    {
                        queue[right++] = num;
                    }
                }
                ans.push_back(temp);
            }

            if (ans.size() == numCourses)
            {
                return ans;
            }
            else
            {
                return {};
            }

        }
    };
}