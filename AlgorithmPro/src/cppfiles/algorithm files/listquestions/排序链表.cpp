#include<vector>
#include<algorithm>


namespace
{
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };
    
    //使用容器，空间复杂度O(n)，不是最优解
    class Solution {
    public:
        ListNode* sortList(ListNode* head) {
            if (head == nullptr)
            {
                return nullptr;
            }

            ListNode* node = head;
            std::vector<ListNode*> arr;
            while (node != nullptr)
            {
                arr.push_back(node);
                node = node->next;
            }

            std::sort(arr.begin(), arr.end(), [](ListNode* A, ListNode* B)
                {
                    return A->val < B->val;
                });

            arr.push_back(nullptr);

            for (int i=0;i<arr.size()-1;i++)
            {
                arr[i]->next = arr[i + 1];
            }

            return arr[0];
        }
    };

    //原地调整，空间复杂度O(1)，最优解。
    //使用归并排序的思想
    class Solution2 {
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

        ListNode* sortList(ListNode* head) {
            if (head == nullptr)
            {
                return nullptr;
            }

            if (head->next == nullptr)
            {
                return head;
            }

            ListNode* fast = head;
            ListNode* slow = head;
            ListNode* slowPre = nullptr;

            while (fast != nullptr && fast->next != nullptr)
            {
                slowPre = slow;
                fast = fast->next->next;
                slow = slow->next;
            }

            slowPre->next = nullptr;
            ListNode* left = sortList(head);
            ListNode* right = sortList(slow);
            ListNode* ans = mergeTwoLists(left, right);
            return ans;
        }
    };
}