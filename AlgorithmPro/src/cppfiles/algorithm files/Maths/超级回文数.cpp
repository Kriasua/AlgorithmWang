/*如果一个正整数自身是回文数，而且它也是一个回文数的平方，那么我们称这个数为 超级回文数 。
现在，给你两个以字符串形式表示的正整数 left 和 right  ，统计并返回区间 [left, right] 
中的 超级回文数 的数目。*/
#include<string>
#include<cmath>
#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
namespace Welly
{
    class Solution {
    using LL = long long int;
    public:

        bool isPalindrome2(LL x) {

            if (x < 0)
            {
                return false;
            }

            LL mask = 1;
            while ((x / mask) >= 10)
            {
                mask *= 10;
            }

            while (x != 0)
            {
                if (x % 10 != x / mask)
                {
                    return false;
                }
                x = x % mask / 10;
                mask /= 100;
            }

            return true;
        }

        bool check(LL left, LL right, LL num)
        {
            if (num >= left && num <= right && isPalindrome2(num))
            {
                return true;
            }

            return false;
        }

        LL evenMaker(LL num)
        {
            LL ans = num;
            while (num != 0)
            {
                ans = ans * 10 + (num % 10);
                num /= 10;
            }

            return ans;
        }

        LL oddMaker(LL num)
        {
            LL ans = num;
            num /= 10;
            while (num != 0)
            {
                ans = ans * 10 + (num % 10);
                num /= 10;
            }

            return ans;
        }

        int superpalindromesInRange(std::string left, std::string right) {
            LL l = std::stoll(left);
            LL r = std::stoll(right);
            LL limit = static_cast<long long>(std::sqrt(r));
            int ans = 0;
            LL evenSeed, oddSeed;
            LL seed2 = 1;
            do {
                evenSeed = evenMaker(seed2);
                oddSeed = oddMaker(seed2);
                if (evenSeed <= limit && check(l, r, evenSeed * evenSeed))
                {
                    ans++;
                }
                if (oddSeed <= limit && check(l, r, oddSeed * oddSeed))
                {
                    ans++;
                }
                seed2++;
            } while (oddSeed <= limit);

            return ans;
        }
    };

    //打表法，超快！
    class Solution2 {
        using LL = long long int;
    public:

        int superpalindromesInRange(std::string left, std::string right) {
            LL l = std::stoll(left);
            LL r = std::stoll(right);
            std::vector<LL> table{ 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004, 10000000200000001, 10002000300020001, 10004000600040001, 10020210401202001, 10022212521222001, 10024214841242001, 10201020402010201, 10203040504030201, 10205060806050201, 10221432623412201, 10223454745432201, 12100002420000121, 12102202520220121, 12104402820440121, 12122232623222121, 12124434743442121, 12321024642012321, 12323244744232321, 12343456865434321, 12345678987654321, 40000000800000004, 40004000900040004, 1000000002000000001, 1000220014100220001, 1002003004003002001, 1002223236323222001, 1020100204020010201, 1020322416142230201, 1022123226223212201, 1022345658565432201, 1210000024200000121, 1210242036302420121, 1212203226223022121, 1212445458545442121, 1232100246420012321, 1232344458544432321, 1234323468643234321, 4000000008000000004 };
            int a = 0;
           
            while (l > table[a])
            {
                a++;
            }
            int b = a;
            while (r > table[b])
            {
                b++;
            }

            return b - a;
            
        }
    };
}





