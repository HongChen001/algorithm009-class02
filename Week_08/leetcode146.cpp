#include "iostream"
#include "unordered_map"

using namespace std;

struct MyNode {
    int m_key;
    int m_value;
    MyNode* prev;
    MyNode* next;
    MyNode(): m_key(0), m_value(0), prev(nullptr), next(nullptr) {};
    MyNode(int key, int value): m_key(key), m_value(value), prev(nullptr), next(nullptr) {};
};

class LRUCache {
private:
    unordered_map<int, MyNode*> cache;
    MyNode* head;
    MyNode* tail;
    int m_size;
    int m_capacity;

public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        m_size = 0;
        head = new MyNode();
        tail = new MyNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!cache.count(key)) {
            return -1;
        }
        MyNode* node = cache[key];
        moveToHead(node);
        return node->m_value;
    }   
    
    void put(int key, int value) {
        if (!cache.count(key)) {
            MyNode* node = new MyNode(key, value);
            cache[key] = node;
            addToHead(node);
            ++m_size;
            if (m_size > m_capacity) {
                MyNode* removed = removeTail();
                cache.erase(removed->m_key);
                delete removed;
                --m_size;
            }
        } else {
            MyNode* node = cache[key];
            node->m_value = value;
            moveToHead(node);
        }
    }    

    void addToHead(MyNode* node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode (MyNode* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void moveToHead(MyNode* node) {
        removeNode(node);
        addToHead(node);
    }

    MyNode* removeTail() {
        MyNode* node = tail->prev;
        removeNode(node);
        return node;
    }
};