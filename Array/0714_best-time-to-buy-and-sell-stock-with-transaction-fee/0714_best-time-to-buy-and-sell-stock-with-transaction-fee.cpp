/*
 * Problem  : 714. Best Time to Buy and Sell Stock with Transaction Fee
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Greedy
 * URL      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

class Solution {
public:
    int solver(int ind, vector<int> &prices, int fee, bool buy, vector<vector<int>> &dp){
        if(ind>=prices.size()){
            return 0;
        }
        if(dp[ind][buy]!=-1){
            return dp[ind][buy];
        }
        int profit=0;

        if(buy){
            profit= max(-prices[ind]+solver(ind+1,prices,fee,false,dp),solver(ind+1,prices,fee,true,dp));
            
        }
        if(!buy){
            profit= max(solver(ind+1,prices,fee,false,dp),prices[ind]+solver(ind+1,prices,fee,true,dp)-fee);
        }
        
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        bool buy=true;
        int n=prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solver(0,prices,fee,buy,dp);
    }
};