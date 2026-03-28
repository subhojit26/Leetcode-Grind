/*
 * Problem  : 3708. Zigzag Grid Traversal With Skip
 * Difficulty: Easy
 * Topics   : Array, Matrix, Simulation
 * URL      : https://leetcode.com/problems/zigzag-grid-traversal-with-skip/
 */

class Solution {
public:
    vector<int> zigzagTraversal(vector<vector<int>>& grid) {
        vector<int> zigzagOrder;
        int rows=grid.size();
        int cols=grid[0].size();
        for (int i=0;i<rows;++i) {
            if(i%2==0){
                for(int j=0;j<cols;++j) {
                    zigzagOrder.push_back(grid[i][j]);
                }
            }else{
                for(int j=cols-1;j>=0;--j) {
                    zigzagOrder.push_back(grid[i][j]);
                }
            }
        }
        vector<int> result;
        for (int i=0;i<zigzagOrder.size();i+=2) {
            result.push_back(zigzagOrder[i]);
        }

        return result;
    }
};
