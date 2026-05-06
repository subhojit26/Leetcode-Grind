/*
 * Problem  : 1972. Rotating the Box
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, Matrix
 * URL      : https://leetcode.com/problems/rotating-the-box/
 */

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m=boxGrid.size();
        int n=boxGrid[0].size();

        for(int i=0;i<m;i++){
            int empty=n-1;
            for(int j=n-1;j>=0;j--){
                if(boxGrid[i][j]=='*'){
                    empty=j-1;
                }else if(boxGrid[i][j]=='#'){
                    swap(boxGrid[i][j],boxGrid[i][empty]);
                    empty--;
                }
            }
        }
        vector<vector<char>> res(n,vector<char>(m,'.'));
        for(int i=0;i<n;i++){
            for(int j=m-1;j>=0;j--){
                res[i][m-j-1]=boxGrid[j][i];
            }
        }

        return res;

    }
};