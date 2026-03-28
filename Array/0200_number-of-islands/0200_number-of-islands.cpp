/*
 * Problem  : 200. Number of Islands
 * Difficulty: Medium
 * Topics   : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
 * URL      : https://leetcode.com/problems/number-of-islands/
 */

class Solution {
public:
    void dfs(int i, int j, vector<vector<int>> &vis, vector<vector<char>> &grid){
        vis[i][j]=1;
        vector<int> dx={-1,1,0,0};
        vector<int> dy={0,0,-1,1};
        for(int k=0;k<4;k++){
            int nr=i+dx[k];
            int nc=j+dy[k];

            if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && vis[nr][nc]==0 && grid[nr][nc]=='1'){
                dfs(nr,nc,vis,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;

    }
};