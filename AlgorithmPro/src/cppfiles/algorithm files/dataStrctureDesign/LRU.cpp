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
 //   struct Node
 //   {
 //       int key;
 //       int value;
 //       Node* last = nullptr;
 //       Node* next = nullptr;

 //       Node(int k, int v) : key(k), value(v)
 //       {

 //       }
 //   };

 //   class Doublelist
 //   {
 //   public:
 //       Node* head = nullptr;
 //       Node* tail = nullptr;

 //       Doublelist() 
 //       {
 //           head = new Node(-1, -1);
 //           tail = new Node(-1, -1);
 //           head->next = tail;
 //           tail->last = head;
 //           
 //       }
 //       ~Doublelist(){}

 //       void moveToTail(Node* node)
 //       {
 //           if (node->next == tail)
 //           {
 //               return;
 //           }

 //           Node* oriLast = node->last;
 //           Node* oriNext = node->next;
 //           node->last = nullptr;
 //           node->next = nullptr;
 //           oriLast->next = oriNext;
 //           oriNext->last = oriLast;

 //           add(node);
 //       }

 //       void removeHead()
 //       {
 //           Node* node = head->next;
 //           Node* next = node->next;
	//		node->last = nullptr;
	//		node->next = nullptr;
 //           head->next = next;
 //           next->last = head;
 //           delete(node);
 //       }

 //       void add(Node* node)
 //       {
 //           Node* Taillast = tail->last;
 //           Taillast->next = node;
 //           node->next = tail;
 //           tail->last = node;
 //           node->last = Taillast;
 //       }

 //   };


	//class LRUCache2 {
	//public:
	//	LRUCache2(int capacity) : m_capacity(capacity)
 //       {

	//	}

	//	int get(int key) {
 //           if (m_map.contains(key))
 //           {
 //               int ans = m_map[key]->value;
 //               m_list.moveToTail(m_map[key]);
 //               return ans;
 //           }
 //           else
 //           {
 //               return -1;
 //           }
	//	}

	//	void put(int key, int value) {
 //           if (m_map.contains(key))
 //           {
 //               m_map[key]->value = value;
 //               m_list.moveToTail(m_map[key]);
 //           }
 //           else
 //           {
 //               Node* node = new Node(key, value);
	//			m_list.add(node);
	//			m_map[key] = node;
 //               if (m_size < m_capacity)
 //               {
 //                   m_size++;
 //               }
 //               else
 //               {
 //                   m_map.erase(m_list.head->next->key);
 //                   m_list.removeHead();  
 //               }
 //           }
	//	}

 //   private:
 //       const int m_capacity;
 //       int m_size = 0;
 //       Doublelist m_list;
 //       std::unordered_map<int, Node*> m_map;
	//};





    //第三次写
	class LRUCache3 {
    private:
        struct node
        {
            int key;
            int value;
            node* next;
            node* last;

            node(int k, int v) : key(k) , value(v), next(nullptr), last(nullptr)
            {

            }
        };

        class doubleList
        {
        public:     
            node* head;
            node* tail;

            doubleList()
            {
                head = new node(0, 0);
                tail = new node(0, 0);
                head->next = tail;
                tail->last = head;
            }

            void insert(node* newNode)
            {              
                node* next = head->next;
                head->next = newNode;
                next->last = newNode;
                newNode->next = next;
                newNode->last = head;
            }

            void moveToHead(node* n)
            {
                node* next = n->next;
                node* last = n->last;
                n->next = nullptr;
                n->last = nullptr;
                next->last = last;
                last->next = next;
                insert(n);
            }

            void erase(node* n)
            {
				node* next = n->next;
				node* last = n->last;
				n->next = nullptr;
				n->last = nullptr;
				next->last = last;
				last->next = next;
                delete(n);
            }
        };

	public:
        int size = 0;
        int cap;
        doubleList list;
        std::unordered_map<int, node*> map;

		LRUCache3(int capacity) :cap(capacity)
        {
            list = doubleList();
		}

		int get(int key) {
            if (!map.contains(key))
            {
                return -1;
            }
            else
            {
                node* target = map[key];
                list.moveToHead(target);
                return target->value;
            }
		}

		void put(int key, int value) {
			if (map.contains(key))
			{
				node* target = map[key];
				list.moveToHead(target);
                target->value = value;
			}
            else
            {
                if (size < cap)
                {
                    node* n = new node(key, value);
                    map.emplace(key, n);
                    list.insert(n);
                    size++;
                }
                else
                {
                    node* last = list.tail->last;
                    map.erase(last->key);
                    list.erase(last);
					node* n = new node(key, value);
					map.emplace(key, n);
					list.insert(n);
                }
            }
		}
	};
}

