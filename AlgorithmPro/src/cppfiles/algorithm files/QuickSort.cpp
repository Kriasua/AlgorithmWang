#include<vector>
#include"Random.h"
#include "pch.h"
namespace {
    using namespace std;
    class Solution {
    public:

        void swap(int& a, int& b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        std::pair<int,int> partition(vector<int>& nums, int a, int b, int pivot)
        {
            int i = a;
            while (i <= b)
            {
                if (nums[i] < pivot)
                {
                    swap(nums[i++], nums[a++]);
                    
                }

                else if (nums[i] == pivot)
                {
                    i++;
                }

                else
                {
                    swap(nums[i], nums[b--]);
                }

            }

            return { a-1,b+1 };
        }
        
        void QuickSort(vector<int>& nums, int a, int b)
        {
            if (a >= b)
            {
                return;
            }
            int index = randomInRange(a, b);
            std::pair<int, int> pos = partition(nums, a, b, nums[index]);
            QuickSort(nums, a, pos.first);
            QuickSort(nums, pos.second, b);

        }

        vector<int> sortArray(vector<int>& nums) {
            QuickSort(nums, 0, nums.size() - 1);
            return nums;
        }



        int* GetArray()
        {
            int arr[3] = {2,5,3};
            return arr;
        }
    };

    class QuickSort
    {
    public:
        std::vector<int>& nums;

        void swap(int a, int b)
        {
            int tmp = nums[a];
            nums[a] = nums[b];
            nums[b] = tmp;
        }

        QuickSort(std::vector<int>& arr) : nums(arr)
        {
            sort(0, nums.size() - 1);
        }

        std::pair<int,int> partition(int pivot, int left, int right)
        {
            int small = left;
            int large = right;
            int i = left;
            while (i <= large)
            {
                if (nums[i] < pivot)
                {
                    swap(i, small);
                    i++;
                    small++;
                }
                else if (nums[i] == pivot)
                {
                    i++;
                }
                else
                {
                    swap(i, large);
                    large--;
                }
            }

            return { small - 1,large + 1 };
        }

        void sort(int left, int right)
        {
            if (left >= right)
            {
                return;
            }

            int pivot = randomInRange(left, right);
            std::pair<int,int> range = partition(nums[pivot], left, right);
            sort(left, range.first);
            sort(range.second, right);
        }
    };

    class MergeSort
    {
    public:
        std::vector<int> help;
        std::vector<int>& nums;

        MergeSort(std::vector<int>& arr) : nums(arr)
        {
            help.resize(nums.size());
            sort(0, nums.size() - 1);
        }

        void merge(int left, int right, int middle)
        {
            int l = left;
            int r = middle + 1;
            int i = l;
            while (l <= middle && r <= right)
            {
                if (nums[l] <= nums[r])
                {
                    help[i] = nums[l];
                    i++;
                    l++;
                }
                else
                {
                    help[i] = nums[r];
                    r++;
                    i++;
                }
            }

            if (l > middle)
            {
                for (; r <= right; r++,i++)
                {
                    help[i] = nums[r];
                }
            }
            else
            {
                for (; l <= middle; l++,i++)
                {
                    help[i] = nums[l];
                }
            }

            for (int i = left; i <= right; i++)
            {
                nums[i] = help[i];
            }
        }

        void sort(int left, int right)
        {
            if (left >= right)
            {
                return;
            }

            int middle = left + (right - left) / 2;
            sort(left, middle);
            sort(middle + 1, right);
            merge(left, right, middle);
        }
    };
}






