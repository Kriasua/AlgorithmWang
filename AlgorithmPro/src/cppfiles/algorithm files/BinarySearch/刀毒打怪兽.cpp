// 刀砍毒杀怪兽问题
// 怪兽的初始血量是一个整数hp，给出每一回合刀砍和毒杀的数值cuts和poisons
// 第i回合如果用刀砍，怪兽在这回合会直接损失cuts[i]的血，不再有后续效果
// 第i回合如果用毒杀，怪兽在这回合不会损失血量，但是之后每回合都损失poisons[i]的血量
// 并且你选择的所有毒杀效果，在之后的回合都会叠加
// 两个数组cuts、poisons，长度都是n，代表你一共可以进行n回合
// 每一回合你只能选择刀砍或者毒杀中的一个动作
// 如果你在n个回合内没有直接杀死怪兽，意味着你已经无法有新的行动了
// 但是怪兽如果有中毒效果的话，那么怪兽依然会在血量耗尽的那回合死掉
// 返回至少多少回合，怪兽会死掉
// 数据范围 : 
// 1 <= n <= 10^5
// 1 <= hp <= 10^9
// 1 <= cuts[i]、poisons[i] <= 10^9
// 本题来自真实大厂笔试，找不到测试链接，所以用对数器验证
#include<vector>
namespace
{
	using LL = long long int;
	bool ifKillinXRound(std::vector<int>& cuts, std::vector<int>& poisons, int round, int hp)
	{
		int n = std::min((int)cuts.size(), round);
		
		LL accuracyDamage = 0;
		for (int i = 1; i <= n; i++)
		{
			LL poisonDamage = (LL)poisons[i - 1] * (LL)(round - i);
			accuracyDamage += cuts[i - 1] > poisonDamage ? cuts[i - 1] : poisonDamage;
		}

		if (accuracyDamage >= hp)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int lowestRoundKillMonster(std::vector<int>& cuts, std::vector<int>& poisons, int hp)
	{
		int l = 0;
		int ans = 0;
		int r = hp + 1;
		int m = 0;
		while (l <= r)
		{
			m = l + ((r - l) >> 1);
			if (ifKillinXRound(cuts, poisons, m, hp))
			{
				ans = m;
				r = m - 1;
			}
			else
			{
				l = m + 1;
			}
		}
		return ans;
	}

	int f2(std::vector<int>& cuts, std::vector<int>& poisons, int n)
	{
		//在n回合内最多能打掉多少血
		int size = cuts.size();
		int damage = 0;

		size = std::min(size, n);
		
		for (int i = 0; i < size; i++)
		{
			int curPoisonDamage = poisons[i] * (n - i - 1);
			if (curPoisonDamage > cuts[i])
			{
				damage += curPoisonDamage;
			}
			else
			{
				damage += cuts[i];
			}
		}
		

		return damage;

	}

	int lowestRoundKillMonster1(std::vector<int>& cuts, std::vector<int>& poisons, int hp)
	{
		int left = 0;
		int right = 1000000005;
		int ans = INT_MAX;
		while (left <= right)
		{
			int middle = left + (right - left) / 2;
			int m = f2(cuts, poisons, middle);
			if (m >= hp)
			{
				ans = middle;
				right = middle - 1;
			}
			else
			{
				left = middle + 1;
			}
		}

		return ans;
	}
}

