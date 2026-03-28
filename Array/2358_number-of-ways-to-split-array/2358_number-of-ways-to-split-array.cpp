/*
 * Problem  : 2358. Number of Ways to Split Array
 * Difficulty: Medium
 * Topics   : Array, Prefix Sum
 * URL      : https://leetcode.com/problems/number-of-ways-to-split-array/
 */

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int l=0;
        long long int currSum=0;
        int ans=0;
        while(l<nums.size()-1){
            currSum+=nums[l];
            sum-=nums[l];
            if(currSum>=sum){
                ans++;
            }
            l++;
        }
        return ans;
    }
};