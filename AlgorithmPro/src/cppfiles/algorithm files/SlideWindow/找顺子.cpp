//�ҳ�һ�����������е�˳��

#include<vector>
#include<iostream>
namespace
{
	using std::vector;
	vector<vector<int>> findShunzi(vector<int> cards)
	{
		vector<vector<int>> ans;
		vector<int> path;  // ÿ������������˳��

		//��5������17����˼�Ƿֱ����˳�ӵ�������5����6����7.....���д𰸼�����
		for (int cnt = 5; cnt <= 17; cnt++)
		{
			//�������ڣ�l����߽磬r���ұ߽�,counts�ǵ�ǰ�Ѿ����۵�������
			int l = 0;
			int r = 1;
			int counts = 1;
			//�������ƣ���ÿ��rλ��Ϊ��β���ռ���
			for (; r < cards.size(); r++)
			{
				counts++;
				//һ�����ֲ���������l��r������λ�ö�������˳�ӡ�����lֱ���ƶ���rλ��
				if (cards[r] - cards[r - 1] != 1)
				{
					l = r;
					counts = 1;   //����counts
				}

				//��couonts���ڵ�ǰҪ���˳������ʱ��˵���ҵ���һ��𰸣��ռ�
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


