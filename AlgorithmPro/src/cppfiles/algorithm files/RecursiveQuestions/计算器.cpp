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

    //第二次做
	class Solution3 {
	public:

        void push(std::vector<int>& nums, std::vector<char>& ops, int cur, char op)
        {
			if (ops.empty())
			{
				nums.push_back(cur);
				ops.push_back(op);
			}
			else if (ops.back() == '+' || ops.back() == '-')
			{
				nums.push_back(cur);
				ops.push_back(op);
			}
			else if (ops.back() == '*')
			{
				int tmp = cur * nums.back();
				nums.pop_back();
				ops.pop_back();
				nums.push_back(tmp);
				ops.push_back(op);
			}
			else
			{
				int tmp = nums.back() / cur;
				nums.pop_back();
				ops.pop_back();
				nums.push_back(tmp);
				ops.push_back(op);
			}
            
        }

        std::vector<int> f(std::string s, int i)
        {
            std::vector<int> nums;
            std::vector<char> ops;
            int cur = 0;
            ops.push_back('+');
            int ans = 0;
            while (i < s.size())
            {
                if (s[i] >= '0' && s[i] <= '9')
                {
                    cur = cur * 10 + (s[i] - '0');
                    i++;
                }

                else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
                {
                    push(nums, ops, cur, s[i]);
                    cur = 0;
                    i++;
                }
                else if (s[i] == '(')
                {
                    std::vector<int> val = f(s, i + 1);
                    cur = val[0];
                    i = val[1] + 1;
                }
                else
                {
                    push(nums, ops, cur, '+');
                    for (int j = 0; j < nums.size(); j++)
                    {
                        if (ops[j] == '+')
                        {
                            ans += nums[j];
                        }
                        else
                        {
                            ans -= nums[j];
                        }
                    }
                    return { ans,i };
                }
            }

            push(nums, ops, cur, '+');
			for (int i = 0; i < nums.size(); i++)
			{
				if (ops[i] == '+')
				{
					ans += nums[i];
				}
				else
				{
					ans -= nums[i];
				}
			}
            return { ans,i };
        }

		int calculate(std::string s) {
            return f(s, 0)[0];
		}
	};
}


