//������r��e��d�����ַ�ƴ���ַ��������ƴ�������ַ�����
// ���ҽ���1������>=2�Ļ����Ӵ�����ô����ַ�������Ϊ"�ô�"
// ���س���Ϊn�����п��ܵ��ַ����У��ô��ж��ٸ�
// ����� 1000000007 ȡģ�� 1 <= n <= 10^9
// ʾ����
// n = 1, ���0
// n = 2, ���3
// n = 3, ���18
#include<string>
#include<vector>
#include<iostream>
namespace
{
	bool isHuiwen(const std::vector<char>& str, int a, int b)
	{
		while (a <= b)
		{
			if (str[a] != str[b])
			{
				return false;
			}
				
			a++;
			b--;
		}

		return true;
	}



	int f(std::vector<char>& path, int i)
	{
		if (i == path.size())
		{
			int cnt = 0;
			for (int i = 0; i < path.size(); i++)
			{
				for (int j = i + 1; j < path.size(); j++)
				{
					if (isHuiwen(path, i, j))
					{
						cnt++;
					}
				}
			}

			return cnt == 1 ? 1 : 0;
		}

		int ans = 0;
		path[i] = 'r';
		ans += f(path, i + 1);
		path[i] = 'e';
		ans += f(path, i + 1);
		path[i] = 'd';
		ans += f(path, i + 1);

		return ans;

	}

	int findGoodString(int n)
	{
		std::vector<char> path(n);
		return f(path, 0);
	}
}



