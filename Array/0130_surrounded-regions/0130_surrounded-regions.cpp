/*
 * Problem  : 130. Surrounded Regions
 * Difficulty: Medium
 * Topics   : Array, Depth-First Search, Breadth-First Search, Union-Find, Matrix
 * URL      : https://leetcode.com/problems/surrounded-regions/
 */

class Solution {
public:

    void dfs(int i, int j, int n, int m, vector<vector<int>> &vis, vector<vector<char>> &board, vector<int> nrow, vector<int> ncol){
        vis[i][j]=1;

        for(int r=0;r<4;r++){
            int delrow=i+nrow[r];
            int delcol=j+ncol[r];

            if(delrow>=0 && delrow<n && delcol>=0 && delcol<m && vis[delrow][delcol]==0 && board[delrow][delcol]=='O'){
                dfs(delrow,delcol,n,m,vis,board,nrow,ncol);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<int> nrow={-1,0,1,0};
        vector<int> ncol={0,1,0,-1};

        vector<vector<int>> vis (n, vector<int> (m,0));

        for(int i=0;i<n;i++){
            if(vis[i][0]==0 && board[i][0]=='O'){
                dfs(i,0,n,m,vis,board,nrow,ncol);
            }
            if(vis[i][m-1]==0 && board[i][m-1]=='O'){
                dfs(i,m-1,n,m,vis,board,nrow,ncol);
            }
        }

        for(int j=0;j<m;j++){
            if(vis[0][j]==0 && board[0][j]=='O'){
                dfs(0,j,n,m,vis,board,nrow,ncol);
            }
            if(vis[n-1][j]==0 && board[n-1][j]=='O'){
                dfs(n-1,j,n,m,vis,board,nrow,ncol);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==0 && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};