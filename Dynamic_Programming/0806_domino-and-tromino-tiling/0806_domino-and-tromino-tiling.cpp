/*
 * Problem  : 806. Domino and Tromino Tiling
 * Difficulty: Medium
 * Topics   : Dynamic Programming
 * URL      : https://leetcode.com/problems/domino-and-tromino-tiling/
 */

class Solution {
public:
    int solver(int i, int n, bool flag){
        if(i==n){
            return !flag;
        }
        if(i>n){
            return 0;
        }
        if(flag){
            return (solver(i+1,n,true)+solver(i+1,n,false))%1000000007;
        }
        return (solver(i+1,n,false)+2L*solver(i+2,n,true))%1000000007;
    }
    int numTilings(int n) {
        return solver(0,n,false);
    }
};