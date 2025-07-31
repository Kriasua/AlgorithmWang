#include<string>
#include<map>
#include "pch.h"
namespace welly
{
    class Solution {
    public:
        int where;

        void fill(std::map<std::string, int>& map,std::map<std::string, int>& path, std::string& name, int cnt)
        {
            if (!name.empty() || !path.empty())
            {
                cnt = cnt == 0 ? 1 : cnt;
                if (!name.empty())
                {
                    map[name] += cnt;
                }

                else
                {
                    for (const auto& pair : path)
                    {
                        map[pair.first] += pair.second * cnt;
                    }
                }
            }
        }

        std::map<std::string,int> f(std::string& formula, int i)
        {
            std::map<std::string, int> map;
            std::string name;

            std::map<std::string, int> path;
            int cnt=0;
            while (i < formula.size() && formula[i] != ')')
            {
                if ((formula[i] >= 'A' && formula[i] <= 'Z') || formula[i]=='(')
                {
                    fill(map, path, name, cnt);
                    name.clear();
                    path.clear();
                    cnt = 0;

                    if (formula[i] >= 'A' && formula[i] <= 'Z')
                    {
                        name += formula[i++];
                    }
                    else
                    {
                        path = f(formula, i + 1);
                        i = where + 1;
                    }
                }

                else if (formula[i] >= 'a' && formula[i] <= 'z')
                {
                    name += formula[i++];
                }

                else
                {
                    cnt = cnt * 10 + (formula[i++] - '0');
                }

            }

            fill(map, path, name, cnt);
            where = i;
            return map;
        }

        std::string countOfAtoms(std::string formula) {
            where = 0;
            std::map<std::string, int> map = f(formula, 0);
            std::string ans;
            for (const auto& pair : map)
            {
                ans += pair.first;
                if (pair.second > 1)
                {
                    ans += std::to_string(pair.second);
                }
            }

            return ans;
        }
    };
}