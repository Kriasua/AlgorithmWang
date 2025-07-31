//找出一副手牌里所有的顺子

#include<vector>
#include<iostream>
namespace
{
	using std::vector;
	vector<vector<int>> findShunzi(vector<int> cards)
	{
		vector<vector<int>> ans;
		vector<int> path;  // 每个符合条件的顺子

		//从5遍历到17，意思是分别计算顺子的牌数是5，是6，是7.....所有答案加起来
		for (int cnt = 5; cnt <= 17; cnt++)
		{
			//滑动窗口，l是左边界，r是右边界,counts是当前已经积累的牌数量
			int l = 0;
			int r = 1;
			int counts = 1;
			//遍历手牌，以每个r位置为结尾，收集答案
			for (; r < cards.size(); r++)
			{
				counts++;
				//一旦发现不连续，从l到r的所有位置都不会有顺子。所以l直接移动到r位置
				if (cards[r] - cards[r - 1] != 1)
				{
					l = r;
					counts = 1;   //重置counts
				}

				//当couonts等于当前要求的顺子牌数时，说明找到了一组答案，收集
				if (counts == cnt)
				{
					path.clear();
					for (int i = l; i <= r; i++)
					{
						path.push_back(cards[i]);
					}
					ans.push_back(path);
					l++;
					counts--;

				}
			}
		}
		return ans;
	}
}


