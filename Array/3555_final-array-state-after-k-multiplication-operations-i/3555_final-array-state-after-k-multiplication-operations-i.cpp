/*
 * Problem  : 3555. Final Array State After K Multiplication Operations I
 * Difficulty: Easy
 * Topics   : Array, Math, Heap (Priority Queue), Simulation
 * URL      : https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
 */

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n=nums.size();
        for(int j=0;j<k;j++){
            int ind;
            int mn=INT_MAX;
            for(int i=0;i<n;i++){
                if(nums[i]<mn){
                    mn=nums[i];
                    ind=i;
                }
            }
            nums[ind]=mn*multiplier;
        }
        return nums;
    }
};