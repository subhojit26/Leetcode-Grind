/*
 * Problem  : 2891. Maximum Beauty of an Array After Applying Operation
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Sliding Window, Sorting
 * URL      : https://leetcode.com/problems/maximum-beauty-of-an-array-after-applying-operation/
 */

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=0;
        int win_count=0;
        int max_count=0;
        int r=0;
        while(r<n){
            while(r<n && nums[r]-nums[l]<=2*k){
                win_count++;
                r++;
            }
            max_count=max(max_count,win_count);
            if(r>=n) break;

            while(l<=r && nums[r]-nums[l]>2*k){
                win_count--;
                l++;
            }
        }
        return max_count;
        
    }
};