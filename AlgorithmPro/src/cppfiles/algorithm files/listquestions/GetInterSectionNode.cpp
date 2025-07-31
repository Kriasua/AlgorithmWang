


namespace {


    //若两条链表相交，返回相交的交点。若没有相交，返回空。

    struct ListNode {
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(nullptr) {}
    };

    class Solution {
    public:
        ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            
            int lengthA = 0;
            int lengthB = 0;
            ListNode* A = headA;
            ListNode* B = headB;

            while (A != nullptr)
            {
                A = A->next;
                lengthA++;
            }

            while (B != nullptr)
            {
                B = B->next;
                lengthB++;
            }

            A = headA;
            B = headB;

            if (lengthA > lengthB)
            {
                for (int i = 0; i < (lengthA - lengthB); i++)
                {
                    A = A->next;
                }

                while ((A != B) && (A!=nullptr))
                {
                    A = A->next;
                    B = B->next;
                }

                return A;
            }

            else if (lengthB > lengthA)
            {
                for (int i = 0; i < (lengthB - lengthA); i++)
                {
                    B = B->next;
                }

                while ((A != B) && (B != nullptr))
                {
                    A = A->next;
                    B = B->next;
                }

                return B;
            }

            else
            {
                while ((A != B) && (B != nullptr))
                {
                    A = A->next;
                    B = B->next;
                }

                return A;
            }



        }
    };

}