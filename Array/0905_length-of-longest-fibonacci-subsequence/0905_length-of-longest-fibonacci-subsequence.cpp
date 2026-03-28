/*
 * Problem  : 905. Length of Longest Fibonacci Subsequence
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Dynamic Programming
 * URL      : https://leetcode.com/problems/length-of-longest-fibonacci-subsequence/
 */

class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int maxLen=0;
        int n=arr.size();
        vector<vector<int>> dp(n, vector<int>(n,0));
        for(int i=2;i<n;i++){
            int start=0;
            int end=i-1;
            while(start<end){
                int currSum=arr[start]+arr[end];
                if(currSum>arr[i]){
                    end--;
                }
                else if(currSum<arr[i]){
                    start++;
                }
                else{
                    dp[end][i]=dp[start][end]+1;
                    maxLen=max(maxLen,dp[end][i]);
                    end--;
                    start++;
                }
            }
        }
        return maxLen==0?0:maxLen+2;
    }
};