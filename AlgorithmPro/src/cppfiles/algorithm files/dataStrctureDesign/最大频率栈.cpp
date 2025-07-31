#include<vector>
#include<unordered_map>
#include "pch.h"
namespace
{
    class FreqStack {

    private:
        std::unordered_map<int, std::vector<int>> dataMap;
        std::unordered_map<int, int> freqMap;
        int maxCnt;

        int Max(int a, int b)
        {
            return a > b ? a : b;
        }

    public:
        FreqStack(): maxCnt(0) {

        }

        void push(int val) {

            freqMap[val]++;
            int curTopTimes = freqMap[val];
            dataMap[curTopTimes].push_back(val);
            maxCnt = Max(maxCnt, curTopTimes);
        }

        int pop() {
            int ans = dataMap[maxCnt].back();
            freqMap[ans]--;
            if (freqMap[ans] == 0)
            {
                freqMap.erase(ans);
            }

            dataMap[maxCnt].pop_back();
            if (dataMap[maxCnt].empty())
            {
                dataMap.erase(maxCnt);
                maxCnt--;
            }
          
            return ans;
        }
    };
}