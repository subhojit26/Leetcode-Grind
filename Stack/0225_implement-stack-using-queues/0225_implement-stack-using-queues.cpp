/*
 * Problem  : 225. Implement Stack using Queues
 * Difficulty: Easy
 * Topics   : Stack, Design, Queue
 * URL      : https://leetcode.com/problems/implement-stack-using-queues/
 */

class MyStack {
    queue<int> q1;

public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        int n=q1.size();
        for(int i=0;i<n-1;i++){
            q1.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int ele=q1.front();
        q1.pop();
        return ele;
    }
    
    int top() {
        int ele=q1.front();
        return ele;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */