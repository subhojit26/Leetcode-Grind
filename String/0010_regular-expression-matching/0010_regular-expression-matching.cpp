/*
 * Problem  : 10. Regular Expression Matching
 * Difficulty: Hard
 * Topics   : String, Dynamic Programming, Recursion
 * URL      : https://leetcode.com/problems/regular-expression-matching/
 */

class Solution {
public:
    bool solver(int i, int j,string s, string p, vector<vector<int>> &dp){
        if(i<0 && j<0){
            return true;
        }
        if(i>=0 && j<0){
            return false;
        }
        if(i<0 && j>=0){
            for (int k = j; k >= 0; k -= 2) {
                if (p[k] != '*') return false;
            }
            return true;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==p[j] || p[j]=='.'){
            return dp[i][j]=solver(i-1,j-1,s,p,dp);
        }
        if (p[j] == '*') {
            // Consider zero occurrence of the character before '*'
            bool zeroOccur = solver(i, j - 2, s, p, dp);
            // Consider one or more occurrence if preceding char matches
            bool oneOrMoreOccur = (p[j - 1] == s[i] || p[j - 1] == '.') && solver(i - 1, j, s, p, dp);
            return dp[i][j] = zeroOccur || oneOrMoreOccur;
        }
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return solver(n-1,m-1,s,p,dp);
    }
};