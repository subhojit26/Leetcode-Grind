/*
 * Problem  : 2692. Take Gifts From the Richest Pile
 * Difficulty: Easy
 * Topics   : Array, Heap (Priority Queue), Simulation
 * URL      : https://leetcode.com/problems/take-gifts-from-the-richest-pile/
 */

class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long tot=0;
        for(int i=0;i<k;i++){
            int mx=INT_MIN;
            int ind=-1;
            for(int j=0;j<gifts.size();j++){
                if(gifts[j]>=mx){
                    mx=gifts[j];
                    ind=j;
                }
            }
            gifts[ind]=sqrtl(mx);
        }
        for(int i=0;i<gifts.size();i++){
            tot+=gifts[i];
        }
        return tot;
    }
};