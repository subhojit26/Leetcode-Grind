/*
 * Problem  : 322. Coin Change
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Breadth-First Search
 * URL      : https://leetcode.com/problems/coin-change/
 */

class Solution {
public:
    int solver(int ind, int n, vector<int> &coins, int amount, vector<vector<int>> &dp){
        if(amount==0){
            return 0;
        }
        if(ind==n){
            return 1e9;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int take=1e9;
        if(coins[ind]<=amount){
            take=1+solver(ind,n,coins,amount-coins[ind],dp);
        }
        int notTake=solver(ind+1,n,coins,amount,dp);
        return dp[ind][amount]=min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        
        int res=solver(0,n,coins,amount,dp);
        if(res>=1e9){
            return -1;
        }
        return res;
    }
};