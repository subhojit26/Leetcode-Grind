/*
 * Problem  : 2038. Nearest Exit from Entrance in Maze
 * Difficulty: Medium
 * Topics   : Array, Breadth-First Search, Matrix
 * URL      : https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/
 */

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m=maze.size();
        int n=maze[0].size();

        vector<vector<int>> vis(m,vector<int>(n,0));
        int entry_row=entrance[0];
        int entry_col=entrance[1];
        queue<pair<pair<int,int>,int>> q;
        q.push({{entry_row,entry_col},0});
        vis[entry_row][entry_col]=1;
        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};
        int minDist=n*n+n;

        while(!q.empty()){
            int row=q.front().first.first;
            int col=q.front().first.second;
            int dist=q.front().second;
            q.pop();
            if((row==0 || col==0 || row==m-1 || col==n-1) && 
   !(row==entry_row && col==entry_col)){
    minDist = min(minDist, dist);
}
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];

                if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && maze[nr][nc]=='.'){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},dist+1});
                }
            }
        }
        return minDist==n*n+n?-1:minDist;
    }
};