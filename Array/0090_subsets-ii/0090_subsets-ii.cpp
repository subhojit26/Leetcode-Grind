/*
 * Problem  : 90. Subsets II
 * Difficulty: Medium
 * Topics   : Array, Backtracking, Bit Manipulation
 * URL      : https://leetcode.com/problems/subsets-ii/
 */

class Solution {
public:

    void solve(vector<int> nums, int ind, vector<int> temp, set<vector<int>> &st){
        if(ind==nums.size()){
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return;
        }
        temp.push_back(nums[ind]);
        solve(nums,ind+1,temp,st);
        temp.pop_back();
        solve(nums,ind+1,temp,st);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> st;
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,temp,st);
        while(!st.empty()){
            vector<int> x=*(st.begin());
            st.erase(x);
            ans.push_back(x);
        }
        return ans;
    }
};