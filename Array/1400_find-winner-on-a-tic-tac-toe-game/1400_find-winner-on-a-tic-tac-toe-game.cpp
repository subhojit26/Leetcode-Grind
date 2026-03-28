/*
 * Problem  : 1400. Find Winner on a Tic Tac Toe Game
 * Difficulty: Easy
 * Topics   : Array, Hash Table, Matrix, Simulation
 * URL      : https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/
 */

class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<char>> mp(3, vector<char>(3, -1));
        int n=moves.size();
        int t=1;
        for(int i=0;i<n;i++){
            int x=moves[i][0];
            int y=moves[i][1];
            if(i%2==0){
                mp[x][y]='X';
            }else{
                mp[x][y]='O';
            }
        }

        for(int i=0;i<3;i++){
            char ch=mp[t][i];
            if(i==t){
                if((mp[t-1][i-1]==ch && mp[t+1][i+1]==ch) || (mp[t-1][i+1]==ch && mp[t+1][i-1]==ch)){
                if(ch=='X'){
                    return "A";
                }else if(ch=='O'){
                    return "B";
                }
                }
            }
            if(mp[t-1][i]==ch && mp[t+1][i]==ch){
                if(ch=='X'){
                    return "A";
                }else if(ch=='O'){
                    return "B";
                }
            }
        }
        for(int i=0;i<3;i++){
            char ch=mp[i][t];
            if(i==t){
                if((mp[t-1][i-1]==ch && mp[t+1][i+1]==ch) || (mp[t-1][i+1]==ch && mp[t+1][i-1]==ch)){
                if(ch=='X'){
                    return "A";
                }else if(ch=='O'){
                    return "B";
                }
            }
            }
            if(mp[i][t-1]==ch && mp[i][t+1]==ch){
                if(ch=='X'){
                    return "A";
                }else if(ch=='O'){
                    return "B";
                }
            }
        }
        if(n==9){
            return "Draw";
        }
        return "Pending";
    }
};