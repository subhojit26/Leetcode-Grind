/*
 * Problem  : 242. Valid Anagram
 * Difficulty: Easy
 * Topics   : Hash Table, String, Sorting
 * URL      : https://leetcode.com/problems/valid-anagram/
 */

class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<s.length();i++){
            mp1[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mp2[t[i]]++;
        }
        return mp1==mp2;
    }
};