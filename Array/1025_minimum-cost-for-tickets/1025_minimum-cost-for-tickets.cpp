/*
 * Problem  : 1025. Minimum Cost For Tickets
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/minimum-cost-for-tickets/
 */

class Solution {
public:
    int solver(int ind, vector<int> &days, vector<int> &costs, vector<int> &dp){
        if(ind>=days.size()){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        int oneDay=costs[0]+solver(ind+1,days,costs,dp);
        int day=lower_bound(days.begin(),days.end(),days[ind]+7)-days.begin();
        int sevenDay=costs[1]+solver(day,days,costs,dp);
        day=lower_bound(days.begin(),days.end(),days[ind]+30)-days.begin();
        int thirtyDay=costs[2]+solver(day,days,costs,dp);
        return dp[ind]=min({oneDay,sevenDay,thirtyDay});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(366,-1);
        return solver(0,days,costs,dp);
    }
};