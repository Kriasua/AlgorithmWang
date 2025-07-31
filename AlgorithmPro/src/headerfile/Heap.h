#pragma once

class Myheap {

	void Swap(std::vector<int>& arr, int a, int b);

	void heapInsert(std::vector<int>& arr, int i);
	
	void heapify(std::vector<int>& arr, int i, int size);
	
	std::vector<int> MakeHeap(std::vector<int>& arr);
	
public:

	std::vector<int> Heap;

	Myheap(std::vector<int> arr);
	
	void HeapSort();
	
};
