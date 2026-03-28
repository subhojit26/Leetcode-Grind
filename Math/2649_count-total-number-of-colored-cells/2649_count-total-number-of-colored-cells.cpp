/*
 * Problem  : 2649. Count Total Number of Colored Cells
 * Difficulty: Medium
 * Topics   : Math
 * URL      : https://leetcode.com/problems/count-total-number-of-colored-cells/
 */

class Solution {
public:
    long long coloredCells(long long int n) {
        //long long int ans=
        long long int n1=(long long int)n;
        return (n1)*(n1)+(n1-1)*(n1-1);
    }
};