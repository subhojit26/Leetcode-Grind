/*
 * Problem  : 198. House Robber
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming
 * URL      : https://leetcode.com/problems/house-robber/
 */

class Solution {
public:
    int solver(int ind, vector<int> &nums){
        if(ind>=nums.size()){
            return 0;
        }

        int take=nums[ind]+solver(ind+2,nums);
        int notTake=solver(ind+1,nums);
        return max(take,notTake);
    }
    int rob(vector<int>& nums) {
        return solver(0,nums);
    }
};