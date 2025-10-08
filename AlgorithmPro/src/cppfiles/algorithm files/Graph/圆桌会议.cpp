// 参加会议的最多员工数
// 一个公司准备组织一场会议，邀请名单上有 n 位员工
// 公司准备了一张 圆形 的桌子，可以坐下 任意数目 的员工
// 员工编号为 0 到 n - 1 。每位员工都有一位 喜欢 的员工
// 每位员工 当且仅当 他被安排在喜欢员工的旁边，他才会参加会议
// 每位员工喜欢的员工 不会 是他自己。给你一个下标从 0 开始的整数数组 favorite
// 其中 favorite[i] 表示第 i 位员工喜欢的员工。请你返回参加会议的 最多员工数目
// 测试链接 : https://leetcode.cn/problems/maximum-employees-to-be-invited-to-a-meeting/

#include<vector>
namespace
{
	using std::vector;
	class Solution {
	public:
		int maximumInvitations(vector<int>& favorite) {
			int n = favorite.size();
			vector<int> queue;
			vector<int> inDegree;
			vector<int> deep;
			queue.resize(n);
			inDegree.resize(n);
			deep.resize(n);

			int l = 0;
			int r = 0;

			for (int num : favorite)
			{
				inDegree[num]++;
			}

			for (int i = 0; i < n; i++)
			{
				if (inDegree[i] == 0)
				{
					queue[r++] = i;
				}
			}

			int cur,next;
			while (l < r)
			{
				cur = queue[l++];
				next = favorite[cur];
				if (--inDegree[next] == 0)
				{
					queue[r++] = next;
				}

				deep[next] = std::max(deep[next], deep[cur] + 1);
			}

			int sumOfSmall = 0;
			int Big = 0;
			int MaxSize = 0;
			int current;
			for (int i = 0; i < n; i++)
			{
				MaxSize = 1;

				if (inDegree[i] > 0)
				{
					current = favorite[i];
					inDegree[i] = 0;
					while (current != i)
					{
						inDegree[current] = 0;
						current = favorite[current];
						MaxSize++;
					}

					if (MaxSize == 2)
					{
						sumOfSmall += deep[i] + deep[favorite[i]] + 2;
					}
					else
					{
						Big = std::max(Big, MaxSize);
					}
				}


			}
			return std::max(sumOfSmall, Big);
		}
	};
}