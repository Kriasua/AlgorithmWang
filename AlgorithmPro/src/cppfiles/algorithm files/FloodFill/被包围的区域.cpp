// ��Χ�Ƶ�����
// ����һ�� m x n �ľ��� board ���������ַ� 'X' �� 'O' ���ҵ����б� 'X' Χ�Ƶ�����
// ������Щ���������е� 'O' �� 'X' ��䡣
// �������� : https://leetcode.cn/problems/surrounded-regions/

#include<vector>
namespace
{
	class Solution {
	public:

		void dfs(std::vector<std::vector<char>>& board, int i, int j)
		{
			if (i < 0 || i == board.size() || j < 0 || j == board[0].size() || board[i][j] != 'O')
			{
				return;
			}

			board[i][j] = 'a';
			dfs(board,i-1,j);
			dfs(board,i+1,j);
			dfs(board,i,j+1);
			dfs(board,i,j-1);
		}

		void solve(std::vector<std::vector<char>>& board) {

			//�ú�ˮ���ķ���

			//ǰ����for loop�����������������ߣ�һ�����ֱ߽���'O'���͵���dfs��Ⱦ��'a'
			for (int i = 0; i < board[0].size(); i++)
			{
				if (board[0][i] == 'O')
				{
					dfs(board, 0, i);
				}

				if (board[board.size() - 1][i] == 'O')
				{
					dfs(board, board.size() - 1, i);
				}
			}

			for (int j = 1; j < board.size(); j++)
			{
				if (board[j][0] == 'O')
				{
					dfs(board, j, 0);
				}

				if (board[j][board[0].size() - 1] == 'O')
				{
					dfs(board, j, board[0].size() - 1);
				}
			}

			//��������������
			for (int i = 0; i < board.size(); i++)
			{
				for (int j = 0; j < board[0].size(); j++)
				{
					if (board[i][j] == 'O')
					{
						board[i][j] = 'X';
					}
					
					if (board[i][j] == 'a')
					{
						board[i][j] = 'O';
					}
				}
			}
		}
	};
}