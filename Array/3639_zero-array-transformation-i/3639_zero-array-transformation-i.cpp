/*
 * Problem  : 3639. Zero Array Transformation I
 * Difficulty: Medium
 * Topics   : Array, Prefix Sum
 * URL      : https://leetcode.com/problems/zero-array-transformation-i/
 */

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int> delta(n+1,0);
        vector<int> operations;
        for(int i=0;i<queries.size();i++){
            int left=queries[i][0];
            int right=queries[i][1];
            delta[left]+=1;
            delta[right+1]-=1;
        }
        int curr=0;
        for(auto it:delta){
            curr+=it;
            operations.push_back(curr);
        }
        for(int i=0;i<n;i++){
            if(operations[i]<nums[i]){
                return false;
            }
        }
        return true;

    }
};