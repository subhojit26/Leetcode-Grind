/*
 * Problem  : 53. Maximum Subarray
 * Difficulty: Medium
 * Topics   : Array, Divide and Conquer, Dynamic Programming
 * URL      : https://leetcode.com/problems/maximum-subarray/
 */

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum=0;
        int mx=INT_MIN;

        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            mx=max(mx,sum);
        }
        return mx;
    }
};