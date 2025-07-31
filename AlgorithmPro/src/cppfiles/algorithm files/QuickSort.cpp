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
}






