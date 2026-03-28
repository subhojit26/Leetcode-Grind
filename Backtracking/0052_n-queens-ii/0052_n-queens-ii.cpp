/*
 * Problem  : 52. N-Queens II
 * Difficulty: Hard
 * Topics   : Backtracking
 * URL      : https://leetcode.com/problems/n-queens-ii/
 */

class Solution {
public:
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<char>> board(n, vector<char> (n,'.'));
        solve(0,n,board,ans);
        return ans.size();
    }
    void solve(int col, int n, vector<vector<char>> &board, vector<vector<string>> &ans){
        if(col==n){
            ans.push_back(construct(board,n));
            return;
        }

        for(int row=0;row<n;row++){
            if(isSafe(row,col,board,n)){
                board[row][col]='Q';
                solve(col+1,n,board,ans);
                board[row][col]='.';
            }
        }
    }
    bool isSafe(int row, int col, vector<vector<char>> &board, int n){
        int trow=row;
        int tcol=col;
        while(trow>=0 && tcol>=0){
            if(board[trow][tcol]=='Q'){
                return false;
            }
            trow--;
            tcol--;
        }
        trow=row;
        tcol=col;
        while(tcol>=0){
            if(board[trow][tcol]=='Q'){
                return false;
            }
            tcol--;
        }
        tcol=col;
        while(tcol>=0 && trow<n){
            if(board[trow][tcol]=='Q'){
                return false;
            }
            trow++;
            tcol--;
        }
        return true;
    }
    vector<string> construct(vector<vector<char>> &board, int n){
        vector<string> res;
        for(int i=0;i<n;i++){
            string temp="";
            for(int j=0;j<n;j++){
                temp+=board[i][j];
            }
            res.push_back(temp);
        }
        return res;
    }
};