/*
 * Problem  : 46. Permutations
 * Difficulty: Medium
 * Topics   : Array, Backtracking
 * URL      : https://leetcode.com/problems/permutations/
 */

class Solution {
public:
    void solve(vector<int> nums, int freq[], vector<int> temp, vector<vector<int>> &ans){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                temp.push_back(nums[i]);
                freq[i]=1;
                solve(nums,freq,temp,ans);
                freq[i]=0;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++)
            freq[i] = 0;
        solve(nums,freq,temp,ans);
        return ans;
    }
};