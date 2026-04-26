/*
 * Problem  : 50. Pow(x, n)
 * Difficulty: Medium
 * Topics   : Math, Recursion
 * URL      : https://leetcode.com/problems/powx-n/
 */

class Solution {
public:
    double solver(double x, long long n){
        if(n==0){
            return 1.0;
        }

        if(n<0){
            return 1.0/solver(x,-n);
        }

        if(n%2==0){
            return solver(x*x,n/2);
        }else{
            return x*solver(x,n-1);
        }
    }
    double myPow(double x, int n) {
        return solver(x, (long long)n);

    }
};