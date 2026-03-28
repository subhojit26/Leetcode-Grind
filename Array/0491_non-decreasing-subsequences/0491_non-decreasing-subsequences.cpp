/*
 * Problem  : 491. Non-decreasing Subsequences
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Backtracking, Bit Manipulation
 * URL      : https://leetcode.com/problems/non-decreasing-subsequences/
 */

class Solution {
public:
    void solver(int ind, vector<vector<int>> &ans, vector<int> &temp, vector<int> &nums) {
        if (temp.size() >= 2) {
            ans.push_back(temp);
        }
        

        unordered_set<int> used; // to prevent duplicates at this level

        for (int i = ind; i < nums.size(); ++i) {
            if ((temp.empty() || nums[i]>=temp.back()) && used.find(nums[i]) == used.end()) {
                used.insert(nums[i]);
                temp.push_back(nums[i]);
                solver(i + 1, ans, temp, nums);
                temp.pop_back();
            }
        }
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solver(0, ans, temp, nums);
        return ans;
    }
};
