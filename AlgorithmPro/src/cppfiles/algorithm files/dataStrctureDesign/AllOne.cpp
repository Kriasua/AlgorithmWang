/*请你设计一个用于存储字符串计数的数据结构，并能够返回计数最小和最大的字符串。

实现 AllOne 类：

AllOne() 初始化数据结构的对象。
inc(String key) 字符串 key 的计数增加 1 。如果数据结构中尚不存在 key ，那么插入计数为 1 的 key 。
dec(String key) 字符串 key 的计数减少 1 。如果 key 的计数在减少后为 0 ，那么需要将这个 key 从数据结构中删除。测试用例保证：在减少计数前，key 存在于数据结构中。
getMaxKey() 返回任意一个计数最大的字符串。如果没有元素存在，返回一个空字符串 "" 。
getMinKey() 返回任意一个计数最小的字符串。如果没有元素存在，返回一个空字符串 "" */


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