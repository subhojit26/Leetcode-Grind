/*
 * Problem  : 79. Word Search
 * Difficulty: Medium
 * Topics   : Array, String, Backtracking, Depth-First Search, Matrix
 * URL      : https://leetcode.com/problems/word-search/
 */

class Solution {
public:
    bool dfs(int it, int i, int j, vector<vector<int>> vis, int m, int n, vector<vector<char>> &board, string word,string temp, vector<int> dr, vector<int> dc){
        if(it>word.length()){
            return false;
        }
        vis[i][j]=1;
        if(temp==word){
            return true;
        }
        cout<<temp<<" ";
        for(int z=0;z<4;z++){
            int nr=i+dr[z];
            int nc=j+dc[z];

            if(nr>=0 && nr<m && nc>=0 && nc<n && vis[nr][nc]==0 && board[nr][nc]==word[it]){
                temp=temp+word[it];
                return dfs(it+1,nr,nc,vis,m,n,board,word,temp,dr,dc);
            }
        }
        return false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<int> dr={-1,1,0,0};
        vector<int> dc={0,0,-1,1};
        int m=board.size();
        int n=board[0].size();

        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(dfs(0,i,j,vis,m,n,board,word,"",dr,dc)){
                    return true;
                }
            }
        }
        return false;
    }
};