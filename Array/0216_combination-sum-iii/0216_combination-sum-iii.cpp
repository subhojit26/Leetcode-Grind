/*
 * Problem  : 216. Combination Sum III
 * Difficulty: Medium
 * Topics   : Array, Backtracking
 * URL      : https://leetcode.com/problems/combination-sum-iii/
 */

class Solution {
public:
    void solver(int sum, int ind, vector<int> temp, int k, int n, set<vector<int>> &res){
        if(ind>9){
            return;
        }
        if(temp.size()==k){
            if(sum==n){
                res.insert(temp);
            }
            return;
        }

        if(sum+ind<=n){
            temp.push_back(ind);
            solver(sum+ind,ind+1,temp,k,n,res);
            temp.pop_back();
        }
        
        
        solver(sum,ind+1,temp,k,n,res);
        
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> temp;
        set<vector<int>> res;
        vector<vector<int>> ans;
        solver(0,1,temp,k,n,res);
        for(auto it:res){
            ans.push_back(it);
        }
        return ans;
    }
};