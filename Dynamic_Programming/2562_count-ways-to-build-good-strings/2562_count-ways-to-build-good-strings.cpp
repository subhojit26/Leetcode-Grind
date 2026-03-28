/*
 * Problem  : 2562. Count Ways To Build Good Strings
 * Difficulty: Medium
 * Topics   : Dynamic Programming
 * URL      : https://leetcode.com/problems/count-ways-to-build-good-strings/
 */

class Solution {
public:
    int solver(int ind, int low, int high, int zero, int one, vector<int> &dp){
        if(ind>high){
            return 0;
        }
        int count=0;
        if(ind>=low){
            count= 1;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        count+=solver(ind+zero, low,high,zero,one,dp)%1000000007;
        count+=solver(ind+one,low,high,zero,one,dp)%1000000007;
        return dp[ind]=count%1000000007;

    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ind=0;
        vector<int> dp(100005,-1);

        return solver(ind, low, high, zero, one,dp);
    }
};