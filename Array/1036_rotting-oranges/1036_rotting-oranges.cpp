/*
 * Problem  : 1036. Rotting Oranges
 * Difficulty: Medium
 * Topics   : Array, Breadth-First Search, Matrix
 * URL      : https://leetcode.com/problems/rotting-oranges/
 */

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int minTime=0;
        int count=0;
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
                if(grid[i][j]!=0){
                    count++;
                }
            }
        }
        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};
        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int time=q.front().second;
            q.pop();
            minTime=time;

            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    grid[nr][nc]=2;
                    q.push({{nr,nc},time+1});
                }
            }
        }
        int bad=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    bad++;
                }
            }
        }
        if(bad!=count) return -1;
        return minTime;
    }
};