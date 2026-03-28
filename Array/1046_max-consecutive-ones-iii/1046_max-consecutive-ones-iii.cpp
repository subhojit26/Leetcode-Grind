/*
 * Problem  : 1046. Max Consecutive Ones III
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Sliding Window, Prefix Sum
 * URL      : https://leetcode.com/problems/max-consecutive-ones-iii/
 */

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;
        int mx=0;
        int z=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }
            while(z>k){
                if(nums[l]==0){
                    z--;
                }
                l++;
            }
            mx=max(i-l+1,mx);
        }
        return mx;
    }
};