/*
 * Problem  : 347. Top K Frequent Elements
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Divide and Conquer, Sorting, Heap (Priority Queue), Bucket Sort, Counting, Quickselect
 * URL      : https://leetcode.com/problems/top-k-frequent-elements/
 */

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int ct=0;
        for(auto it:mp){
            if(ct<k){
                pq.push({it.second,it.first});
            }else{
                auto tp=pq.top();
                if(tp.first<it.second){
                    pq.pop();
                    pq.push({it.second,it.first});
                }
            }
            ct++;
        }
        vector<int>ans;
        while(!pq.empty()){
            auto pr = pq.top();
            pq.pop();
            ans.push_back(pr.second);
        }
        return ans;
    }
};