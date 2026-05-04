/*
 * Problem  : 80. Remove Duplicates from Sorted Array II
 * Difficulty: Medium
 * Topics   : Array, Two Pointers
 * URL      : https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/
 */

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=1;
        int k=1;
        while(r<n){
            if(nums[l]==nums[r]){
                r++;
            }
            else {
                l++;
                k++;
                nums[l]=nums[r];
                r++;
            }
        }
        return k;
    }
};