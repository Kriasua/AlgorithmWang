

namespace
{
  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            if (head->next == nullptr)
            {
                return head;
            }

            ListNode* answer = teamEnd(head, k);

           
            if (answer == nullptr)
            {
                return head;
            }

            ListNode* start = head;
            ListNode* end = answer;
            reverseList(start, end);

            ListNode* lastGroupTail = start;
            
            while (lastGroupTail->next != nullptr)
            {
                start = lastGroupTail->next;
                end = teamEnd(start, k);

                if (end == nullptr)
                {
                    return answer;
                }

                
                reverseList(start, end);
                lastGroupTail->next = end;
                lastGroupTail = start;
                
            }

            return answer;
        }

        ListNode* teamEnd(ListNode* s, int k)
        {
            k--;
            while ((k != 0) && (s != nullptr))
            {
                s = s->next;
                k--;
            }

            return s;
        }

        void reverseList(ListNode* start, ListNode* end)
        {
            if (start == end)
            {
                return;
            }

            end = end->next;

            ListNode* cur = start;
            ListNode* next = nullptr;
            ListNode* pre = nullptr;

            while (cur != end)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }

            start->next = end;

        }
    };


}