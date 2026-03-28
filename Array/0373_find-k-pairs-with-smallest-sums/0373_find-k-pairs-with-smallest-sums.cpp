/*
 * Problem  : 373. Find K Pairs with Smallest Sums
 * Difficulty: Medium
 * Topics   : Array, Heap (Priority Queue)
 * URL      : https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
 */

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq;
        vector<vector<int>> ans;
        int n1=nums1.size();
        int n2=nums2.size();
        for(int i=0;i<n1;i++){
            pq.push({nums1[i]+nums2[0],0});
        }
        while(k-- && !pq.empty()){
            int sum=pq.top().first;
            int ind=pq.top().second;
            pq.pop();

            ans.push_back({sum-nums2[ind],nums2[ind]});

            if(ind+1<n2){
                pq.push({sum-nums2[ind]+nums2[ind+1],ind+1});
            }
        }
        return ans;
    }
};