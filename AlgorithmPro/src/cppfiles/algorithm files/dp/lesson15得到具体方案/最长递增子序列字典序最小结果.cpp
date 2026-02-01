// 最长递增子序列字典序最小的结果
// 给定数组arr，设长度为n
// 输出arr的最长递增子序列
// 如果有多个答案，请输出其中字典序最小的
// 注意这道题的字典序设定（根据提交的结果推论的）：
// 每个数字看作是单独的字符，比如120认为比36的字典序大
// 保证从左到右每个数字尽量小
// 测试链接 : https://www.nowcoder.com/practice/30fb9b3cab9742ecae9acda1c75bf927
// 测试链接 : https://www.luogu.com.cn/problem/T386911

#include<vector>
#include<iostream>
#include<climits>
namespace
{
	constexpr int MAXN = 100005;
	int n;
	std::vector<int> arr;
	std::vector<int> ends;
	std::vector<int> dp;
	std::vector<int> ans;

	void build()
	{
		ends.assign(n, INT_MAX);
		ans.assign(n + 2, INT_MAX);
	}

	int LIS()
	{
		ends[0] = arr[0];
		dp[0] = 1;
		int endSize = 1;
		int longest = dp[0];
		for (int i = 1; i < n; i++)
		{
			int num = arr[i];
			int left = 0;
			int right = n-1;
			int pos = 0;
			while (left <= right)
			{
				int middle = left + (right - left) / 2;
				if (ends[middle] >= num)
				{
					pos = middle;
					right = middle - 1;
				}
				else
				{
					left = middle + 1;
				}
			}
			ends[pos] = num;
			dp[i] = pos + 1;
			longest = std::max(longest, dp[i]);
		}
		return longest;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		std::cout.tie(nullptr);
		arr.resize(MAXN);
		dp.resize(MAXN);
		ends.resize(MAXN,INT_MAX);
		ans.resize(MAXN, INT_MAX);

		while (std::cin >> n)
		{
			build();

			for (int i = 0; i < n; i++)
			{
				std::cin >> arr[i];
			}

			int longest = LIS();

			for (int i = 0; i < longest; i++)
			{
				ans[i] = 0;
			}

			int cur_target = longest;
			for (int i = n - 1; i >= 0 && cur_target > 0; i--) {
				if (dp[i] == cur_target) {
					ans[cur_target - 1] = arr[i];
					cur_target--;
				}
			}

			for (int i = 0; i < longest-1; i++)
			{
				std::cout << ans[i] << " ";
			}

			std::cout << ans[longest - 1] << "\n";
		}

	}
}