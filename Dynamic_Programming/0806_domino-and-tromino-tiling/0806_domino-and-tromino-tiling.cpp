/*
 * Problem  : 806. Domino and Tromino Tiling
 * Difficulty: Medium
 * Topics   : Dynamic Programming
 * URL      : https://leetcode.com/problems/domino-and-tromino-tiling/
 */

class Solution {
public:
    int solver(int i, int n, bool flag,vector<vector<int>> &dp){
        if(i==n){
            return !flag;
        }
        if(i>n){
            return 0;
        }
        if(dp[i][flag]!=-1){
            return dp[i][flag];
        }
        if(flag){
            return dp[i][flag]=(solver(i+1,n,true,dp)+solver(i+1,n,false,dp))%1000000007;
        }
        return dp[i][flag]=(solver(i+1,n,false,dp)+solver(i+2,n,false,dp)+2L*solver(i+2,n,true,dp))%1000000007;
    }
    int numTilings(int n) {
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return solver(0,n,false,dp);
    }
};