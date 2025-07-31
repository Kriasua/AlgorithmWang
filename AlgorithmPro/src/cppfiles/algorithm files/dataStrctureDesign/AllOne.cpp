/*�������һ�����ڴ洢�ַ������������ݽṹ�����ܹ����ؼ�����С�������ַ�����

ʵ�� AllOne �ࣺ

AllOne() ��ʼ�����ݽṹ�Ķ���
inc(String key) �ַ��� key �ļ������� 1 ��������ݽṹ���в����� key ����ô�������Ϊ 1 �� key ��
dec(String key) �ַ��� key �ļ������� 1 ����� key �ļ����ڼ��ٺ�Ϊ 0 ����ô��Ҫ����� key �����ݽṹ��ɾ��������������֤���ڼ��ټ���ǰ��key ���������ݽṹ�С�
getMaxKey() ��������һ�����������ַ��������û��Ԫ�ش��ڣ�����һ�����ַ��� "" ��
getMinKey() ��������һ��������С���ַ��������û��Ԫ�ش��ڣ�����һ�����ַ��� "" */


#include "pch.h"
namespace {
    class AllOne {
    private:
        class Bucket
        {
        public:

            Bucket(std::string s, int n) : cnt(n)
            {
                set.emplace(s);
            }

            std::unordered_set<std::string> set;
            int cnt;
            Bucket* next;
            Bucket* last;    
        };


    public:

        void add(Bucket* cur, Bucket* pos)
        {
            Bucket* front = cur->next;
            cur->next = pos;
            pos->next = front;
            front->last = pos;
            pos->last = cur;

        }

        void remove(Bucket* node)
        {
            node->last->next = node->next;
            node->next->last = node->last;
            delete node;
        }

        
        std::unordered_map<std::string, Bucket*> map;

        Bucket* head = new Bucket("", 0);
        Bucket* tail = new Bucket("", 0xffffffff);
        AllOne() {

            head->next = tail;
            tail->last = head;
        }

        void inc(std::string key) {
            auto it = map.find(key);
            if (it == map.end())
            {
                if (head->next->cnt == 1)
                {
                    map.emplace(key, head->next);
                    head->next->set.emplace(key);
                }
                else
                {
                    Bucket* newNode = new Bucket(key, 1);
                    add(head, newNode);
                    map.emplace(key, newNode);
                }
            }
            else
            {
                Bucket* cur = it->second;
                if (cur->next->cnt == (cur->cnt + 1))
                {
                    map[key] = cur->next;
                    cur->next->set.emplace(key);
                }
                else
                {
                    Bucket* newNode2 = new Bucket(key, cur->cnt + 1);
                    add(cur, newNode2);
                    map[key] = newNode2;
                }

                cur->set.erase(key);
                if (cur->set.empty())
                {
                    remove(cur);
                }
            }
        }

        void dec(std::string key) {

            Bucket* cur = map[key];
            
            if (cur->cnt == 1)
            {
                map.erase(key);
            }

            else if (cur->last->cnt != cur->cnt - 1)
            {
                Bucket* newNode = new Bucket(key, cur->cnt - 1);
                add(cur->last, newNode);
                map[key] = newNode;
            }

            else
            { 
                cur->last->set.emplace(key);
                map[key] = cur->last;
            }

            cur->set.erase(key);

            if (cur->set.empty())
            {
                remove(cur);
            }
        }

        std::string getMaxKey() {
            return *(tail->last->set.begin());
        }

        std::string getMinKey() {
            return *(head->next->set.begin());
        }
    };
}