/*
 * Problem  : 1073. Number of Enclaves
 * Difficulty: Medium
 * Topics   : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
 * URL      : https://leetcode.com/problems/number-of-enclaves/
 */

class Solution {
public:
    vector<int> delrow={-1,0,1,0};
    vector<int> delcol={0,1,0,-1};
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<int>> &grid){
        vis[i][j]=1;
        for(int x=0;x<4;x++){
            int nr=i+delrow[x];
            int nc=j+delcol[x];

            if(nr>=0 && nr<grid.size() && nc>=0 && nc<grid[0].size() && grid[nr][nc]==1 && vis[nr][nc]==0){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        vector<vector<int>> vis(n,vector<int> (m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && vis[i][j]==0 && grid[i][j]==1){
                    dfs(i,j,vis,grid);
                }
            }
        }
        int enclaves=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    enclaves++;
                }
            }
        }
        return enclaves;
    }
};