/*
 * Problem  : 39. Combination Sum
 * Difficulty: Medium
 * Topics   : Array, Backtracking
 * URL      : https://leetcode.com/problems/combination-sum/
 */

class Solution {
public:
    void solver(int ind, int sum, vector<int> &candidates, int target, vector<int> &temp, set<vector<int>> &st){
        if(sum > target) return;
        if(ind==candidates.size()){
            if(sum==target){
                st.insert(temp);
            }
            
            return;
        }
        temp.push_back(candidates[ind]);
        solver(ind, sum+candidates[ind], candidates, target, temp, st);
        temp.pop_back();
        solver(ind+1,sum,candidates, target, temp, st);

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        vector<vector<int>> ans;
        set<vector<int>> st;
        solver(0, 0, candidates, target, temp, st);
        for(auto it: st){
            ans.push_back(it);
        }
        return ans;
    }
};