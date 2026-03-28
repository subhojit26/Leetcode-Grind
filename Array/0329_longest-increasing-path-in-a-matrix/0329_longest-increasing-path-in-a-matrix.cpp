/*
 * Problem  : 329. Longest Increasing Path in a Matrix
 * Difficulty: Hard
 * Topics   : Array, Dynamic Programming, Depth-First Search, Breadth-First Search, Graph Theory, Topological Sort, Memoization, Matrix
 * URL      : https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
 */

class Solution {
public:
    int maxi=0;
    int solve(int i,int j, int m, int n, int nrow[], int ncol[], vector<vector<int>> &matrix,vector<vector<int>> &dp){
        int curr=1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        for(int r=0;r<4;r++){
            int delrow=i+nrow[r];
            int delcol=j+ncol[r];

            if(delrow>=0 && delrow<m && delcol>=0 && delcol<n && matrix[i][j]<matrix[delrow][delcol]){
                curr=max(curr,1+solve(delrow,delcol,m,n,nrow,ncol,matrix,dp));
            }

            
        }
        maxi=max(maxi,curr);
        return dp[i][j]=curr;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        int nrow[]={-1,0,1,0};
        int ncol[]={0,1,0,-1};

        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                solve(i,j,m,n,nrow,ncol,matrix,dp);
            }
        }
        return maxi;
    }
};