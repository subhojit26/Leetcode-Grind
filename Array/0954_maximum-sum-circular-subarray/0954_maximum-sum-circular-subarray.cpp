/*
 * Problem  : 954. Maximum Sum Circular Subarray
 * Difficulty: Medium
 * Topics   : Array, Divide and Conquer, Dynamic Programming, Queue, Monotonic Queue
 * URL      : https://leetcode.com/problems/maximum-sum-circular-subarray/
 */

class Solution {
public:
    int kadane(vector<int> nums){
        int maxi=INT_MIN;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            if(curr<0){
                curr=0;
            }
        }
        return maxi;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int nonCircularSum=kadane(nums);
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
            nums[i]=-nums[i];
        }
        int circularSum=totalSum+kadane(nums);
        if(circularSum==0){
            return nonCircularSum;
        }
        
        return max(circularSum,nonCircularSum); 
    }
};