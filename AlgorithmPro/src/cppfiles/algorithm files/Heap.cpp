#include<iostream>
#include<vector>
#include<queue>

class heap
{
private:
	int m_size = 0;
	std::vector<int> m_heap;

	

	void swap(std::vector<int>& nums, int a, int b)
	{
		int tmp = nums[a];
		nums[a] = nums[b];
		nums[b] = tmp;
	}

	void heapInsert(int num)
	{
		if (m_heap.size() == m_size)
		{
			m_heap.resize(2 * m_heap.size() + 1);
		}

		m_heap[m_size++] = num;

		int curIdx = m_size - 1;
		int fatherIdx = (curIdx - 1) / 2;
		while (curIdx != 0 && m_heap[curIdx] > m_heap[fatherIdx])
		{
			swap(m_heap, fatherIdx, curIdx);
			curIdx = fatherIdx;
			fatherIdx = (curIdx - 1) / 2;
		}
	}

	void heapify(int i)
	{
		int cur = i;
		int leftChild = 2 * i + 1;
		int rightChild = 2 * i + 2;
		int bigger = leftChild;

		while (m_size > leftChild)
		{
			if (m_size > rightChild && m_heap[rightChild] > m_heap[leftChild])
			{
				bigger = rightChild;
			}
			else
			{
				bigger = leftChild;
			}

			bigger = m_heap[cur] > m_heap[bigger] ? cur : bigger;
			if (cur == bigger)
			{
				break;
			}

			swap(m_heap, cur, bigger);
			cur = bigger;
			leftChild = 2 * cur + 1;
			rightChild = 2 * cur + 2;
		}


	}

public:
	heap()
	{

	}

	heap(std::vector<int>& arr)
	{
		m_size = arr.size();
		m_heap.resize(arr.size());
		for (int num : arr)
		{
			heapInsert(num);
		}

	}

	~heap()
	{
		m_heap.clear();
	}

	int getSize()
	{
		return m_size;
	}

	bool empty()
	{
		return m_size == 0;
	}

	void insert(int num)
	{
		heapInsert(num);
	}

	int top()
	{
		return m_heap[0];
	}

	void pop()
	{
		swap(m_heap, 0, m_size - 1);
		m_size--;
		heapify(0);
	}

};

//将数组和减半的最少操作
class Solution {
public:
	int halveArray(std::vector<int>& nums) {
		std::priority_queue<float,std::vector<float>,std::less<float>> heap(nums.begin(), nums.end());
		double sum = 0;
		for (int num : nums)
		{
			sum += num;
		}

		double half = sum / 2;
		int ans = 0;
		sum = 0;

		while (sum < half)
		{
			float tmp = heap.top();
			heap.pop();
			sum += tmp / 2;
			heap.push(tmp / 2);
			ans++;
		}

		return ans;
	}
};





