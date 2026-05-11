// 乘法快速幂模版
// 求a的b次方，对p取模的结果
// 测试链接 : https://www.luogu.com.cn/problem/P1226

#include<iostream>

namespace
{
	int a, b, p;
	int main()
	{
		std::ios::sync_with_stdio(false);
		std::cin.tie(nullptr);

		while (std::cin >> a >> b >> p)
		{
			long long int ans = 1;
			long long int x = a;
			int B = b;
			while (b != 0)
			{
				if ((1 & b) != 0)
				{
					ans = (ans * x) % p;
				}
				x = (x * x) % p;
				b >>= 1;
			}

			std::cout << a << "^" << B << " mod " << p << "=" << ans << "\n";
		}
	}
}