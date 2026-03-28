/*
 * Problem  : 121. Best Time to Buy and Sell Stock
 * Difficulty: Easy
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
 */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTillNow=INT_MAX;
        int profit=INT_MIN;
        for(int i=0;i<prices.size();i++){
            minTillNow=min(minTillNow,prices[i]);
            profit=max(profit,prices[i]-minTillNow);
        }
        return profit;
    }
};