//https://leetcode.cn/problems/nth-magical-number/description/
#include<cmath>
#include<utility>
namespace Welly
{
    class Solution {
        using LL = long long int;
    public:

        LL lcm(LL a, LL b)
        {
            return a / (gcd(a, b)) * b;
        }

        LL gcd(LL a, LL b)
        {
            if (b == 0 || a == 0)
            {
                return a == 0 ? b : a;
            }

            LL remainder = a % b;
            while (remainder != 0)
            {
                a = b;
                b = remainder;
                remainder = a % b;
            }

            return b;
        }

        int nthMagicalNumber(int n, int a, int b) {
            LL range = (LL)n * (LL)std::min(a, b);
            LL Lcm = lcm(a, b);
            LL l = 1;
            LL r = range;
            LL ans = 0;
            LL m = 0;
            while (l < r)
            {
                m = (l + r) / 2;
                if ((m / a + m / b - m / Lcm) >= n)
                {
                    ans = m;
                    r = m;
                }
                else
                {
                    l = m+1;
                }
            }

            return static_cast<int>(ans % 1000000007);
        }
    };
        
    
}