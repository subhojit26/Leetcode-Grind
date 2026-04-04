/*
 * Problem  : 1441. Minimum Flips to Make a OR b Equal to c
 * Difficulty: Medium
 * Topics   : Bit Manipulation
 * URL      : https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 */

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(a > 0 || b > 0 || c > 0){
            int la=a&1;
            int lb=b&1;
            int lc=c&1;

            if(lc==1){
                if(la!=1 && lb!=1){
                    count++;
                }
            }else{
                if(la==1 && lb==1){
                    count+=2;
                }else if(la==1 || lb==1){
                    count++;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;
    }
};