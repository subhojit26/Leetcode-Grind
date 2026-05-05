/*
 * Problem  : 322. Coin Change
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Breadth-First Search
 * URL      : https://leetcode.com/problems/coin-change/
 */

class Solution {
public:
    int solver(int ind, int n, vector<int> coins, int amount){
        if(amount==0){
            return 0;
        }
        if(ind==n){
            return 1e9;
        }

        int take=1e9;
        if(coins[ind]<=amount){
            take=1+solver(ind,n,coins,amount-coins[ind]);
            cout<<take<<" ";
        }
        int notTake=solver(ind+1,n,coins,amount);
        //cout<<min(take,notTake)<<"\n";
        return min(take,notTake);

    }
    int coinChange(vector<int>& coins, int amount) {
        int c=0;
        int n=coins.size();
        int res=solver(0,n,coins,amount);
        if(res>=1e9){
            return -1;
        }
        else{
            return res;
        }
    }
};