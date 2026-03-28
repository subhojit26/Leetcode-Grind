/*
 * Problem  : 300. Longest Increasing Subsequence
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Dynamic Programming
 * URL      : https://leetcode.com/problems/longest-increasing-subsequence/
 */

class Solution {
public:
    int solve(int ind,int prev, vector<int> &nums, int n, vector<vector<int>> &dp){
        if(ind>=n){
            return 0;
        }
        if(dp[ind][prev+1]!=-1){
            return dp[ind][prev+1];
        }

        if(prev==-1 || nums[ind]>nums[prev]){
            return dp[ind][prev+1]= max(1+solve(ind+1,ind,nums,n,dp),solve(ind+1,prev,nums,n,dp));
        }

        return dp[ind][prev+1]= solve(ind+1,prev,nums,n,dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        int ind=0;
        int prev=-1;
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(ind,prev,nums,n,dp);
    }
};