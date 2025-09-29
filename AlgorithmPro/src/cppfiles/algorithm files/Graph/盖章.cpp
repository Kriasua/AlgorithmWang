// 戳印序列
// 你想最终得到"abcbc"，认为初始序列为"?????"。印章是"abc"
// 那么可以先用印章盖出"??abc"的状态，
// 然后用印章最左字符和序列的0位置对齐，就盖出了"abcbc"
// 这个过程中，"??abc"中的a字符，被印章中的c字符覆盖了
// 每次盖章的时候，印章必须完全盖在序列内
// 给定一个字符串target是最终的目标，长度为n，认为初始序列为n个'?'
// 给定一个印章字符串stamp，目标是最终盖出target
// 但是印章的使用次数必须在10*n次以内
// 返回一个数组，该数组由每个回合中被印下的最左边字母的索引组成
// 上面的例子返回[2,0]，表示印章最左字符依次和序列2位置、序列0位置对齐盖下去，就得到了target
// 如果不能在10*n次内印出序列，就返回一个空数组
// 测试链接 : https://leetcode.cn/problems/stamping-the-sequence/

#include<string>
#include<vector>
namespace
{
	class Solution {
	public:
		std::vector<int> movesToStamp(std::string stamp, std::string target) {
			int m = stamp.size();
			int n = target.size();
			std::vector<int> inDegree;
			std::vector<int> queue;
			std::vector<std::vector<int>> graph;
			inDegree.resize(n - m + 1, m);
			queue.resize(n - m + 1);
			graph.resize(n);

			int left = 0;
			int right = 0;

			for (int i = 0 ; i < n - m + 1; i++)
			{
				
				for (int j = 0; j < m; j++)
				{
					if (target[j+i] == stamp[j])
					{
						if (--inDegree[i] == 0)
						{
							queue[right++] = i;
						}
					}
					else
					{
						graph[i + j].push_back(i);
					}
					
				}
			}

			std::vector<bool> visted;
			visted.resize(n,false);

			std::vector<int> ans;
			int cur;
			while (left < right)
			{
				cur = queue[left++];
				ans.push_back(cur);
				for (int i = 0; i < m; i++)
				{
					if (!visted[cur + i])
					{
						visted[cur + i] = true;
						for (int num : graph[cur + i])
						{
							if (--inDegree[num] == 0)
							{
								queue[right++] = num;
							}
						}
					}
				}
			}

			if (ans.size() != n - m + 1)
			{
				return {};
			}

			for (int i = 0,temp; i < ans.size() >> 1; i++)
			{
				temp = ans[i];
				ans[i] = ans[ans.size() - i - 1];
				ans[ans.size() - i - 1] = temp;
			}

			return ans;

		}
	};
}