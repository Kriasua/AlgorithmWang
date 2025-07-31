namespace {

    //��ת����ʱ���������� A>B>C>D>E
    //Ҫȷ�����м�Ͽ�  A>B>C �� D<E
    //�Ƚ�ʱֻ��Ƚ�AB��ED�����ˣ��м��C����Ƚ�
    //ע�⣡���� A>B>C<D<E   �����Ǵ�ģ����� �������Ҳ���û�жϿ������׳�����

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

            while (fast->next && fast->next->next) {  // ����ѭ������
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