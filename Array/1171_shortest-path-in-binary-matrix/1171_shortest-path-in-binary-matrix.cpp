/*
 * Problem  : 1171. Shortest Path in Binary Matrix
 * Difficulty: Medium
 * Topics   : Array, Breadth-First Search, Matrix
 * URL      : https://leetcode.com/problems/shortest-path-in-binary-matrix/
 */

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<int, pair<int, int>>> q;
        int delrow[]={-1,-1,0,1,1,1,0,-1};
        int delcol[]={0,1,1,1,0,-1,-1,-1};
        q.push({0,{0,0}});
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        if(grid[0][0]==1){
            return -1;
        }
        if(n==1){
            return 1;
        }

        while(!q.empty()){
            int dis=q.front().first;
            int r=q.front().second.first;
            int c=q.front().second.second;
            q.pop();

            for(int i=0;i<8;i++){
                int nr=r+delrow[i];
                int nc=c+delcol[i];
                if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==0 && dis+1<dist[nr][nc]){
                    dist[nr][nc]=dis+1;
                    if(nr==n-1 && nc==n-1){
                        return dis+1+1;
                    }
                    q.push({dist[nr][nc],{nr,nc}});
                }
            }
        }
        return -1;
    }
};