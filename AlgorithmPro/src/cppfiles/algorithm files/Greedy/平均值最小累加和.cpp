// 平均值最小累加和
// 给定一个数组arr，长度为n
// 再给定一个数字k，表示一定要将arr划分成k个集合
// 每个数字只能进一个集合
// 返回每个集合的平均值都累加起来的最小值
// 平均值向下取整
// 1 <= n <= 10^5
// 0 <= arr[i] <= 10^5
// 1 <= k <= n
// 来自真实大厂笔试，没有在线测试，对数器验证

#include<vector>
#include<algorithm>
namespace
{
	int minAveSum(std::vector<int>& arr, int k)
	{
		std::sort(arr.begin(), arr.end());
		int ans = 0;
		for (int i = 0; i < k - 1; i++)
		{
			ans += arr[i];
		}

		int last = 0;
		for (int i = k - 1; i < arr.size(); i++)
		{
			last += arr[i];
		}

		last /= (arr.size() - k + 1);
		ans += last;
		return ans;
	}
}