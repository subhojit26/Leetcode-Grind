/*
 * Problem  : 146. LRU Cache
 * Difficulty: Medium
 * Topics   : Hash Table, Linked List, Design, Doubly-Linked List
 * URL      : https://leetcode.com/problems/lru-cache/
 */

class LRUCache {
    public:
    struct Node{
        int key;
        int val;
        Node* next;
        Node* prev;

        Node(int k, int v){
            key=k;
            val=v;
            next=nullptr;
            prev=nullptr;
        }
    };
    int cap;
    Node* head=new Node(-1,-1);
    Node* tail=new Node(-1,-1);
    unordered_map<int, Node*> mp;
    LRUCache(int capacity) {
        cap=capacity;
        head->next=tail;
        tail->prev=head;
    }

    void addNodeAtFront(Node* node){
        Node* temp=head->next;
        node->next=temp;
        temp->prev=node;
        head->next=node;
        node->prev=head;
    }

    void deleteNode(Node* node){
        Node* nextNode=node->next;
        Node* prevNode=node->prev;

        prevNode->next=nextNode;
        nextNode->prev=prevNode;
    }
    
    int get(int key) {
        if(mp.find(key)!=mp.end()){
            int res=mp[key]->val;
            Node* node=mp[key];
            mp.erase(key);

            deleteNode(node);
            addNodeAtFront(node);
            mp[key]=head->next;
            return res;
        }else{
            return -1;
        }
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* node=mp[key];
            mp.erase(key);
            deleteNode(node);
        }
        if(mp.size()==cap){
            mp.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNodeAtFront(new Node(key,value));
        mp[key]=head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */