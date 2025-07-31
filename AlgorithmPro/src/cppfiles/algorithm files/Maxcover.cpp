#include<iostream>
#include<vector>
#include<algorithm>
#include<array>
#include "pch.h"
namespace {

    constexpr int maxN = 10000;

    std::array<std::array<int, 2>, maxN> nums;
    std::vector<int> heap(10000);


    void Swap(std::vector<int>& arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    void heapPop(int& size)
    {
        Swap(heap, 0, size - 1);
        size--;
        int i = 0;
        int l = 1;
        while (l < size)
        {
            int best = l + 1 < size && heap[l + 1] < heap[l] ? l + 1 : l;
            if (heap[i] > heap[best])
            {
                Swap(heap, i, best);
                i = best;
                l = 2 * i + 1;
            }
            else
            {
                break;
            }
        }
    }

    void heapIn(int& size, int in)
    {

        int i = size;
        heap[i] = in;
        size++;
        while (heap[i] < heap[(i - 1) / 2])
        {
            Swap(heap, i, (i - 1) / 2);
            i = (i - 1) / 2;
        }
    }

    int maxCover(std::array<std::array<int, 2>, maxN>& nums, int n)
    {
        int ans = 0;
        int size = 0;

        std::sort(nums.begin(), nums.begin() + n, [](const std::array<int, 2>& a,
            const std::array<int, 2>& b) {
                return a[0] < b[0];
            });


        for (auto it = nums.begin(); it != nums.begin() + n; it++)
        {
            while (size > 0 && heap[0] <= (*it)[0])
            {
                heapPop(size);
            }

            heapIn(size, (*it)[1]);
            ans = std::max(ans, size);
        }


        return ans;
    }


    void Main()
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);


        int n;
        while (std::cin >> n)
        {
            for (int i = 0; i <= n; i++)
            {
                std::cin >> nums[i][0] >> nums[i][1];
            }

            std::cout << maxCover(nums, n) << '\n';

        }
    }

    
}