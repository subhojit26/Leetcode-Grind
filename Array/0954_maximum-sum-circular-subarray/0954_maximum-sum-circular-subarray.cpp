/*
 * Problem  : 954. Maximum Sum Circular Subarray
 * Difficulty: Medium
 * Topics   : Array, Divide and Conquer, Dynamic Programming, Queue, Monotonic Queue
 * URL      : https://leetcode.com/problems/maximum-sum-circular-subarray/
 */

class Solution {
public:
    int kadane(vector<int> nums){
        int sum=0;
        int mx=INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            mx=max(sum,mx);
            if(sum<0){
                sum=0;
            }
        }
        return mx;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int ncSum=kadane(nums);
        int totalSum=0;
        for(int i=0;i<nums.size();i++){
            totalSum+=nums[i];
            nums[i]=-nums[i];
        }
        int cSum=totalSum+kadane(nums);
        if(cSum==0){
            return ncSum;
        }
        cout<<totalSum<<" ";
        cout<<cSum<<" "<<ncSum<<" ";
        return max(cSum,ncSum);
    }
};