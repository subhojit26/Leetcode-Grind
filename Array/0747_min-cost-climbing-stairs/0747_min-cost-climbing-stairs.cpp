/*
 * Problem  : 747. Min Cost Climbing Stairs
 * Difficulty: Easy
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/min-cost-climbing-stairs/
 */

class Solution {
public:
    int solver(int ind, vector<int> &cost, vector<int> &dp){
        if(ind>=cost.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }

        int one=cost[ind]+solver(ind+1,cost,dp);
        int two=cost[ind]+solver(ind+2,cost,dp);
        return dp[ind]=min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(solver(0,cost,dp),solver(1,cost,dp));
    }
};