/*
 * Problem  : 1367. Maximum Height by Stacking Cuboids 
 * Difficulty: Hard
 * Topics   : Array, Dynamic Programming, Sorting
 * URL      : https://leetcode.com/problems/maximum-height-by-stacking-cuboids/
 */

class Solution {
public:
    int solver(int curr,int prev, vector<vector<int>>& cuboids){
        if(curr==cuboids.size()){
            return 0;
        }
        int take=0;
        if(prev==-1 || cuboids[curr][0]>=cuboids[prev][0] && cuboids[curr][1]>=cuboids[prev][1] && cuboids[curr][2]>=cuboids[prev][2]){
            take= cuboids[curr][2]+solver(curr+1,curr,cuboids);
        }
        int nottake=solver(curr+1,prev,cuboids);
        return max(take,nottake);
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for(auto &cuboid:cuboids){
            sort(cuboid.begin(),cuboid.end());
        }
        sort(cuboids.begin(),cuboids.end());
        return solver(0,-1,cuboids);

    }
};