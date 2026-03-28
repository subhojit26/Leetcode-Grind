/*
 * Problem  : 859. Design Circular Deque
 * Difficulty: Medium
 * Topics   : Array, Linked List, Design, Queue
 * URL      : https://leetcode.com/problems/design-circular-deque/
 */

class MyCircularDeque {
public:
    vector<int> deque;
    int front;
    int end;
    int size;
    int capacity;
    MyCircularDeque(int k) {
        deque=vector<int> (k);
        size=0;
        capacity=k;
        front=0;
        end=k-1;
    }
    
    bool insertFront(int value) {
        if(size==capacity){
            return false;
        }
        front=(front-1+capacity)%capacity;
        deque[front]=value;
        size++;
        return true;
    }
    
    bool insertLast(int value) {
        if(size==capacity){
            return false;
        }
        end=(end+1)%capacity;
        deque[end]=value;
        size++;
        return true;
    }
    
    bool deleteFront() {
        if(size==0){
            return false;
        }
        front=(front+1)%capacity;
        size--;
        return true;
    }
    
    bool deleteLast() {
        if(size==0){
            return false;
        }
        end=(end-1+capacity)%capacity;
        size--;
        return true;
    }
    
    int getFront() {
        if(size==0){
            return -1;
        }
        return deque[front];
    }
    
    int getRear() {
        if(size==0){
            return -1;
        }
        return deque[end];
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    bool isFull() {
        return size==capacity;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */