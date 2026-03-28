/*
 * Problem  : 713. Subarray Product Less Than K
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Sliding Window, Prefix Sum
 * URL      : https://leetcode.com/problems/subarray-product-less-than-k/
 */

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int p=1;
        int n=nums.size();
        int left=0;
        int right=0;
        int ans=0;
        if(k<=1){
            return 0;
        }
        while(right<n){
            p=p*nums[right];
            while(p>=k){
                p=p/nums[left];
                left++;
            }
            ans+=1+(right-left);
            right++;
        }
        return ans;
    }
};