// 一开始1~n范围上的数字都是0，一共有m个操作，每次操作为(l,r,s,e,d)
// 表示在l~r范围上依次加上首项为s、末项为e、公差为d的数列
// m个操作做完之后，统计1~n范围上所有数字的最大值和异或和
// 测试链接 : https://www.luogu.com.cn/problem/P4231
#include<vector>
#include<array>
#include<iostream>
namespace
{
    using LL = long long int;
    int l, r, s, e, N, M;
    constexpr int MAX = 10000005;
    LL sum;
    LL max;
    std::array<LL, MAX> arr;

    int compute(int l, int r, int s, int e)
    {
        return (e - s) / (r - l);
    }

    void set(int l, int r, int s, int e, int d)
    {
        arr[l] += s;
        arr[l + 1] += d - s;
        arr[r + 1] -= d + e;
        arr[r + 2] += e;
    }

    void build()
    {
        for (int i = 1; i <= N; i++)
        {
            arr[i] += arr[i - 1];
        }

        for (int i = 1; i <= N; i++)
        {
            arr[i] += arr[i - 1];
        }
    }

    int main()
    {
        // N 柱子数量
        // M 攻击次数
        std::fill(arr.begin(), arr.end(), 0);
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        while (std::cin >> N >> M)
        {
            std::fill(arr.begin(), arr.begin()+N, 0);
            sum = 0;
            max = 0;
            for (int i = 0; i < M; i++)
            {
                std::cin >> l >> r >> s >> e;
                set(l, r, s, e, compute(l, r, s, e));
            }
            build();
            for (int i = 1; i <= N; i++)
            {
                max = std::max(max, arr[i]);
                sum ^= arr[i];
            }
            std::cout << sum << " " << max << "\n";
        }
    }
}