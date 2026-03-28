/*
 * Problem  : 1335. Maximum Candies Allocated to K Children
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
 */

class Solution {
public:
    bool isPossible(long long int mc, vector<int> &candies, long long k){
        long long int pool=0;
        for(int i=0;i<candies.size();i++){
            pool+=candies[i]/mc;
        }
        return pool>=k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long int l=1;
        long long int r=0;
        int n=candies.size();
        for(int i=0;i<n;i++){
            r+=candies[i];
        }
        if(r<k){
            return 0;
        }
        long long int ans=r;
        while(l<=r){
            long long int mid=r-(r-l)/2;
            if(isPossible(mid,candies,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};