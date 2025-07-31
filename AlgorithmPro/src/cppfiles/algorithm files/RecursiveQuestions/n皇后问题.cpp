#include<vector>
#include<cmath>
#include<iostream>
namespace Welly
{
    class Solution {
    public:

        bool check(std::vector<int> path, int i, int j)
        {
            //i: cur row
            //j: cur col
            for (int k = 0; k < i; k++)
            {
                
                if ((j == path[k]) || (std::abs(i - k) == std::abs(j - path[k])))
                {
                    return false;
                }
            }
            return true;
        }

        int f1(int i, std::vector<int>& path, int n)
        {
            if (i == n)
            {
                return 1;
            }

            int ans = 0;
            for (int j = 0; j < n; j++)
            {
                if (check(path, i, j))
                {
                    path[i] = j;
                    ans += f1(i + 1, path, n);
                }
            }
            
            return ans;

        }

        int totalNQueens(int n) {
            std::vector<int> ans(n);
            
            return f1(0, ans, n);
        }
    };

  
    /////////位运算版本///////////////////////////
    class Solution2 {
    public:

        int f2(unsigned int limit, unsigned int col, unsigned int left, unsigned int right)
        {
            if (col == limit)
            {
                return 1;
            }

            unsigned int ban = col | left | right;  //1不可， 0可

            ban = ~ban & limit;      //转成了1可， 0不可
            unsigned int candidate = ban;
            unsigned int place;
            int ans = 0;
            while (candidate != 0)
            {
                place = candidate & (~candidate + 1);
                candidate ^= place;
                ans += f2(limit, col | place, (left | place) >> 1, (right | place) << 1);
            }
            return ans;
        }

        int totalNQueens(int n) {
            if (n < 1)
            {
                return 0;
            }

            unsigned int limit = (1 << n) - 1;
            return f2(limit, 0, 0, 0);
        }
    };
}





