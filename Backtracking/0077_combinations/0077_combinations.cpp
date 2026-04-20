/*
 * Problem  : 77. Combinations
 * Difficulty: Medium
 * Topics   : Backtracking
 * URL      : https://leetcode.com/problems/combinations/
 */

class Solution {
public:
    void solver(int i, int n, int k, vector<int> &temp, vector<vector<int>> &ans){
        if(i>n+1){
            return;
        }
        if(temp.size()==k){
            ans.push_back(temp);
            return;
        }

        for(int it=i;it<=n;it++){
            temp.push_back(it);
            solver(it+1,n,k,temp,ans);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> temp;
        vector<vector<int>> ans;
        solver(1,n,k,temp,ans);
        return ans;
    }
};