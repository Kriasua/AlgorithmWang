#include<string>
#include<vector>
#include<unordered_set>
#include "pch.h"
namespace
{
    class Solution {
    public:
        void f(const std::string& s, int i, int size, std::vector<char>& path, std::unordered_set<std::string>& set)
        {
            if (i == s.length())
            {
                set.emplace(std::string(path.begin(), path.begin() + size));
            }
            else
            {
                path[size] = s[i];
                f(s, i + 1, size + 1, path, set);
                f(s, i + 1, size, path, set);
            }

        }

        std::vector<std::string> generatePermutation(std::string s) {
            std::vector<std::string> ans;
            if (s.empty())
            {
                ans.push_back(s);
                return ans;
            }

            std::vector<char> path(s.length());
            std::unordered_set<std::string> set;
            f(s, 0, 0, path, set);

            for (std::string str : set)
            {
                ans.push_back(str);
            }

            return ans;
        }


        ///////第二种方法：回溯，回复现场

        void f2(const std::string& s, int i, std::vector<char>& path, std::unordered_set<std::string>& set)
        {
            if (i == s.length())
            {
                set.emplace(std::string(path.begin(),path.end()));
            }
            else
            {
                path.push_back(s[i]);
                f2(s, i + 1, path, set);
                path.pop_back();
                f2(s, i + 1, path, set);
            }
        }

        std::vector<std::string> generatePermutation2(std::string s)
        {
            std::vector<std::string> ans;
            if (s.empty())
            {
                ans.push_back(s);
                return ans;
            }
            std::vector<char> path;
            std::unordered_set<std::string> set;

            f2(s, 0, path, set);
            for (std::string str : set)
            {
                ans.push_back(str);
            }

            return ans;
        }
    };
}