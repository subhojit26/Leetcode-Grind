/*
 * Problem  : 123. Best Time to Buy and Sell Stock III
 * Difficulty: Hard
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/
 */

class Solution {
public:
    int solver(int ind, int buy, int trans, int n, vector<int> &prices, vector<vector<vector<int>>> &dp){
        if(ind==n || trans==0){
            return 0;
        }

        if(dp[ind][buy][trans]!=-1){
            return dp[ind][buy][trans];
        }

        if(buy){
            return dp[ind][buy][trans]=max(-prices[ind]+solver(ind+1,0,trans,n,prices,dp),solver(ind+1,1,trans,n,prices,dp));
        }
        return dp[ind][buy][trans]=max(prices[ind]+solver(ind+1,1,trans-1,n,prices,dp),solver(ind+1,0,trans,n,prices,dp));

    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int ind=0;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int> (3,-1)));
        return solver(ind,1,2,n,prices,dp);
    }
};