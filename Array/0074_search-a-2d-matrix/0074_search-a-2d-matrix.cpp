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
            vector<int>curr=matrix[i];
            if(target>=curr[0] && target<=curr[n-1]){
                int left=0;
                int right=n-1;
                while(left<=right){
                    int mid=(left+right)/2;
                    if(curr[mid]==target){
                        return true;
                    }else if(curr[mid]<target){
                        left=mid+1;
                    }else{
                        right=mid-1;
                    }
                }
            }else if(target>curr[n-1]){
                continue;
            }
        }
        return false;
    }
};