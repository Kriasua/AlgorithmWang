//https://leetcode.cn/problems/UHnkqh/

namespace
{

	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};


	class Solution {
	public:
		ListNode* reverseList(ListNode* head) {
			ListNode* pre = nullptr;
			ListNode* cur = head;

			if (cur == nullptr || cur->next == nullptr)
			{
				return cur;
			}

			ListNode* next = cur->next;

			while (next != nullptr)
			{
				cur->next = pre;
				pre = cur;
				cur = next;
				next = next->next;
			}

			cur->next = pre;
			return cur;
		}
	};
}