/*
 * Problem  : 747. Min Cost Climbing Stairs
 * Difficulty: Easy
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/min-cost-climbing-stairs/
 */

class Solution {
public:
    int solver(int ind, vector<int> &cost){
        if(ind>=cost.size()){
            return 0;
        }

        int one=cost[ind]+solver(ind+1,cost);
        int two=cost[ind]+solver(ind+2,cost);
        return min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        return min(solver(0,cost),solver(1,cost));
    }
};