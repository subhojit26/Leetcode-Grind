/*
 * Problem  : 3621. Minimum Operations to Make Array Values Equal to K
 * Difficulty: Easy
 * Topics   : Array, Hash Table
 * URL      : https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
 */

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        map<int,int> mp;
        int cnt=0;
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        if(k>nums[n-1]){
            return -1;
        }
        
        if(k==nums[n-1]){
            return mp.size()-1;
        }

        if(k<nums[n-1]){
            return mp.size();
        }
        return -1;
    }
};