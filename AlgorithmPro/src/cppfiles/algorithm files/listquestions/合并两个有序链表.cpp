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
        ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
            if (list1 == nullptr)
            {
                return list2;
            }

            if (list2 == nullptr)
            {
                return list1;
            }

            ListNode* head = list1->val <= list2->val ? list1 : list2;

            if (head == list1)
            {
                list1 = list1->next;
            }
            else
            {
                list2 = list2->next;
            }
            ListNode* cur = head;
            while (list1 != nullptr && list2 != nullptr)
            {
                if (list1->val <= list2->val)
                {
                    cur->next = list1;
                    list1 = list1->next;
                    cur = cur->next;
                }
                else
                {
                    cur->next = list2;
                    list2 = list2->next;
                    cur = cur->next;
                }
            }

            if (list1 == nullptr)
            {
                cur->next = list2;
            }
            else
            {
                cur->next = list1;
            }
            return head;
        }
    };
}




