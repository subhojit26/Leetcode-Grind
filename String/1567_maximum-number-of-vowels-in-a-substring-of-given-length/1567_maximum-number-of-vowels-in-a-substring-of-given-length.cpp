/*
 * Problem  : 1567. Maximum Number of Vowels in a Substring of Given Length
 * Difficulty: Medium
 * Topics   : String, Sliding Window
 * URL      : https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/
 */

class Solution {
public:
    int maxVowels(string s, int k) {
        int l=s.length();
        int i=0;
        int j=0;
        int mx=INT_MIN;
        int c=0;
        while(j<l){
            if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
                c++;
            }
            if(j-i+1==k){
                mx=max(mx,c);
                if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                    c--;
                }
                i++;
            }
            j++;
        }
        return mx;
    }
};