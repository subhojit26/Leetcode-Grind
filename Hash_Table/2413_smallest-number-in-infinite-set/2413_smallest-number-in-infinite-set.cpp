/*
 * Problem  : 2413. Smallest Number in Infinite Set
 * Difficulty: Medium
 * Topics   : Hash Table, Design, Heap (Priority Queue), Ordered Set
 * URL      : https://leetcode.com/problems/smallest-number-in-infinite-set/
 */

class SmallestInfiniteSet {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int counter=1;
    unordered_set<int> st;
    bool isPresent(priority_queue<int> pq, int target){
        while(!pq.empty()){
        if(pq.top() == target) return true;
        pq.pop();
    }
    return false;
    }
    SmallestInfiniteSet() {
        
    }
    
    int popSmallest() {
        if(!pq.empty()){
            int val = pq.top();
            pq.pop();
            st.erase(val);
            return val;
        }
        return counter++;
    }
    
    void addBack(int num) {
        if(num < counter && st.find(num) == st.end()){
            pq.push(num);
            st.insert(num);
        }

    }
};

/**
 * Your SmallestInfiniteSet object will be instantiated and called as such:
 * SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 * int param_1 = obj->popSmallest();
 * obj->addBack(num);
 */