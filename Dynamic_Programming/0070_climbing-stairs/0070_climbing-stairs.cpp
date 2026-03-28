/*
 * Problem  : 70. Climbing Stairs
 * Difficulty: Easy
 * Topics   : Math, Dynamic Programming, Memoization
 * URL      : https://leetcode.com/problems/climbing-stairs/
 */

class Solution {
public:
    int solve(int i, int n, vector<int> &dp){
        if(i==n){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }

        return dp[i]=solve(i+1,n,dp)+solve(i+2,n,dp);
    }
    int climbStairs(int n) {
        int i=0;
        vector<int> dp(n+1,-1);
        return solve(i,n,dp);
    }
};