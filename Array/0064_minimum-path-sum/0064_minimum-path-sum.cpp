/*
 * Problem  : 64. Minimum Path Sum
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Matrix
 * URL      : https://leetcode.com/problems/minimum-path-sum/
 */

class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp){
        if(i==0 && j==0){
            return grid[i][j];
        }
        
        if(i<0 || j<0){
            return INT_MAX;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return dp[i][j]=grid[i][j]+min(solve(i-1,j,grid,dp),solve(i,j-1,grid,dp));

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return solve(m-1,n-1,grid,dp);
    }
};