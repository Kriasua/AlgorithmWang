//#include<unordered_map>
//#include <memory>
#include "pch.h"
#include <unordered_map>
namespace {
    //第一次写
    class LRUCache1 {

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

        LRUCache1(int capacity) : size(capacity) {
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

    //第二次写
    struct Node
    {
        int key;
        int value;
        Node* last = nullptr;
        Node* next = nullptr;

        Node(int k, int v) : key(k), value(v)
        {

        }
    };

    class Doublelist
    {
    public:
        Node* head = nullptr;
        Node* tail = nullptr;

        Doublelist() 
        {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);
            head->next = tail;
            tail->last = head;
            
        }
        ~Doublelist(){}

        void moveToTail(Node* node)
        {
            if (node->next == tail)
            {
                return;
            }

            Node* oriLast = node->last;
            Node* oriNext = node->next;
            node->last = nullptr;
            node->next = nullptr;
            oriLast->next = oriNext;
            oriNext->last = oriLast;

            add(node);
        }

        void removeHead()
        {
            Node* node = head->next;
            Node* next = node->next;
			node->last = nullptr;
			node->next = nullptr;
            head->next = next;
            next->last = head;
            delete(node);
        }

        void add(Node* node)
        {
            Node* Taillast = tail->last;
            Taillast->next = node;
            node->next = tail;
            tail->last = node;
            node->last = Taillast;
        }

    };


	class LRUCache2 {
	public:
		LRUCache2(int capacity) : m_capacity(capacity)
        {

		}

		int get(int key) {
            if (m_map.contains(key))
            {
                int ans = m_map[key]->value;
                m_list.moveToTail(m_map[key]);
                return ans;
            }
            else
            {
                return -1;
            }
		}

		void put(int key, int value) {
            if (m_map.contains(key))
            {
                m_map[key]->value = value;
                m_list.moveToTail(m_map[key]);
            }
            else
            {
                Node* node = new Node(key, value);
				m_list.add(node);
				m_map[key] = node;
                if (m_size < m_capacity)
                {
                    m_size++;
                }
                else
                {
                    m_map.erase(m_list.head->next->key);
                    m_list.removeHead();  
                }
            }
		}

    private:
        const int m_capacity;
        int m_size = 0;
        Doublelist m_list;
        std::unordered_map<int, Node*> m_map;
	};
}

