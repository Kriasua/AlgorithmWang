// ����˹���
// ����һ����СΪ n * n �����ƾ��� grid ����� ֻ�ܽ�һ�� 0 ��� 1 ��
// ����ִ�д˲�����grid �����ĵ�������Ƕ��٣�
// ���� ��һ���ϡ��¡������ĸ����������� 1 �γ�
// �������� : https://leetcode.cn/problems/making-a-large-island/
 
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
namespace
{
	class Solution {
	public:
		int id = 2;
		std::vector<int> cnt;
		int n;
		std::unordered_map<int, int> map;
		std::unordered_set<int> set;
		//dfs��Ⱦ����ÿ�������ţ���2��ʼ
		int dfs(std::vector<std::vector<int>>& grid, int i, int j)
		{
			if (i < 0 || i == grid.size() || j < 0 || j == grid[0].size() || grid[i][j] != 1)
			{
				return 0;
			}

			grid[i][j] = id;
			return 1 + dfs(grid, i - 1, j)+
			dfs(grid, i + 1, j)+
			dfs(grid, i, j + 1)+
			dfs(grid, i, j - 1);
		}

		int addition(std::vector<std::vector<int>>& grid, int i, int j)
		{
			int up, down, left, right;
			//������ģ���ϣ��ȥ�أ�Ϊ�˷�ֹ����
			//����������3�ŵ������Ҳ��3�ŵ����Ͳ���������
			set.clear();
			if (i == 0)
			{
				up = 0;
			}
			else
			{
				if (set.find(grid[i - 1][j]) != set.end())
				{
					up = 0;
				}
				else
				{
					up = map[grid[i - 1][j]];
					set.emplace(grid[i - 1][j]);
				}
			}

			if (i == n - 1)
			{
				down = 0;
			}
			else
			{
				if (set.find(grid[i + 1][j]) != set.end())
				{
					down = 0;
				}
				else
				{
					down = map[grid[i + 1][j]];
					set.emplace(grid[i + 1][j]);
				}
			}

			if (j == 0)
			{
				left = 0;
			}
			else
			{
				if (set.find(grid[i][j - 1]) != set.end())
				{
					left = 0;
				}
				else
				{
					left = map[grid[i][j - 1]];
					set.emplace(grid[i][j - 1]);
				}
			}

			if (j == n - 1)
			{
				right = 0;
			}
			else
			{
				if (set.find(grid[i][j + 1]) != set.end())
				{
					right = 0;
				}
				else
				{
					right = map[grid[i][j+1]];
					set.emplace(grid[i][j + 1]);
				}
			}

			return up + down + left + right + 1;

		}

		int largestIsland(std::vector<std::vector<int>>& grid) {
			id = 2;
			n = grid.size();
			
			int ans = 0;
			
			map.clear();

			//ÿ����һ��½�ؾ͵���dfs��Ⱦ��˳���š�
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if (grid[i][j] == 1)
					{
						map.emplace(id,dfs(grid, i, j));
						id++;
					}
				}
			}
			cnt.resize(id);


			//�������ŵ�ͼ���������0���͵���addition�������鿴���0�����������ж���½�أ���������
			for (int i = 0; i < grid.size(); i++)
			{
				for (int j = 0; j < grid[0].size(); j++)
				{
					if (grid[i][j] == 0)
					{
						ans = std::max(ans, addition(grid, i, j));
					}
				}
			}

			return ans == 0 ? n * n : ans;

		}
	};
}

