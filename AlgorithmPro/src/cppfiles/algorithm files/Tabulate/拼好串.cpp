//可以用r、e、d三种字符拼接字符串，如果拼出来的字符串中
// 有且仅有1个长度>=2的回文子串，那么这个字符串定义为"好串"
// 返回长度为n的所有可能的字符串中，好串有多少个
// 结果对 1000000007 取模， 1 <= n <= 10^9
// 示例：
// n = 1, 输出0
// n = 2, 输出3
// n = 3, 输出18
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



