//两两交换链表中的节点
//https://leetcode.cn/problems/swap-nodes-in-pairs/?envType=study-plan-v2&envId=top-100-liked
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
        ListNode* swapPairs(ListNode* head) {
			if (head == nullptr || head->next == nullptr)
			{
				return head;
			}

			ListNode* cur = head;
			ListNode* next = nullptr;
			ListNode* nextnext = nullptr;
			head = head->next;

			while (cur != nullptr && cur->next != nullptr)
			{
				next = cur->next;
				nextnext = next->next;
				next->next = cur;
				if (nextnext == nullptr || nextnext->next == nullptr)
				{
					cur->next = nextnext;
				}
				else
				{
					cur->next = nextnext->next;
				}
				cur = nextnext;
			}

			return head;
        }
    };
}