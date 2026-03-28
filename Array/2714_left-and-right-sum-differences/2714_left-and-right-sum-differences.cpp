/*
 * Problem  : 2714. Left and Right Sum Differences
 * Difficulty: Easy
 * Topics   : Array, Prefix Sum
 * URL      : https://leetcode.com/problems/left-and-right-sum-differences/
 */

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefix(n+2,0);
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+nums[i];
        }
        
        for(int i=1;i<=n;i++){
            int leftSum=prefix[i-1];
            int rightSum=prefix[n]-prefix[i];
            ans.push_back(abs(rightSum-leftSum));
        }
        return ans;
    }
};