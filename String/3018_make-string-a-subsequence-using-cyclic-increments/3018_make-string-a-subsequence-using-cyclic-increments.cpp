/*
 * Problem  : 3018. Make String a Subsequence Using Cyclic Increments
 * Difficulty: Medium
 * Topics   : Two Pointers, String
 * URL      : https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
 */

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i=0;
        int j=0;
        int c=0;
        int l1=str1.length();
        int l2=str2.length();

        while(i<l1 && j<l2){
            if(str1[i]==str2[j] ||(str2[j] - str1[i] + 26) % 26 == 1){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==str2.length()){
            return true;
        }
        return false;
    }
};