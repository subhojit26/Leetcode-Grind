/*
 * Problem  : 518. Coin Change II
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/coin-change-ii/
 */

class Solution {
public:
    int solver(int ind, int amount, vector<int> &coins, vector<vector<int>> &dp){
        if(amount==0){
            return 1;
        }
        if(ind==coins.size()){
            return 0;
        }
        if(dp[ind][amount]!=-1){
            return dp[ind][amount];
        }
        int take=0;
        if(coins[ind]<=amount){
            take=solver(ind,amount-coins[ind],coins,dp);
        }
        int notTake=solver(ind+1,amount,coins,dp);
        return dp[ind][amount]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int ind=0;

        vector<vector<int>> dp(coins.size()+1, vector<int>(amount+1,-1));
        return solver(ind, amount, coins, dp);
    }
};