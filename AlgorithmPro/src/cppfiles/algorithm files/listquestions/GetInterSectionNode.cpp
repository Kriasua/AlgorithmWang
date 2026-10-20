//https://leetcode.cn/problems/intersection-of-two-linked-lists/submissions/755160065/


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

	class Solution1 {
	public:
		ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
            ListNode* l1 = headA;
            ListNode* l2 = headB;
            int countA = 0;
            int countB = 0;

            while (l1 != nullptr)
            {
                l1 = l1->next;
                countA++;
            }

			while (l2 != nullptr)
			{
				l2 = l2->next;
				countB++;
			}

            l1 = headA;
            l2 = headB;

            if (countA > countB)
            {
                for (int i = 0; i < countA - countB; i++)
                {
                    l1 = l1->next;
                }
            }
            else
            {
				for (int i = 0; i < countB - countA; i++)
				{
					l2 = l2->next;
				}
            }

            while (l1 != l2)
            {
                l1 = l1->next;
                l2 = l2->next;
            }

            return l1;

		}
	};

}