// 单词搜索（无法改成动态规划）
// 给定一个 m x n 二维字符网格 board 和一个字符串单词 word
// 如果 word 存在于网格中，返回 true ；否则，返回 false 。
// 单词必须按照字母顺序，通过相邻的单元格内的字母构成
// 其中"相邻"单元格是那些水平相邻或垂直相邻的单元格
// 同一个单元格内的字母不允许被重复使用
// 测试链接 : https://leetcode.cn/problems/word-search/

#include<vector>
#include<string>
namespace
{
	class Solution {
	public:
		bool f(std::vector<std::vector<char>>& board, std::string word, int x, int y, int i)
		{
			//已经找到了最后一个字母
			if (i == word.size())
			{
				return true;
			}	

			//越界了,或者遇到了已经访问过的格子
			if (x < 0 || y < 0 || x == board.size() || y == board[0].size() || board[x][y] == '#')
			{
				return false;
			}

			//当前格子的字母不对
			if (board[x][y] != word[i])
			{
				return false;
			}

			//标记为已经访问过
			char tmp = board[x][y];
			board[x][y] = '#';
			bool ans = false;

			//往四个方向尝试
			ans = f(board, word, x - 1, y, i + 1) ||
			f(board, word, x + 1, y, i + 1) ||
			f(board, word, x, y - 1, i + 1) ||
			f(board, word, x, y + 1, i + 1);

			//返回前把格子改回来
			board[x][y] = tmp;
			return ans;
			
		}

		bool exist(std::vector<std::vector<char>>& board, std::string word) {
			int n = board.size();
			int m = board[0].size();
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					if (f(board, word, i, j, 0))
					{
						return true;
					}
				}
			}
			return false;
			
		}
	};
}