/*
 * Problem  : 209. Minimum Size Subarray Sum
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Sliding Window, Prefix Sum
 * URL      : https://leetcode.com/problems/minimum-size-subarray-sum/
 */

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int i=0;
        int j=0;
        int mn=INT_MAX;
        while(j<nums.size()){
            sum+=nums[j];
            while(sum>=target){
                if(sum>=target){
                    mn=min(mn,j-i+1);
                }
                sum-=nums[i];
                i++;
                if(sum>=target){
                    mn=min(mn,j-i+1);
                }
            }
        j++;
    }
    if(mn==INT_MAX){
        return 0;
    }
    return mn;
    }
};