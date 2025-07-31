// �����������ֵ���������о����÷�ģ�棩
// ����һ���������� nums����һ����СΪ k �Ļ������ڴ������������ƶ�����������Ҳ�
// ��ֻ���Կ����ڻ��������ڵ� k �����֡���������ÿ��ֻ�����ƶ�һλ��
// ���� ���������е����ֵ ��
// �������� : https://leetcode.cn/problems/sliding-window-maximum/
#include<vector>
namespace
{
	class Solution {
	public:
		std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
			std::vector<int> ans;
			if (nums.size() == 0)
			{
				return ans;
			}
			std::vector<int> queue;
			int qL = 0;
			int qR = 0;
			queue.resize(nums.size());
			int wL = 0;
			int wR = 0;
			queue[0] = 0;
			for (; wR < k; wR++)
			{
				while (qR > qL && nums[wR] >= nums[queue[qR - 1]])
				{
					qR--;
				}
				queue[qR++] = wR;
			}
			ans.push_back(nums[queue[qL]]);
			for (; wR < nums.size(); wR++, wL++)
			{
				while (qR > qL && nums[wR] >= nums[queue[qR - 1]])
				{
					qR--;
				}
				queue[qR++] = wR;
				if (queue[qL] == wL)
				{
					qL++;
				}
				ans.push_back(nums[queue[qL]]);
			}
			return ans;
		}
	};
}

