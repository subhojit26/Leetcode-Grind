/*
 * Problem  : 62. Unique Paths
 * Difficulty: Medium
 * Topics   : Math, Dynamic Programming, Combinatorics
 * URL      : https://leetcode.com/problems/unique-paths/
 */

class Solution {
public:
    int solver(int m, int n, vector<vector<int>> &dp){
        if(m==0 && n==0){
            return 1;
        }
        if(m<0 || n<0){
            return 0;
        }
        if(dp[m][n]!=-1){
            return dp[m][n];
        }
        return dp[m][n]=solver(m-1,n,dp)+solver(m,n-1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int> (n,-1));
        return solver(m-1,n-1,dp);
    }
};