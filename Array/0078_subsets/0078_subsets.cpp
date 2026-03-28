/*
 * Problem  : 78. Subsets
 * Difficulty: Medium
 * Topics   : Array, Backtracking, Bit Manipulation
 * URL      : https://leetcode.com/problems/subsets/
 */

class Solution {
public:
    void solve(vector<int>nums, int ind, vector<vector<int>> &ans,vector<int> temp){
        if(ind==nums.size()){
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(nums,ind+1,ans,temp);
        temp.pop_back();
        solve(nums,ind+1,ans,temp);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,ans,temp);
        return ans;
    }
};