/*
 * Problem  : 2015. Determine Whether Matrix Can Be Obtained By Rotation
 * Difficulty: Easy
 * Topics   : Array, Matrix
 * URL      : https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/
 */

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target){
            return true;
        }
        int n=mat.size();
        for(int r=0;r<4;r++){
            for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                    swap(mat[i][j],mat[j][i]);
                }
            }
            for(int i=0;i<n;i++){
                reverse(mat[i].begin(),mat[i].end());
            }
            if(mat==target){
                return true;
            }
        }
        return false;
    }
};