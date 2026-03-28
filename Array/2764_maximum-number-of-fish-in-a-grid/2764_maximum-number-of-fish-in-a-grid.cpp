/*
 * Problem  : 2764. Maximum Number of Fish in a Grid
 * Difficulty: Medium
 * Topics   : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
 * URL      : https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
 */

class Solution {
public:
    int dfs(int i, int j, int m, int n, vector<vector<int>> &grid){
        if(i<0 || i>=m || j<0 || j>=n || grid[i][j]==0){
            return 0;
        }      
        int curr=grid[i][j];
        grid[i][j]=0;
        curr+=dfs(i+1,j,m,n,grid);
        curr+=dfs(i-1,j,m,n,grid);
        curr+=dfs(i,j+1,m,n,grid);
        curr+=dfs(i,j-1,m,n,grid);
        return curr;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    ans=max(ans,dfs(i,j,m,n,grid));
                }
            }
        }
        return ans;
    }
};