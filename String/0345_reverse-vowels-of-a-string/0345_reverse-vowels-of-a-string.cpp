/*
 * Problem  : 345. Reverse Vowels of a String
 * Difficulty: Easy
 * Topics   : Two Pointers, String
 * URL      : https://leetcode.com/problems/reverse-vowels-of-a-string/
 */

class Solution {
public:
    string reverseVowels(string s) {
        string temp="";
        int len=s.length();
        for(int i=0;i<len;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                temp=s[i]+temp;
            }
        }
        int j=0;
        for(int i=0;i<len;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                s[i]=temp[j++];
            }
        }
        return s;
    }
};