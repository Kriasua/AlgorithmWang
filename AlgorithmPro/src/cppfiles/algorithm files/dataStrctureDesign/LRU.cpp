//#include<unordered_map>
//#include <memory>
#include "pch.h"
namespace {
    class LRUCache {

    private:

        class DoubleNode
        {
        public:

            int key, value;
            DoubleNode* next;
            DoubleNode* last;

            DoubleNode(int x, int y) : key(x), value(y), next(nullptr), last(nullptr)
            {
            }

        };

        class Doublelist
        {

        public:
            DoubleNode* head;
            DoubleNode* tail;

            Doublelist() : head(nullptr), tail(nullptr) {}

            void addNode(DoubleNode* node)
            {
                if (node == nullptr)
                    return;

                if (head == nullptr)
                {
                    head = node;
                    tail = node;
                }
                else
                {
                    tail->next = node;
                    node->last = tail;
                    tail = node;
                }
            }

            void moveToTail(DoubleNode* node)
            {
                if (node == nullptr)
                    return;
                if (node == tail)
                    return;

                if (node == head)
                {
                    head = head->next;
                    head->last = nullptr;
                }

                else
                {
                    node->last->next = node->next;
                    node->next->last = node->last;
                }
                node->next = nullptr;
                node->last = tail;
                tail->next = node;
                tail = node;

            }

            DoubleNode* removeHead()
            {
                if (head == nullptr)
                {
                    return nullptr;
                }

                DoubleNode* ans = head;

                if (head == tail)
                {
                    head = nullptr;
                    tail = nullptr;
                }
                else
                {
                    head = head->next;
                    head->last = nullptr;
                    ans->next = nullptr;
                }

                return ans;
            }

        };

        std::unordered_map<int, DoubleNode*> myMap;
        std::unique_ptr<Doublelist> myList;
        int size;


    public:

        LRUCache(int capacity) : size(capacity) {
            myList = std::make_unique<Doublelist>();
        }

        int get(int key) {
            auto it = myMap.find(key);
            if (it != myMap.end())
            {
                myList->moveToTail(it->second);
                return it->second->value;
            }

            return -1;
        }

        void put(int key, int value) {
            auto it = myMap.find(key);
            if (it != myMap.end())
            {
                it->second->value = value;
                myList->moveToTail(it->second);

            }
            else
            {
                if (myMap.size() == size)
                {
                    DoubleNode* head = myList->removeHead();
                    myMap.erase(head->key);
                    delete head;
                }
                DoubleNode* newNode = new DoubleNode(key, value);
                myMap.emplace(key, newNode);
                myList->addNode(newNode);
            }
        }


    };
}