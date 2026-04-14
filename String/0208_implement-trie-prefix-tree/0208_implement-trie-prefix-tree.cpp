/*
 * Problem  : 208. Implement Trie (Prefix Tree)
 * Difficulty: Medium
 * Topics   : Hash Table, String, Design, Trie
 * URL      : https://leetcode.com/problems/implement-trie-prefix-tree/
 */

struct Node{
    Node* links[26]={nullptr};
    bool flag=false;

    bool isContainsKey(char ch){
        return links[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return links[ch-'a'];
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }

    bool isEnd(){
        return flag;
    }

    void setEnd(){
        flag=true;
    }
};

class Trie {
public:
Node* root;
    Trie() {
        root=new Node();
    }
    
    void insert(string word) {
        Node* node=root;
    for(auto it:word){
        if(!node->isContainsKey(it)){
            node->put(it,new Node());
        }
        node=node->get(it);
    }
    node->setEnd();
    }
    
    bool search(string word) {
         Node* node=root;
    for(auto it:word){
        if(!node->isContainsKey(it)){
                return false;
            }
            node=node->get(it);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node=root;
    for(auto it:prefix){
        if(!node->isContainsKey(it)){
            return false;
        }
        node=node->get(it);
    }
    return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */