#include "iostream"
#include "vector"
using namespace std;

class MyCircularDeque {
private:
    vector<int> m_arr;
    int m_front;
    int m_rear;
    int m_capacity;

public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        m_capacity = k + 1;
        m_arr.assign(m_capacity, 0);
        m_front = 0;
        m_rear = 0;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if (isFull()) {
            return false;
        }
        m_front = (m_front - 1 + m_capacity) % m_capacity;
        m_arr[m_front] = value;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if (isFull()) {
            return false;
        }
        m_arr[m_rear] = value;
        m_rear = (m_rear + 1) % m_capacity;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        m_front = (m_front + 1) % m_capacity;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        m_rear = (m_rear - 1 + m_capacity) % m_capacity;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return m_arr[m_front];
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        if (isEmpty()) {
            return -1;
        }
        return m_arr[(m_rear - 1 + m_capacity) % m_capacity];
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return m_front == m_rear;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return (m_rear + 1) % m_capacity == m_front;
    }
};

int main() {
    int k = 3;

    MyCircularDeque* obj = new MyCircularDeque(k);
    bool param_1 = obj->insertFront(1);
    bool param_4 = obj->deleteLast();
    int param_5 = obj->getFront();
    int param_6 = obj->getRear();
    bool param_2 = obj->insertLast(2);
    bool param_3 = obj->deleteFront();
    bool param_7 = obj->isEmpty();
    bool param_8 = obj->isFull();
 
    cout << "frontInsterState: " << param_1 << endl;
    cout << "lastInsterState: " << param_2 << endl;
    cout << "frontValue: " << param_5 << endl;
    cout << "lastValue: " << param_6 << endl;
    cout << "frontDeleteState: " << param_3 << endl;
    cout << "lastDeleteState: " << param_4 << endl;  
    cout << "isEmptyState: " << param_7 << endl;
    cout << "isFullState: " << param_8 << endl;
    getchar();
    return 0;
}
