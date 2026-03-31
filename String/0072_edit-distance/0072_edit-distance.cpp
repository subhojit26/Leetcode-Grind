/*
 * Problem  : 72. Edit Distance
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming
 * URL      : https://leetcode.com/problems/edit-distance/
 */

class Solution {
public:
    int solver(int i, int j, string &word1, string &word2, vector<vector<int>> &dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(word1[i]==word2[j]){
            return dp[i][j]=solver(i-1,j-1,word1,word2,dp);
        }
        return dp[i][j]=1+min(solver(i-1,j-1,word1,word2,dp),min(solver(i-1,j,word1,word2,dp),solver(i,j-1,word1,word2,dp)));
    }
    int minDistance(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        if(n==0){
            return m;
        }
        if(m==0){
            return n;
        }
        vector<vector<int>> dp(n+1,vector<int>(m,-1));
        return solver(n-1,m-1,word1,word2,dp);
    }
};