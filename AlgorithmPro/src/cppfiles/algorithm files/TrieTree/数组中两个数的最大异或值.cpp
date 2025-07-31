#include<vector>
#include<cmath>
#include<array>
#include<unordered_set>
namespace
{
    class Solution {
    public:
        const int MAX = 3000001;
        int cnt;
        int high;
        std::vector<std::array<int,2>> trie;

        Solution() : cnt(1)
        {
            trie.resize(MAX, std::array<int,2>{0,0});
        }

        void insert(int num)
        {
            int cur = 1;
            for (int i = high,path; i >= 0; i--)
            {
                path = (num >> i) & 1;
                if (trie[cur][path] == 0)
                {
                    trie[cur][path] = ++cnt;
                }
                cur = trie[cur][path];
            }
        }

        int numberOfLeadingZeros(int num)
        {
            int cnt = 0;
            for (int i = 31; i >= 0; i--)
            {
                if (((num >> i) & 1) == 1)
                {
                    break;
                }
                cnt++;
            }
            return cnt;
        }


        void build(std::vector<int>& nums)
        {
            cnt = 1;
            int max = INT_MIN;
            for (int num : nums) {
                max = std::max(num, max);
            }

            high = 31 - numberOfLeadingZeros(max);

            for (int num : nums)
            {
                insert(num);
            }
        }

        int maxXOR(int num)
        {
            int ans = 0;
            int cur = 1;
            int wish, status;
            for (int i = high; i >= 0; i--)
            {
                status = (num >> i) & 1;
                wish = status ^ 1;
                if (trie[cur][wish] == 0)
                {
                    wish = status;
                }
                ans |= ((status ^ wish) << i);
                cur = trie[cur][wish];
            }
            return ans;
        }

        void clear()
        {
            for (int i = 1; i <= cnt; i++)
            {
                trie[i][0] = 0;
                trie[i][1] = 0;
            }
        }


        int findMaximumXOR(std::vector<int>& nums) {
            build(nums);
            int ans = 0;
            for (int num : nums)
            {
                ans = std::max(ans, maxXOR(num));
            }
            clear();
            return ans;
        }

        //哈希表方法，难想！
        int findMaximumXOR2(std::vector<int>& nums) {
            int max = INT_MIN;
            for (int num : nums) {
                max = std::max(num, max);
            }

            high = 31 - numberOfLeadingZeros(max);
            std::unordered_set<int> set;
            int ans = 0;
            for (int i = high; i >= 0; i--)
            {
                set.clear();
                int better = ans | (1 << i);
                for (int num : nums)
                {
                    num = (num >> i) << i;
                    set.emplace(num);

                    if (set.find(better ^ num) != set.end())
                    {
                        ans = better;
                        break;
                    }
                }

                
            }
            return ans;
        }
    };
}



