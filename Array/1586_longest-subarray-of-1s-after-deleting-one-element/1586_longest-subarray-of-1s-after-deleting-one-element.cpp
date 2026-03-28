/*
 * Problem  : 1586. Longest Subarray of 1's After Deleting One Element
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Sliding Window
 * URL      : https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 */

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0;
        int z=0;
        int mx=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                z++;
            }
            while(z>1){
                if(nums[l]==0){
                    z--;
                }
                l++;
            }
            mx=max(mx,i-l);
        }
        return mx;
    }
};