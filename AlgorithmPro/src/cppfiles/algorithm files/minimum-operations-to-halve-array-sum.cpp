#include <vector>
#include<iostream>
#include "pch.h"
namespace {
    class Solution {

    public:

        std::vector<long> myheap;
        int size = 0;

        void Swap(int a, int b)
        {
            long temp = myheap[a];
            myheap[a] = myheap[b];
            myheap[b] = temp;
        }

        void heapInsert(long x)
        {
            myheap.push_back(x);
            int i = size++;
            while (myheap[i] > myheap[(i - 1) / 2])
            {
                Swap(i, (i - 1) / 2);
                i = (i - 1) / 2;
            }

        }

        void heapify(int i)
        {

            int l = 2 * i + 1;

            while (l < size)
            {
                int best = l + 1 < size && myheap[l + 1] > myheap[l] ? l + 1 : l;

                if (myheap[i] < myheap[best])
                {
                    Swap(i, best);
                    i = best;
                    l = 2 * i + 1;
                }
                else
                {
                    break;
                }
            }
        }

        int halveArray(std::vector<int>& nums) {
            size = nums.size();
            myheap.resize(size);
            long sum = 0;
            long ans = 0;
            int counts = 0;
            for (int i = size - 1; i >= 0; i--)
            {
                myheap[i] = static_cast<long>(nums[i]) << 20;
                sum += myheap[i];
                heapify(i);
            }


            while (ans < sum / 2)
            {
                myheap[0] = myheap[0] / 2;
                ans += myheap[0];
                heapify(0);
                counts++;
            }
            return counts;

        }

    };
}

