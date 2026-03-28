/*
 * Problem  : 283. Move Zeroes
 * Difficulty: Easy
 * Topics   : Array, Two Pointers
 * URL      : https://leetcode.com/problems/move-zeroes/
 */

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=0;

        while(r<n && l<n){
            if(nums[r]!=0){
                swap(nums[r],nums[l]);
                l++;
            }
            r++;
        }

    }
};