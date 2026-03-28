/*
 * Problem  : 838. Design Linked List
 * Difficulty: Medium
 * Topics   : Linked List, Design
 * URL      : https://leetcode.com/problems/design-linked-list/
 */

class MyLinkedList {
    struct Node{
        int val;
        Node* next;

        Node(int val):val(val), next(nullptr){}
        Node(int val, Node* next) : val(val),next(next){}
    };

    Node* front, *rear;
    int size;

    Node* getNodeAt(int index){
        Node* tmp=front;
        for(int i=0;i<index;i++){
            tmp=tmp->next;
        }
        return tmp;
    }
    
public:

    MyLinkedList():size(0) {    
        front=nullptr;
        rear=nullptr;
    }
    
    int get(int index) {
        if(index>=0 && index<size){
            Node* tmp=getNodeAt(index);
            return tmp->val;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        Node* newNode=new Node(val,front);
        front=newNode;
        if(!rear) rear=newNode;
        size++;
    }
    
    void addAtTail(int val) {
        Node* newNode=new Node(val,nullptr);
        if(!rear){
            front=newNode;
            rear=newNode;
        }
        rear->next=newNode;
        rear=newNode;
        size++;
    }
    
    void addAtIndex(int index, int val) {
        if(index==0){
            addAtHead(val);
        }
        else if(index==size){
            addAtTail(val);
        }
        else if(index>=0 && index<size){
            Node* tmp=getNodeAt(index-1);
            Node* newNode=new Node(val,tmp->next);
            tmp->next=newNode;

            if(tmp==rear) rear=tmp->next;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if(index==0){
            if(front){
                Node* tmp=front;
                front=front->next;
                if(!front){
                    rear=front;
                }
                if(rear==tmp){
                    rear=nullptr;
                }
                delete tmp;
                size--;
            }
        }
        else if(index>=0 && index<size){
            Node* prev=getNodeAt(index-1);

            Node* delNode=prev->next;
            prev->next=delNode->next;
            if(delNode==rear) rear=prev;
            if(front==delNode) front=nullptr;
            delete delNode;
            size--;
        }
    }


};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */