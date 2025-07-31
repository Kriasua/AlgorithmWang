#include <iostream>
#include"Random.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <random>
//#include"Heap.h"
#include <functional>
#include <queue>
#include <climits>
#include<array>
#include "pch.h"

namespace {


    using std::vector;


    void Swap(vector<int>& arr, int a, int b)
    {
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    vector<int> help;

    //void Merge(vector<int>& arr, int L, int R)
    //{
    //    if (L == R)
    //    {
    //        return;
    //    }
    //
    //    int m = (L + R) >> 1;
    //    Merge(arr, L, m);
    //    Merge(arr, m + 1, R);
    //
    //    int a = L;
    //    int b = m + 1;
    //    int i = L;
    //
    //    while (a <= m && b <= R)
    //    {
    //        help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
    //    }
    //
    //    while (a <= m)
    //    {
    //        help[i++] = arr[a++];
    //    }
    //
    //    while (b <= R)
    //    {
    //        help[i++] = arr[b++];
    //    }
    //
    //    for (int i = L; i <= R; i++)
    //    {
    //        arr[i] = help[i];
    //    }
    //}

    void Merge(vector<int>& arr, int L, int R)
    {
        if (L >= R)
            return;


        int m = (L + R) >> 1;


        Merge(arr, L, m);
        Merge(arr, m + 1, R);


        int a = L;
        int b = m + 1;
        int i = L;

        while (a <= m && b <= R)
        {
            help[i++] = arr[a] <= arr[b] ? arr[a++] : arr[b++];
        }

        while (a <= m)
        {
            help[i++] = arr[a++];
        }

        while (b <= R)
        {
            help[i++] = arr[b++];
        }

        for (int i = L; i <= R; i++)
        {
            arr[i] = help[i];
        }


    }

    void MergeSort(vector<int>& arr)
    {

        help.resize(arr.size());
        Merge(arr, 0, arr.size() - 1);

    }

    void Partition(vector<int>& nums, int L, int R)
    {
        if (L >= R)
            return;
        int a = L;
        int b = R;
        int i = L;

        //.....Partition¹ý³Ì.......//
        int standard = nums[randomInRange(L, R)];

        while (i <= b)
        {
            if (nums[i] < standard)
            {
                Swap(nums, i, a);
                i++;
                a++;
            }
            else if (nums[i] == standard)
            {
                i++;
            }
            else
            {
                Swap(nums, i, b);
                b--;
            }
        }

        Partition(nums, L, a - 1);
        Partition(nums, b + 1, R);

    }

    void QuickSort(vector<int>& nums)
    {
        Partition(nums, 0, nums.size() - 1);

    }



    void Partition(vector<int>& nums, int L, int R, int& Left, int& Right)
    {
        int a = L;
        int b = R;
        int i = L;

        int pivot = nums[randomInRange(a, b)];

        while (i <= b)
        {
            if (nums[i] < pivot)
            {
                Swap(nums, i, a);
                i++;
                a++;
            }

            else if (nums[i] == pivot)
            {
                i++;
            }

            else
            {
                Swap(nums, i, b);
                b--;
            }
        }

        Left = a;
        Right = b;

    }

    int findKthLargest(vector<int>& nums, int k) {

        k = nums.size() - k;
        int L = 0;
        int R = nums.size() - 1;

        int Left = 0;
        int Right = nums.size() - 1;
        int ans = 0;
        while (L <= R)
        {
            Partition(nums, L, R, Left, Right);
            if (Left <= k && k <= Right)
            {
                ans = nums[Left];
                break;
            }

            else if (k < Left)
            {
                R = Left - 1;
            }

            else
            {
                L = Right + 1;
            }
        }

        return ans;
    }
}


constexpr int MAXN = 100001;
std::array<int, MAXN> nums;
std::array<int, MAXN> assist;
std::array<int, 10> cnts;

int bits(int number)
{
    int ans = 0;
    while (number > 0)
    {
        number = number / 10;
        ans++;
    }
    return ans;
}

void Radixsort(int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        max = std::max(max, nums[i]);
    }

    for (int i = 1, offset = 1; i <= bits(max); i++ , offset *= 10)
    {

        std::fill(cnts.begin(), cnts.end(), 0);
        for (int i = 0; i < n; i++)
        {

            cnts[(nums[i]/offset)%10]++;
        }

        for (int i = 1; i <= 9; i++)
        {
            cnts[i] += cnts[i - 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            assist[--cnts[(nums[i] / offset) % 10] ] = nums[i];
        }

        for (int i = 0; i < n; i++)
        {
            nums[i] = assist[i];
        }
    }



    

}














