/*
 * Problem  : 1236. N-th Tribonacci Number
 * Difficulty: Easy
 * Topics   : Math, Dynamic Programming, Memoization
 * URL      : https://leetcode.com/problems/n-th-tribonacci-number/
 */

class Solution {
public:
    int solver(int n,vector<int> &dp){
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return solver(n-1,dp)+solver(n-2,dp)+solver(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int> dp(n+1,-1);
        return solver(n,dp);
    }
};