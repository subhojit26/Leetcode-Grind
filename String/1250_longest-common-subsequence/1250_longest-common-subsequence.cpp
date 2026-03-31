/*
 * Problem  : 1250. Longest Common Subsequence
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming
 * URL      : https://leetcode.com/problems/longest-common-subsequence/
 */

class Solution {
public:
    int solver(int i, int j, string text1, string text2, vector<vector<int>> &dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(text1[i]==text2[j]){
            cout<<text1[i];
            return dp[i][j]=1+solver(i-1,j-1,text1,text2,dp);
        }
        return dp[i][j]=max(solver(i-1,j,text1,text2,dp),solver(i,j-1,text1,text2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solver(n-1,m-1,text1,text2,dp);
    }
};