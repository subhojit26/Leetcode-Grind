/*
 * Problem  : 494. Target Sum
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Backtracking
 * URL      : https://leetcode.com/problems/target-sum/
 */

class Solution {
public:
    int solver(int ind, int sum, int n, vector<int> &nums, int target, vector<vector<long long int>> &dp, int offset){
        if(ind==n){
            if(sum==target){
                return 1;
            }
            else{
                return 0;
            }
        }
        if(dp[ind][sum+offset]!=-1){
            return dp[ind][sum+offset];
        }
        return dp[ind][sum+offset]=solver(ind+1,sum+nums[ind],n,nums,target,dp,offset)+solver(ind+1,sum-nums[ind],n,nums,target,dp,offset);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
        int offset=1000;
        vector<vector<long long int>> dp(22, vector<long long int>(2002,-1));
        return solver(0,sum,n,nums,target,dp,offset);
    }
};