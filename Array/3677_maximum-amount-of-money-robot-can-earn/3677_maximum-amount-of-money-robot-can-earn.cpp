/*
 * Problem  : 3677. Maximum Amount of Money Robot Can Earn
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Matrix
 * URL      : https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
 */

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m=coins.size();
        int n=coins[0].size();

        int NEG_INF=-1e9;

        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, NEG_INF)));

        dp[0][0][0]=coins[0][0]; 
        dp[0][0][1]=(coins[0][0]<0?0:coins[0][0]); 
        dp[0][0][2]=(coins[0][0]<0?0:coins[0][0]); 

        for (int i=0;i<m;++i){
            for (int j=0;j<n;++j){
                for (int k=0;k<3;++k){
                    if (dp[i][j][k]==NEG_INF) continue; 
                    
                    int cellValue=coins[i][j];

                    if(i+1<m){
                        dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]+coins[i + 1][j]);
                        if (k+1<3 &&coins[i+1][j]<0) {
                            dp[i+1][j][k+1]=max(dp[i+1][j][k+1],dp[i][j][k]);
                        }
                    }

                    if (j+1<n) {
                        dp[i][j+1][k]=max(dp[i][j + 1][k],dp[i][j][k]+coins[i][j + 1]);
                        if (k+1<3&&coins[i][j+1]<0) {
                            dp[i][j+1][k+1]=max(dp[i][j+1][k+1],dp[i][j][k]); 
                        }
                    }
                }
            }
        }

        return max({dp[m-1][n-1][0],dp[m-1][n-1][1],dp[m-1][n-1][2]});
    }
};
