/*
 * Problem  : 45. Jump Game II
 * Difficulty: Medium
 * Topics   : Array, Dynamic Programming, Greedy
 * URL      : https://leetcode.com/problems/jump-game-ii/
 */

class Solution {
public:
    int jump(vector<int>& nums) {
        int near=0;
        int far=0;
        int steps=0;
        if(nums.size()==1){
            return 0;
        }
        while(far<nums.size()-1){
            int farthest=0;
            for(int i=near;i<=far;i++){
                farthest=max(i+nums[i],farthest);
            }
            near=far+1;
            far=farthest;
            steps++;
        }
        return steps;
    }
};