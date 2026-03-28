/*
 * Problem  : 1570. Final Prices With a Special Discount in a Shop
 * Difficulty: Easy
 * Topics   : Array, Stack, Monotonic Stack
 * URL      : https://leetcode.com/problems/final-prices-with-a-special-discount-in-a-shop/
 */

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n=prices.size();
        for(int i=0;i<n;i++){
            int temp=-1;
            for(int j=i+1;j<n;j++){
                if(prices[j]<=prices[i]){
                    temp=prices[j];
                    break;
                }
            }
            if(temp!=-1){
                prices[i]-=temp;
            }
        }
        return prices;
    }
};