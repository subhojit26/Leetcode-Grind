/*
 * Problem  : 516. Longest Palindromic Subsequence
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming
 * URL      : https://leetcode.com/problems/longest-palindromic-subsequence/
 */

class Solution {
public:
    int solver(string &s, string &t, int n, int m, vector<vector<int>> &dp){
        if(n<0 || m<0){
            return 0;
        }

        if(dp[n][m]!=-1){
            return dp[n][m];
        }

        if(s[n]==t[m]){
            return dp[n][m]=1+solver(s,t,n-1,m-1,dp);
        }
        return dp[n][m]= max(solver(s,t, n-1,m,dp),solver(s,t,n,m-1,dp));
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int l=s.length();
        vector<vector<int>> dp(l+1, vector<int> (l+1,-1));
        return solver(s,t,l-1,l-1,dp);
    }
};