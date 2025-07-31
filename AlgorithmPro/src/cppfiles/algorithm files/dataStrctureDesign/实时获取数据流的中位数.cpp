#include<queue>
#include<cstdlib>
#include "pch.h"
namespace
{
    class MedianFinder {

    private:

        std::priority_queue<int> max_heap;
        std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;

    public:
        MedianFinder() {

        }

        void balance()
        {
            int difference = min_heap.size() - max_heap.size();
            if (std::abs(static_cast<int>(min_heap.size() - max_heap.size())) == 2)
            {
                if (min_heap.size() > max_heap.size())
                {
                    max_heap.emplace(min_heap.top());
                    min_heap.pop();
                }

                else
                {
                    min_heap.emplace(max_heap.top());
                    max_heap.pop();
                }
            }
        }

        void addNum(int num) {

            if (max_heap.empty() || num <= max_heap.top())
            {
                max_heap.emplace(num);
            }
            else
            {
                min_heap.emplace(num);
            }

            balance();

            

        }

        double findMedian() {
            if (min_heap.size() == max_heap.size())
            {
                return 0.5 * (min_heap.top() + max_heap.top());
            }
            else
            {
                return min_heap.size() > max_heap.size() ? min_heap.top() : max_heap.top();
            }
        }
    };
}