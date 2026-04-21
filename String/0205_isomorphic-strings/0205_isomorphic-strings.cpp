/*
 * Problem  : 205. Isomorphic Strings
 * Difficulty: Easy
 * Topics   : Hash Table, String
 * URL      : https://leetcode.com/problems/isomorphic-strings/
 */

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        int l=s.length();
        int i=0;
        while(i<l){
            if(mp.find(s[i])!=mp.end()){
                if(mp[s[i]]!=t[i]){
                    return false;
                }
            }else{
                mp[s[i]]=t[i];
            }
            i++;
        }
        return true;
    }
};