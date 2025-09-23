// ��������ģ�棨Leetcode��
// �ڽӱ�ͼ����̬��ʽ��
// �γ̱�II
// �������ܹ��� numCourses �ſ���Ҫѡ����Ϊ 0 �� numCourses - 1
// ����һ������ prerequisites ������ prerequisites[i] = [ai, bi]
// ��ʾ��ѡ�޿γ� ai ǰ ���� ��ѡ�� bi
// ���磬��Ҫѧϰ�γ� 0 ������Ҫ����ɿγ� 1 ��������һ��ƥ������ʾ��[0,1]
// ������Ϊ��ѧ�����пγ������ŵ�ѧϰ˳�򡣿��ܻ��ж����ȷ��˳��
// ��ֻҪ���� ����һ�� �Ϳ����ˡ����������������пγ̣����� һ��������
// �������� : https://leetcode.cn/problems/course-schedule-ii/

#include<vector>
namespace
{
    class Solution {
    public:
        std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {

            std::vector<std::vector<int>> graph;// ��ͼ
            std::vector<int> indegree; //��ȱ�
            std::vector<int> queue;//ʹ�ö���ģ������
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