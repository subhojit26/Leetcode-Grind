/*
 * Problem  : 198. House Robber
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/house-robber/
 */

class Solution {
public:
    int solver(int ind, vector<int> &nums,vector<int>&dp){
        if(ind>=nums.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int take=nums[ind]+solver(ind+2,nums,dp);
        int notTake=solver(ind+1,nums,dp);
        return dp[ind]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solver(0,nums,dp);
    }
};