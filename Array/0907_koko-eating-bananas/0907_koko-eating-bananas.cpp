/*
 * Problem  : 907. Koko Eating Bananas
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/koko-eating-bananas/
 */

class Solution {
public:
    bool isPossible(long long int mb, vector<int> piles, long long int h){
        long long int t=0;
        for(int i=0;i<piles.size();i++){
            t+=ceil((double)piles[i]/mb);
            if(t>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long int l=1;
        long long int r=*max_element(piles.begin(),piles.end());
        long long int ans=r;
        while(l<=r){

            long long int mid=r-(r-l)/2;
            if(isPossible(mid,piles,h)){
                ans=mid;
                r=mid-1;
            } else{
                l=mid+1;
            }
        }
        return ans;
    }
};