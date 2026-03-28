/*
 * Problem  : 740. Delete and Earn
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Dynamic Programming
 * URL      : https://leetcode.com/problems/delete-and-earn/
 */

class Solution {
public:
    int solver(int ind, vector<int> &nums, vector<int>&dp){
        if(ind==nums.size()){
            return 0;
        }
        int currValue=nums[ind];
        int currSum=nums[ind];
        int index=ind+1;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        while(index<nums.size() && nums[index]==currValue){
            currSum+=currValue;
            index++;
        }
        while(index<nums.size() && nums[index]==currValue+1){
            index++;
        }
        return dp[ind]=max(currSum+solver(index,nums,dp),solver(ind+1,nums,dp));
    }
    int deleteAndEarn(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size()+1,-1);
        
        return solver(0,nums,dp);
    }
};