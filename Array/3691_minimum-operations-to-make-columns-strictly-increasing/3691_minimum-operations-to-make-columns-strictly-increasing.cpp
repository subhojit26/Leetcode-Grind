/*
 * Problem  : 3691. Minimum Operations to Make Columns Strictly Increasing
 * Difficulty: Easy
 * Topics   : Array, Greedy, Matrix
 * URL      : https://leetcode.com/problems/minimum-operations-to-make-columns-strictly-increasing/
 */

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int operation = 0;
        for (int i = 0;i<grid[0].size();i++){  
            for (int j = 1;j<grid.size();j++){ 
                if (grid[j][i]<=grid[j-1][i]){
                    int increment=(grid[j-1][i]-grid[j][i])+1;
                    operation+=increment;
                    grid[j][i]=grid[j-1][i]+1;  
                }
            }
        }
        return operation;
    }
};
