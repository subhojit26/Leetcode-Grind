/*
 * Problem  : 3620. Maximum Number of Distinct Elements After Operations
 * Difficulty: Medium
 * Topics   : Array, Greedy, Sorting
 * URL      : https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations/
 */

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long>minVals(n),maxVals(n);
        for(int i = 0; i < n; i++) {
            minVals[i]=(long long)nums[i]-k;
            maxVals[i]=(long long)nums[i]+k;
        }
        int count=1;  
        long long curr=minVals[0];  
        for(int i=1;i<n;i++) {
            if(minVals[i]>curr+1) {
                curr=minVals[i];
                count++;
            }
            else if(curr+1<=maxVals[i]) {
                curr++;
                count++;
            }
        }
        
        return count;
    }
};