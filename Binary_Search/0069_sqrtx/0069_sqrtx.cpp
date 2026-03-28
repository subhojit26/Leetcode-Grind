/*
 * Problem  : 69. Sqrt(x)
 * Difficulty: Easy
 * Topics   : Math, Binary Search
 * URL      : https://leetcode.com/problems/sqrtx/
 */

class Solution {
public:
    int mySqrt(int x) {
        int left=1;
        int right=x;
        while(left<=right){
            int mid=left+(right-left)/2;
            if(mid==x/mid){
                return mid;
            }else if(mid<x/mid){
                left=mid+1;
            }else{
                right=mid-1;
            }
        }
        return right;
    }
};