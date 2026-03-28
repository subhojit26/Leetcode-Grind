/*
 * Problem  : 120. Triangle
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/triangle/
 */

class Solution {
public:
    int solve(int r, int c, vector<vector<int>> &triangle, int n, vector<vector<int>> &dp){
        if(r==n){
            return 0;
        }
        if(dp[r][c]!=-1){
            return dp[r][c];
        }

        return dp[r][c]=triangle[r][c]+min(solve(r+1,c,triangle,n,dp),solve(r+1,c+1,triangle,n,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int r=0;
        int c=0;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));

        return solve(r,c,triangle,n,dp);
    }
};