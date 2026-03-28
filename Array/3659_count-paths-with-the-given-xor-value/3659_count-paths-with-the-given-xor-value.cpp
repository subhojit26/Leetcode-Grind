/*
 * Problem  : 3659. Count Paths With the Given XOR Value
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Bit Manipulation, Matrix
 * URL      : https://leetcode.com/problems/count-paths-with-the-given-xor-value/
 */

class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int mod=1e9+7;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(16, 0)));

        dp[0][0][grid[0][0]]=1;

        for (int i=0;i<m;i++) {
            for (int j=0;j<n;j++) {
                for (int xval=0;xval<16;xval++) {
                    if (dp[i][j][xval]==0) 
                        continue; 

                    if (i+1<m) {
                        dp[i+1][j][xval^grid[i+1][j]]= 
                            (dp[i+1][j][xval^grid[i+1][j]]+dp[i][j][xval])% mod;
                    }

                    if (j+1<n){
                        dp[i][j+1][xval^grid[i][j+1]]= 
                            (dp[i][j+1][xval^grid[i][j+1]]+dp[i][j][xval]) % mod;
                    }
                }
            }
        }

        return dp[m-1][n-1][k];
    }
};
