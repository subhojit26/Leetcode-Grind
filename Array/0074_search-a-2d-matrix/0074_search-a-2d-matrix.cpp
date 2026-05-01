/*
 * Problem  : 74. Search a 2D Matrix
 * Difficulty: Medium
 * Topics   : Array, Binary Search, Matrix
 * URL      : https://leetcode.com/problems/search-a-2d-matrix/
 */

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();

        for(int i=0;i<m;i++){
            int low=matrix[i][0];
            int high=matrix[i][n-1];
            if(target>=low && target<=high){
                int l=0;
                int h=n-1;
                while(l<=h){
                    int mid=(l+h)/2;
                    if(matrix[i][mid]==target){
                        return true;
                    }else if(matrix[i][mid]>target){
                        h=mid-1;
                    }else{
                        l=mid+1;
                    }
                }
            }
        }
        return false;
    }
};