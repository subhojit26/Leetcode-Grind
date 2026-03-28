/*
 * Problem  : 1488. Sort Integers by The Power Value
 * Difficulty: Medium
 * Topics   : Dynamic Programming, Memoization, Sorting
 * URL      : https://leetcode.com/problems/sort-integers-by-the-power-value/
 */

struct compare{
    bool operator()(const pair<int,int> &a, const pair<int, int> &b){
        if(a.first==b.first){
            return a.second>b.second;
        }
        return a.first>b.first;
    }
};

class Solution {
public:
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int, int>,vector<pair<int, int>>,compare> pq;
        vector<int> v;
        for(int i=lo;i<=hi;i++){
            int x=i;
            int count=0;
            while(x!=1){
                if(x%2==0){
                    x=x/2;
                }else{
                    x=x*3+1;
                }
                count++;
            }
            pq.push({count,i});
        }
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v[k-1];
    }
};