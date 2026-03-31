/*
 * Problem  : 1250. Longest Common Subsequence
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming
 * URL      : https://leetcode.com/problems/longest-common-subsequence/
 */

class Solution {
public:
    int solver(int i, int j, string text1, string text2){
        if(i<0 || j<0){
            return 0;
        }

        if(text1[i]==text2[j]){
            cout<<text1[i];
            return 1+solver(i-1,j-1,text1,text2);
        }
        return max(solver(i-1,j,text1,text2),solver(i,j-1,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.length();
        int m=text2.length();

        return solver(n-1,m-1,text1,text2);
    }
};