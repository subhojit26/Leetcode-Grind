/*
 * Problem  : 2428. Equal Row and Column Pairs
 * Difficulty: Medium
 * Topics   : Array, Hash Table, Matrix, Simulation
 * URL      : https://leetcode.com/problems/equal-row-and-column-pairs/
 */

class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        map<vector<int>,int> mpr;
        map<vector<int>,int> mpc;
        for(auto it:grid){
            mpr[it]++;
        }
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(grid[j][i]);
            }
            if(mpr.find(temp)!=mpr.end()){
                count+=mpr[temp];
            }
        }
        return count;
    }
};