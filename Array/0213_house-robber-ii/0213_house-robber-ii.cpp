/*
 * Problem  : 213. House Robber II
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/house-robber-ii/
 */

class Solution {
public:
    int solve(int ind, vector<int> t, int n,vector<int> &dp){
        if(ind>n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        return dp[ind]=(max(t[ind]+solve(ind+2,t,n,dp),solve(ind+1,t,n,dp)));
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        int ind=0;
        vector<int> dp1(n+1,-1);
        vector<int> dp2(n+1,-1);
        if(n==1){
            return nums[0];
        }
        if(n==2){
            return max(nums[0],nums[1]);
        }
        return max(solve(ind,nums,n-2,dp1),solve(ind+1,nums,n-1,dp2));
    }
};