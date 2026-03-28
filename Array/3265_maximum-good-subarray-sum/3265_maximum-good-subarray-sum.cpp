/*
 * Problem  : 3265. Maximum Good Subarray Sum
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Prefix Sum
 * URL      : https://leetcode.com/problems/maximum-good-subarray-sum/
 */

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long n=nums.size();
        vector<long long> prefix(n);
        map<long long, long long> mp;
        long long maxi=LLONG_MIN;
        
        prefix[0]=nums[0];

        for(long long i=1;i<n;i++){
            prefix[i]=prefix[i-1]+nums[i];
        }
        mp[nums[0]]=0;

        for(long long i=1;i<n;i++){
            long long target1=nums[i]-k;
            long long target2=nums[i]+k;

            if(mp.find(target1)!=mp.end()){
                long long currSum=prefix[i]-prefix[mp[target1]]+nums[mp[target1]];
                maxi=max(maxi,currSum);
            }
            if(mp.find(target2)!=mp.end()){
                long long currSum=prefix[i]-prefix[mp[target2]]+nums[mp[target2]];
                maxi=max(maxi,currSum);
            }
            if(mp.find(nums[i])!=mp.end()){
                if(prefix[i]>=prefix[mp[nums[i]]]) continue;
            }
            mp[nums[i]]=i;
        }

        if(maxi==LLONG_MIN){
            return 0;
        }
        return maxi;

    }
};