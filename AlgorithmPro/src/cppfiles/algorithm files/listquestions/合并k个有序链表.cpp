//https://www.nowcoder.com/practice/65cfde9e5b9b4cf2b6bafa5f3ef33fa6
#include<vector>
#include<queue>
 struct ListNode {
	int val;
	struct ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
	
};

class Solution {
public:
	struct cmp
	{
		bool operator()(ListNode* a, ListNode* b)
		{
			return a->val > b->val;
		}
	};

    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
		std::priority_queue<ListNode*, std::vector<ListNode*>, cmp> heap;
		for (auto node : lists)
		{
			if (node != nullptr)
			{
				heap.push(node);
			}
		}

		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		while (!heap.empty())
		{
			ListNode* top = heap.top();
			heap.pop();
			cur->next = top;
			if (top->next != nullptr)
			{
				heap.push(top->next);
			}
			cur = cur->next;
		}

		return head->next;
    }
};