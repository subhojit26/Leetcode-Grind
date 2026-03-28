/*
 * Problem  : 2690. House Robber IV
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Dynamic Programming, Greedy
 * URL      : https://leetcode.com/problems/house-robber-iv/
 */

class Solution {
public:
    int solver(int mid, vector<int> &nums, int k){
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=mid){
                count++;
                i++;
            }
        }
        if(count>=k){
            return true;
        }
        return false;
    }
    int minCapability(vector<int>& nums, int k) {
        int left=1;
        int right=*max_element(nums.begin(),nums.end());
        int ans=right;
        while(left<=right){
            int mid=(left+right)/2;
            if(solver(mid,nums,k)){
                ans=mid;
                right=mid-1;
            } else{
                left=mid+1;
            }
        }
        return ans;
    }
};