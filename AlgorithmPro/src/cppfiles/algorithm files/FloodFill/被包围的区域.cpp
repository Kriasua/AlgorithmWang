// 被围绕的区域
// 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域
// 并将这些区域里所有的 'O' 用 'X' 填充。
// 测试链接 : https://leetcode.cn/problems/surrounded-regions/

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

			//用洪水填充的方法

			//前两个for loop用来处理上下两条边，一旦发现边界是'O'，就调用dfs感染成'a'
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

			//最后遍历整个棋盘
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