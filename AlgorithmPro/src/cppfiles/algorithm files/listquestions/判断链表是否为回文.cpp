namespace {

    //翻转链表时假如奇数个 A>B>C>D>E
    //要确保从中间断开  A>B>C 和 D<E
    //比较时只需比较AB和ED就行了，中间的C无需比较
    //注意！！！ A>B>C<D<E   这样是错的！！！ 链表左右部分没有断开，容易出问题

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
    class Solution {
    public:
        bool isPalindrome(ListNode* head) {

            if (head->next == nullptr)
            {
                return true;
            }
            bool ans = true;
            ListNode* fast = head;
            ListNode* slow = head;

            while (fast->next && fast->next->next) {  // 修正循环条件
                fast = fast->next->next;
                slow = slow->next;
            }

        
            ListNode* middle = slow;
            ListNode* pre = slow;
            ListNode* next = nullptr;
            ListNode* cur = pre->next;
            pre->next = nullptr;
            while (cur != nullptr)
            {
                next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }


            ListNode* right = pre;
            ListNode* left = head;
            while (right != nullptr)
            {
                if (left->val != right->val)
                {
                    ans = false;
                    break;
                }

                left = left->next;
                right = right->next;
            }

            middle = slow;
            pre = nullptr;
            next = nullptr;
            while (slow != nullptr)
            {
                next = slow->next;
                slow->next = pre;
                pre = slow;
                slow = next;
            }

            return ans;


        }
    };
}