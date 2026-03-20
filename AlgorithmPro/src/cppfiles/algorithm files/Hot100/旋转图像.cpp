//Ðý×ªÍ¼Ïñ
//https://leetcode.cn/problems/rotate-image/?envType=study-plan-v2&envId=top-100-liked
#include<vector>
namespace
{
	class Solution {
	public:
		void f(int x, int y, int length, std::vector<std::vector<int>>& matrix)
		{
			if (length == 1 || length == 0)
			{
				return;
			}

			int x1 = x;
			int y1 = y;
			int x2 = x1;
			int y2 = y1 + (length - 1);
			int x3 = x1 + (length - 1);
			int y3 = y1 + (length - 1);
			int x4 = x1 + (length - 1);
			int y4 = y1;

			for (int i = 0; i < length - 1; i++)
			{
				int tmp1 = matrix[x1][y1];
				int tmp2 = matrix[x2][y2];
				int tmp3 = matrix[x3][y3];
				int tmp4 = matrix[x4][y4];
				matrix[x1][y1] = tmp4;
				matrix[x2][y2] = tmp1;
				matrix[x3][y3] = tmp2;
				matrix[x4][y4] = tmp3;
				y1++;
				x2++;
				y3--;
				x4--;
			}

			f(x + 1, y + 1, length - 2, matrix);
		}

		void rotate(std::vector<std::vector<int>>& matrix) {
			f(0, 0, matrix.size(), matrix);
		}
	};
}