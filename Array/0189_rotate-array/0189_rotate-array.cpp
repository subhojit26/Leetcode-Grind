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
        for(int i=0;i<n/2;i++){
            if((i>=0 && i<k)||(i>=n-k && i<n)){
                swap(nums[i],nums[n-i-1]);
            }
        }
        reverseArray(nums,0,k-1);
        reverseArray(nums,k,n-1);
    }
};