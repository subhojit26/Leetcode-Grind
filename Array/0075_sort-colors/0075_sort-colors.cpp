/*
 * Problem  : 75. Sort Colors
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Sorting
 * URL      : https://leetcode.com/problems/sort-colors/
 */

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int m=0;
        int r=n-1;
        while(m<n && m<=r){
            if(nums[m]==0){
                swap(nums[l],nums[m]);
                l++;
                m++;
            }else if(nums[m]==2){
                swap(nums[r],nums[m]);
                r--;
            
            }else{
                m++;
            }
        }
    }
};