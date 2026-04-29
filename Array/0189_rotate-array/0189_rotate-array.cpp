/*
 * Problem  : 189. Rotate Array
 * Difficulty: Medium
 * Topics   : Array, Math, Two Pointers
 * URL      : https://leetcode.com/problems/rotate-array/
 */

class Solution {
public:
    void reverseArray(vector<int> &nums, int l, int r){
        while(l<r){
            swap(nums[l],nums[r]);
            l++;
            r--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        reverseArray(nums,0,n-1);
        reverseArray(nums,0,k-1);
        reverseArray(nums,k,n-1);
    }
};