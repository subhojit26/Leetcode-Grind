/*
 * Problem  : 46. Permutations
 * Difficulty: Medium
 * Topics   : Array, Backtracking
 * URL      : https://leetcode.com/problems/permutations/
 */

class Solution {
public:
    void solver(vector<int> nums,vector<int> freq, vector<int> &temp, vector<vector<int>> & ans){
        
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++){
            if(freq[i]==0){
                temp.push_back(nums[i]);
                freq[i]=1;
                solver(nums,freq,temp,ans);
                freq[i]=0;
                temp.pop_back();
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<vector<int>> ans;
        int n=nums.size();
        vector<int> freq(n,0);
        solver(nums,freq, temp, ans);
        return ans;
    }
};