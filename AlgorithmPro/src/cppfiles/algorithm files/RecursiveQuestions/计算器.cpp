#include<vector>
#include<string>
#include<iostream>
#include "pch.h"
namespace welly
{
    
    /// 力扣第227题，不带括号版本
    
    class Solution {
    public:
        
        void push(std::vector<int>& nums, std::vector<char>& oops, int cur, char c)
        {
            if ((oops.empty()) || (oops.back() != '*' && oops.back() != '/'))
            {
                oops.push_back(c);
                nums.push_back(cur);
            }
            else if(oops.back() == '*')
            {
                cur *= nums.back();
                nums.pop_back();
                oops.pop_back();
                oops.push_back(c);
                nums.push_back(cur);
            }
            else
            {
                cur = nums.back() / cur;
                nums.pop_back();
                oops.pop_back();
                oops.push_back(c);
                nums.push_back(cur);
            }
        }

        int compute(std::vector<int>& nums, std::vector<char>& oops)
        {
            int ans = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                ans += oops[i - 1] == '+' ? nums[i] : -nums[i];
            }

            return ans;
        }

        int calculate(std::string s) {
            std::vector<int> nums;
            std::vector<char> oops;
            int cur = 0;
            
            for (int i = 0; i < s.size(); i++)
            {
                if (s[i] == ' ')
                {
                    continue;
                }

                else if (s[i] >= '0' && s[i] <= '9')
                {
                    cur = cur * 10 + (s[i] - '0');
                }

                else
                {
                    push(nums, oops, cur, s[i]);
                    cur = 0;
                }
            }

            push(nums, oops, cur, '+');

            
            int sum = compute(nums, oops);
            return sum;
        }
    };


    
    /////////////////////带括号，嵌套，用递归写////////////
    
    class Solution2 {
    public:
        int where;
        void push(std::vector<int>& nums, std::vector<char>& oops, int cur, char c)
        {
            if ((oops.empty()) || (oops.back() != '*' && oops.back() != '/'))
            {
                oops.push_back(c);
                nums.push_back(cur);
            }
            else if (oops.back() == '*')
            {
                cur *= nums.back();
                nums.pop_back();
                oops.pop_back();
                oops.push_back(c);
                nums.push_back(cur);
            }
            else
            {
                cur = nums.back() / cur;
                nums.pop_back();
                oops.pop_back();
                oops.push_back(c);
                nums.push_back(cur);
            }
        }

        int compute(std::vector<int>& nums, std::vector<char>& oops)
        {
            int ans = nums[0];

            for (int i = 1; i < nums.size(); i++)
            {
                ans += oops[i - 1] == '+' ? nums[i] : -nums[i];
            }

            return ans;
        }

        int f(std::string& s, int i)
        {
            std::vector<int> nums;
            std::vector<char> oops;
            int cur = 0;
            while ((i < s.size()) && s[i] != ')')
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    cur = cur * 10 + (s[i++] - '0');
                }

                else if (s[i] == '(')
                {
                    cur = f(s, i + 1);
                    i = where + 1;
                }

                else
                {
                    push(nums, oops, cur, s[i++]);
                    cur = 0;
                   
                }
            }
            push(nums, oops, cur, '+');
            int sum = compute(nums, oops);
            where = i;
            return sum; 
        }

        int calculate(std::string s) {
            where = 0;              
            return f(s, 0);
        }
    };
}


