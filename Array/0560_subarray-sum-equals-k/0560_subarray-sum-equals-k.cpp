/*
 * Problem  : 560. Subarray Sum Equals K
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Prefix Sum
 * URL      : https://leetcode.com/problems/subarray-sum-equals-k/
 */

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int>mp;
        int sum=0;
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum==k){
                ans++;
            }
            if(mp.find(sum-k)!=mp.end()){
                ans+=mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;
    }
};