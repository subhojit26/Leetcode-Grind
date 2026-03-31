/*
 * Problem  : 1236. N-th Tribonacci Number
 * Difficulty: Easy
 * Topics   : Math, Dynamic Programming, Memoization
 * URL      : https://leetcode.com/problems/n-th-tribonacci-number/
 */

class Solution {
public:
    int solver(int n){
        if(n<=0){
            return 0;
        }
        if(n==1){
            return 1;
        }
        if(n==2){
            return 1;
        }
        return solver(n-1)+solver(n-2)+solver(n-3);
    }
    int tribonacci(int n) {
        return solver(n);
    }
};