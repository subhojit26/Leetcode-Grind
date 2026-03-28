/*
 * Problem  : 55. Jump Game
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Greedy
 * URL      : https://leetcode.com/problems/jump-game/
 */

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest=0;
        for(int i=0;i<nums.size();i++){
            if(i>farthest) return false;
            farthest=max(farthest,i+nums[i]);
        }
        return true;
    }
};