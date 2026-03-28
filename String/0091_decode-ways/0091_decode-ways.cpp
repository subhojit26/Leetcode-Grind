/*
 * Problem  : 91. Decode Ways
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming
 * URL      : https://leetcode.com/problems/decode-ways/
 */

class Solution {
public:
    int solver(int ind, int len, string &s, vector<int> &dp){
        if(ind==len){
            return 1;
        }
        if(s[ind]=='0'){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int count=solver(ind+1,len,s,dp);

        if(ind+1<len && (s[ind]=='1' || (s[ind]=='2' && s[ind+1]<='6'))){
            count+=solver(ind+2,len,s,dp);
        }
        return dp[ind]=count;
    }
    int numDecodings(string s) {
        int ind=0;
        int len=s.length();
        vector<int> dp(len+1,-1);
        return solver(ind,len,s,dp);
    }
};