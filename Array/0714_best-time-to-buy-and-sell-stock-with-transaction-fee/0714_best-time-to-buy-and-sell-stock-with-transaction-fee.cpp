/*
 * Problem  : 714. Best Time to Buy and Sell Stock with Transaction Fee
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Greedy
 * URL      : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
 */

class Solution {
public:
    int solver(int ind, vector<int> &prices, int fee, bool buy){
        if(ind>=prices.size()){
            return 0;
        }
        int profit=0;

        if(buy){
            profit= max(-prices[ind]+solver(ind+1,prices,fee,false),solver(ind+1,prices,fee,true));
            
        }
        if(!buy){
            profit= max(solver(ind+1,prices,fee,false),prices[ind]+solver(ind+1,prices,fee,true)-fee);
        }
        
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        bool buy=true;
        return solver(0,prices,fee,buy);
    }
};