// 水资源分配优化
// 村里面一共有 n 栋房子。我们希望通过建造水井和铺设管道来为所有房子供水。
// 对于每个房子 i，我们有两种可选的供水方案：一种是直接在房子内建造水井
// 成本为 wells[i - 1] （注意 -1 ，因为 索引从0开始 ）
// 另一种是从另一口井铺设管道引水，数组 pipes 给出了在房子间铺设管道的成本，
// 其中每个 pipes[j] = [house1j, house2j, costj] 
// 代表用管道将 house1j 和 house2j连接在一起的成本。连接是双向的。
// 请返回 为所有房子都供水的最低总成本
// 测试链接 : https://leetcode.cn/problems/optimize-water-distribution-in-a-village/

#include<vector>
#include<array>
#include<algorithm>
namespace
{
	std::vector<int> fathers;
	int find(int num)
	{
		if (num == fathers[num])
		{
			return num;
		}

		int result = find(fathers[num]);
		fathers[num] = result;
		return result;
	}

	bool Union(int a, int b)
	{
		int fa = find(a);
		int fb = find(b);

		if (fa != fb)
		{
			fathers[fa] = fb;
			return true;
		}
		else
		{
			return false;
		}
	}
	int minCostToSupplyWater(int n, std::vector<int>& wells, std::vector<std::vector<int>>& pipes)
	{
		//直接在房子内建水井可以看成有另外的一个水源地往各个房子铺设管道
		for (int i = 1; i <= n; i++)
		{
			pipes.push_back({ i, n + 1, wells[i - 1] });
		}

		fathers.resize(n+2);
		for (int i = 1; i <= n+1; i++)
		{
			fathers[i] = i;
		}

		std::sort(pipes.begin(), pipes.end(), [](std::vector<int>& a, std::vector<int>& b)
			{
				return a[2] < b[2];
			});

		int ans = 0;
		for (auto& col : pipes)
		{
			if (Union(col[0], col[1]))
			{
				ans += col[2];
			}
		}

		return ans;

	}
}