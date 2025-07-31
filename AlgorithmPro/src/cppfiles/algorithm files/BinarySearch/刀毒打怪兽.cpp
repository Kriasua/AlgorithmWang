
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
}

