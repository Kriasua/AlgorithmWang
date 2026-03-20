//n皇后
//https://leetcode.cn/problems/n-queens-ii/description/
#include<vector>
#include<cmath>
namespace
{
	//普通回溯版本
	class Solution1 {
	public:
		int ans;
		bool check(std::vector<int>& path, int i, int j)
		{
			if (i == 0)
			{
				return true;
			}

			for (int row = 0; row < i; row++)
			{
				int col = path[row];
				if (col == j)
				{
					return false;
				}
				if (std::abs(i - row) == std::abs(j - col))
				{
					return false;
				}
			}

			return true;
		}

		void f(std::vector<int>& path, int i)
		{
			if (i == path.size())
			{
				ans++;
				return;
			}

			for (int j = 0; j < path.size(); j++)
			{
				if (check(path, i, j))
				{
					path[i] = j;
					f(path, i + 1);
				}
			}
		}

		int totalNQueens(int n) {
			ans = 0;
			std::vector<int> path(n);
			f(path, 0);
			return ans;
		}
	};

	//位运算版本
	class Solution2 {
	public:
		int ans;

		void f(uint32_t col, uint32_t left, uint32_t right, int i, int n, uint32_t limit)
		{
			if (i == n)
			{
				ans++;
				return;
			}

			uint32_t ban = col | left | right;
			uint32_t pos = ~ban & limit;
			while (pos != 0)
			{
				uint32_t mostRightone = pos & (~pos + 1);
				pos ^= mostRightone;
				f(col | mostRightone, (left | mostRightone) >> 1, (right | mostRightone) << 1, i + 1, n, limit);
			}

		}


		int totalNQueens(int n) {
			ans = 0;
			uint32_t limit = (1 << n) - 1;
			f(0, 0,0,0,n,limit);
			return ans;
		}
	};
}