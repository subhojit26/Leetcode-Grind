/*
 * Problem  : 392. Is Subsequence
 * Difficulty: Easy
 * Topics   : Two Pointers, String, Dynamic Programming
 * URL      : https://leetcode.com/problems/is-subsequence/
 */

class Solution {
public:
    int solver(string s, string t, int i,int j){
        if(i<0){
            return 1;
        }
        if(j<0){
            return 0;
        }

        if(s[i]==t[j]){
            return solver(s,t,i-1,j-1);
        }
        return solver(s,t,i,j-1);
    }
    bool isSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();

        return solver(s,t,n-1,m-1);
    }
};