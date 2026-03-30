/*
 * Problem  : 907. Koko Eating Bananas
 * Difficulty: Medium
 * Topics   : Array, Binary Search
 * URL      : https://leetcode.com/problems/koko-eating-bananas/
 */

class Solution {
public:
    bool isPossible(vector<int> &piles, int h, int speed){
        int banana=0;
        int time=0;
        for(int i=0;i<piles.size();i++){
            time+=ceil((double)piles[i]/(double)speed);
            if(time>h){
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(),piles.end());
        int n=piles.size();
        int low=piles[0];
        int high=piles[n-1];
        int ans;
        if(n>h){
            return -1;
        }

        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(piles,h,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};