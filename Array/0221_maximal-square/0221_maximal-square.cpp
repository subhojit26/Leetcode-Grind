/*
 * Problem  : 221. Maximal Square
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Matrix
 * URL      : https://leetcode.com/problems/maximal-square/
 */

class Solution {
public:
    int solver(int i, int j, int n, int m, vector<vector<char>> &matrix, int &maxi, vector<vector<int>> &dp){
        if(i>=n || j>=m){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int right=solver(i+1,j,n,m,matrix,maxi,dp);
        int down=solver(i,j+1,n,m,matrix,maxi,dp);
        int diag=solver(i+1,j+1,n,m,matrix,maxi,dp);
        if(matrix[i][j]=='1'){
            int ans=1+min({right,down,diag});
            maxi=max(maxi,ans);
            dp[i][j]=ans;
            return ans;
        }
        else{
            return 0;
        }
    }
    int tabulateSolver(vector<vector<char>> &matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        int maxi=0;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                int right=dp[i+1][j];
                int diag=dp[i+1][j+1];
                int down=dp[i][j+1];

                if(matrix[i][j]=='1'){
                    int ans=1+min({right,down,diag});
                    maxi=max(maxi,ans);
                    dp[i][j]=ans;
                }
            }
        }
        return maxi*maxi;
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int maxi=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        //int side= solver(0,0,n,m,matrix,maxi,dp);
        int area=tabulateSolver(matrix);
        return area;
    }
};