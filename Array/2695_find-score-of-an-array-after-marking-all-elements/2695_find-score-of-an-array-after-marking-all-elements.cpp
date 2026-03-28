/*
 * Problem  : 2695. Find Score of an Array After Marking All Elements
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Sorting, Heap (Priority Queue), Simulation
 * URL      : https://leetcode.com/problems/find-score-of-an-array-after-marking-all-elements/
 */

struct Compare {
    bool operator()(const pair<long long int, long long int>& a, const pair<long long int, long long int>& b) {
        if (a.first == b.first) {
            return a.second > b.second;
        }
        return a.first > b.first; 
    }
};
class Solution {
public:
    long long findScore(vector<int>& nums) {
        priority_queue<pair<long long int,long long int>, vector<pair<long long int, long long int>>, Compare> pq;
        map<long long int,long long int> mp;
        long long int ans=0;
        long long int n=nums.size();
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        while(!pq.empty()){
            long long int mini=pq.top().first;
            long long int ind=pq.top().second;
            if(mp.find(ind)==mp.end()){
                mp[ind]=1;
                mp[max((long long int)0,ind-1)]=1;
                mp[min(n-1,ind+1)]=1;
                ans+=mini;
                pq.pop();
            } else{
                pq.pop();
            }
        }
        return ans;
    }
};