/*
 * Problem  : 1849. Maximum Absolute Sum of Any Subarray
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
 */

class Solution {
public:
    int kadane(vector<int> nums){
        int currMax=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            if(sum<0){
                sum=0;
            }
            currMax=max(currMax,sum);
        }
        return currMax;
    }
    int maxAbsoluteSum(vector<int>& nums) {
        vector<int> temp=nums;
        for(int i=0;i<temp.size();i++){
            temp[i]=-1*temp[i];
        }
        int ans1=kadane(nums);
        int ans2=kadane(temp);
        return max(ans1,ans2);
    }
};