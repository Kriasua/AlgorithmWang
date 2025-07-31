#include<string>

namespace
{
    //转成字符串，很慢！
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }

        std::string num = std::to_string(x);
        int a = 0;
        int b = num.size() - 1;

        while (a <= b)
        {
            if (num[a] != num[b])
            {
                return false;
            }
            a++;
            b--;
        }

        return true;
    }


    //直接数值判断，很快！
    bool isPalindrome2(int x) {

        if (x < 0)
        {
            return false;
        }

        int mask = 1;
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
            x = x % mask /10;
            mask /= 100;
        }

        return true;
    }
}