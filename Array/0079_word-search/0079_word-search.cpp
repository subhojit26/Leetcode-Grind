/*
 * Problem  : 79. Word Search
 * Difficulty: Medium
 * Topics   : Array, String, Backtracking, Depth-First Search, Matrix
 * URL      : https://leetcode.com/problems/word-search/
 */

class Solution {
public:
    bool dfs(int it, int i, int j, vector<vector<int>> vis, int m, int n, vector<vector<char>> &board, string word, vector<int> dr, vector<int> dc){
        if(it==word.length()){
            return true;
        }

        vis[i][j]=1;

        for(int z=0;z<4;z++){
            int nr=i+dr[z];
            int nc=j+dc[z];

            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && board[nr][nc]==word[it]){
                if(dfs(it+1,nr,nc,vis,m,n,board,word,dr,dc)){
                    return true;
                }
            }
        }
        vis[i][j]=0;
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                vector<vector<int>> vis(m, vector<int>(n,0));

                    if(dfs(1,i,j,vis,m,n,board,word,dr,dc)){
                        return true;
                    }
            }
        }
        }
        return false;
    }
};