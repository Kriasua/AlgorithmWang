// 机器人跳跃问题
// 机器人正在玩一个古老的基于DOS的游戏
// 游戏中有N+1座建筑，从0到N编号，从左到右排列
// 编号为0的建筑高度为0个单位，编号为i的建筑的高度为H(i)个单位
// 起初机器人在编号为0的建筑处
// 每一步，它跳到下一个（右边）建筑。假设机器人在第k个建筑，且它现在的能量值是E
// 下一步它将跳到第个k+1建筑
// 它将会得到或者失去正比于与H(k+1)与E之差的能量
// 如果 H(k+1) > E 那么机器人就失去H(k+1)-E的能量值，否则它将得到E-H(k+1)的能量值
// 游戏目标是到达第个N建筑，在这个过程中，能量值不能为负数个单位
// 现在的问题是机器人以多少能量值开始游戏，才可以保证成功完成游戏
// 测试链接 : https://www.nowcoder.com/practice/7037a3d57bbd4336856b8e16a9cafd71

#include <iostream>
#include <array>
namespace
{
	constexpr int MAX = 100001;
	std::array<int, MAX> nums;
	int N;

	bool f(int energy, int maxheight)
	{

		for (int i = 1; i <= N; i++)
		{
			energy += (energy - nums[i]);
			if (energy < 0)
			{
				return false;
			}
			if (energy >= maxheight)
			{
				return true;
			}
		}

		return true;
	}

	int findLowestEnergy(int l, int r, int MaxHeight)
	{
		int Ans = 0;

		int m = 0;
		while (l <= r)
		{
			m = l + ((r - l) >> 1);
			if (f(m, MaxHeight))
			{
				Ans = m;
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}

		return Ans;
	}

	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);
		nums[0] = 0;
		while (std::cin >> N)
		{
			int l = 0;
			int r = 0;
			for (int i = 1; i <= N; i++)
			{
				std::cin >> nums[i];
				r = std::max(r, nums[i]);
			}

			std::cout << findLowestEnergy(l, r, r) << "\n";
		}
	}
}
