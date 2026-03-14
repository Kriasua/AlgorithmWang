//搜索二维矩阵
//https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-100-liked

#include<vector>
namespace
{
	//纯暴力法
	class Solution1 {
	public:
		bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
			int m = matrix.size();
			int n = matrix[0].size();

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n; j++)
				{
					if (target == matrix[i][j])
					{
						return true;
					}
				}
			}
			return false;
		}
	};

	//普通两次二分
	class Solution2 {
	public:
		bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
			int m = matrix.size();
			int n = matrix[0].size();

			int left = 0;
			int right = m - 1;
			int mid;
			int col = -1;
			int row = -1;
			while (left <= right)
			{
				mid = left + (right - left) / 2;
				if (matrix[mid][0] < target)
				{
					col = mid;
					left = mid + 1;
				}
				else if (matrix[mid][0] == target)
				{
					return true;
				}
				else
				{
					right = mid - 1;
				}
			}

			if (col == -1)
			{
				return false;
			}

			left = 0;
			right = n - 1;
			while (left <= right)
			{
				mid = left + (right - left) / 2;
				if (matrix[col][mid] < target)
				{
					row = mid;
					left = mid + 1;
				}
				else if (matrix[col][mid] == target)
				{
					return true;
				}
				else
				{
					right = mid - 1;
				}
			}
			return false;
		}
	};

	//二维数组看成一维，一次二分
	class Solution3 {
	public:
		bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
			int m = matrix.size();
			int n = matrix[0].size();

			int left = 0;
			int right = m * n - 1;
			int mid;
			int ans = -1;
			while (left <= right)
			{
				int mid = left + (right - left) / 2;
				int i = mid / n;
				int j = mid % n;
				
				if (matrix[i][j] < target)
				{
					ans = mid;
					left = mid + 1;
				}
				else if (matrix[i][j] == target)
				{
					return true;
				}
				else
				{
					right = mid - 1;
				}
			}
			return false;
		}
	};

}