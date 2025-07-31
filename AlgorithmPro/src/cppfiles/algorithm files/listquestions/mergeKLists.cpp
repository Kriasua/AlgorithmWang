#include<vector>
#include<queue>
#include "pch.h"
namespace {
    using std::vector;
    struct ListNode {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}

    };

    struct CompareListNode {
        bool operator()(const ListNode* a, const ListNode* b) const {
            // ����С���ѵıȽϹ�����С�� val �ڶѶ�
            // �� a->val > b->val���� a ���ȼ��ͣ�b ���ϸ�
            return a->val > b->val; // ">" ��С���ѵĹؼ�������
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        std::priority_queue<ListNode*, vector<ListNode*>, CompareListNode> help;

        for (ListNode* head : lists) {
            if (head != nullptr) {
                help.push(head);
            }
        }

        if (help.empty())
            return nullptr;

        ListNode* H;
        ListNode* pre;
        H = help.top();
        help.pop();
        if (H->next != nullptr)
        {
            help.push(H->next);
        }

        pre = H;

        while (!help.empty())
        {
            pre->next = help.top();
            help.pop();
            pre = pre->next;
            if (pre->next != nullptr)
            {
                help.push(pre->next);
            }
        }
        return H;
    }
}