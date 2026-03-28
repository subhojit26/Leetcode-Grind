/*
 * Problem  : 1894. Merge Strings Alternately
 * Difficulty: Easy
 * Topics   : Two Pointers, String
 * URL      : https://leetcode.com/problems/merge-strings-alternately/
 */

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int n=word1.length();
        int m=word2.length();
        int i=0;
        int j=0;
        string ans="";
        while(i<n && j<m){
            ans=ans+word1[i++];
            ans=ans+word2[j++];
        }
        if(i<n){
            ans=ans+word1.substr(i);
        }
        if(j<m){
            ans=ans+word2.substr(j);
        }
        return ans;
    }
};