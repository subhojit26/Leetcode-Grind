/*
 * Problem  : 5. Longest Palindromic Substring
 * Difficulty: Medium
 * Topics   : Two Pointers, String, Dynamic Programming
 * URL      : https://leetcode.com/problems/longest-palindromic-substring/
 */

class Solution {
public:
    int solve(string s, int l, int r){
        while(l>=0 && r<s.length() && s[l]==s[r]){
            l--;
            r++;
        }
        return r-l-1;
    }
    string longestPalindrome(string s) {
        int l=s.length();
        int st=-1;
        int ans=INT_MIN;
        for(int i=0;i<l;i++){
            int len1=solve(s,i,i);
            int len2=solve(s,i,i+1);
            int t=max(len1,len2);
            if(t>ans){
                ans=t;
                st=i-(t-1)/2;
            }
        }
        return s.substr(st,ans);
    }
};