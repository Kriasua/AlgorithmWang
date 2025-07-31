namespace
{
    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution {
    public:
        ListNode* detectCycle(ListNode* head) {
            if (head == nullptr || head->next == nullptr)
            {
                return nullptr;
            }

            ListNode* fast = head;
            ListNode* slow = head;

            do
            {
                if (fast == nullptr || fast->next == nullptr)
                {
                    return nullptr;
                }

                slow = slow->next;
                fast = fast->next->next;

            } while (slow != fast);

            fast = head;

            while (fast != slow)
            {
                slow = slow->next;
                fast = fast->next;
            }
            return fast;

        }
    };
}