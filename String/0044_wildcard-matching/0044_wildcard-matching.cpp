/*
 * Problem  : 44. Wildcard Matching
 * Difficulty: Hard
 * Topics   : String, Dynamic Programming, Greedy, Recursion
 * URL      : https://leetcode.com/problems/wildcard-matching/
 */

class Solution {
public:
    bool solver(int si, int pi, int n, int m, string &s, string &p, vector<vector<int>> &dp){
        if(si>=n && pi>=m){
            return true;
        }
        if(si<n && pi>=m){
            return false;
        }

        if(si>=n && pi<m){
            while(pi<m){
                while(p[pi]!='*'){
                    return false;
                }
                pi++;
            }
            return true;
        }
        if(dp[si][pi]!=-1){
            return dp[si][pi];
        }

        if(s[si]==p[pi] || p[pi]=='?'){
            return dp[si][pi]= solver(si+1,pi+1,n,m,s,p,dp);
        }
        if(p[pi]=='*'){
            return dp[si][pi]= solver(si+1,pi,n,m,s,p,dp)|solver(si,pi+1,n,m,s,p,dp);
        }
        return dp[si][pi]= false;
        
    }
    bool isMatch(string s, string p) {
        int n=s.length();
        int m=p.length();
        vector<vector<int>> dp(n+1, vector<int>(m+1,-1));
        return solver(0,0,n,m,s,p,dp);
    }
};