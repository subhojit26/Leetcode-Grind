/*
 * Problem  : 205. Isomorphic Strings
 * Difficulty: Easy
 * Topics   : Hash Table, String
 * URL      : https://leetcode.com/problems/isomorphic-strings/
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1,mp2;
        int l=s.length();
        int i=0,j=0;
        while(i<l){
            if(mp1.find(s[i])!=mp1.end()){
                if(mp1[s[i]]!=t[i]){
                    return false;
                }
            }else{
                mp1[s[i]]=t[i];
            }
            i++;
        }
        while(j<l){
            if(mp2.find(t[j])!=mp2.end()){
                if(mp2[t[j]]!=s[j]){
                    return false;
                }
            }else{
                mp2[t[j]]=s[j];
            }
            j++;
        }
        return true;
    }
};