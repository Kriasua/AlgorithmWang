#include<iostream>
#include<vector>
#include"Heap.h"
#include "pch.h"

	void Myheap::Swap(std::vector<int>& arr, int a, int b)
	{
		int temp = arr[a];
		arr[a] = arr[b];
		arr[b] = temp;
	}

	void Myheap::heapInsert(std::vector<int>& arr, int i)
	{
		while (arr[(i - 1) / 2] < arr[i])
		{
			Swap(arr, i, (i - 1) / 2);
			i = (i - 1) / 2;
		}
	}

	void Myheap::heapify(std::vector<int>& arr, int i, int size)
	{
		int l = 2 * i + 1;

		while (l < size)
		{
			int bigger = l + 1 < size && arr[l + 1] > arr[l] ? l + 1 : l;

			if (arr[i] < arr[bigger])
			{
				Swap(arr, i, bigger);
				i = bigger;
				l = 2 * i + 1;
			}
			else
			{
				break;
			}
		}
	}

	std::vector<int> Myheap::MakeHeap(std::vector<int>& arr)
	{
		for (int i = (arr.size()-2)/2 ; i>=0 ; i--)
		{
			heapify(arr, i, arr.size());
		}

		return arr;
	}


	Myheap::Myheap( std::vector<int> arr)
	{
		Heap=MakeHeap(arr);
	}

	void Myheap::HeapSort()
	{
		int size = Heap.size();
		for (int i =size-1; i >= 0; i--)
		{
			Swap(Heap, 0, i);
			size--;
			heapify(Heap, 0, size);
		}
		
	}

