/*����һ������Ϊ n ������ÿ���ڵ����һ���������ӵ����ָ�� random ��
��ָ�����ָ�������е��κνڵ��սڵ㡣
������������ ����� 
���Ӧ�������� n �� ȫ�� �ڵ���ɣ�
����ÿ���½ڵ��ֵ����Ϊ���Ӧ��ԭ�ڵ��ֵ��
�½ڵ�� next ָ��� random ָ��Ҳ��Ӧָ���������е��½ڵ㣬
��ʹԭ����͸��������е���Щָ���ܹ���ʾ��ͬ������״̬��
���������е�ָ�붼��Ӧָ��ԭ�����еĽڵ� ��*/

namespace {

    class Node {
    public:
        int val;
        Node* next;
        Node* random;

        Node(int _val) {
            val = _val;
            next = nullptr;
            random = nullptr;
        }
    };


    class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (head == nullptr)
            {
                return nullptr;
            }

            Node* start = head;         
            while (start != nullptr)
            {
                Node* newNode = new Node(start->val);
                newNode->next = start->next;
                start->next = newNode;
                start = newNode->next;
            }

            start = head;
            while (start != nullptr)
            {
                if (start->random != nullptr)
                {
                    start->next->random = start->random->next;
                }
                else
                {
                    start->next->random = nullptr;
                }
                
                start = start->next->next;
            }

            start = head;
            Node* copied = start->next;
            Node* ans = copied;
            while (copied->next != nullptr)
            {
                start->next = copied->next;
                start = start->next;
                copied->next = start->next;
                copied = copied->next;
            }
            start->next = nullptr;

            return ans;

        }
    };
}