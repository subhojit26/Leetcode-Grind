/*
 * Problem  : 3. Longest Substring Without Repeating Characters
 * Difficulty: Medium
 * Topics   : Hash Table, String, Sliding Window
 * URL      : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int len=s.length();

        int l=0;
        int r=0;
        int res=INT_MIN;
        while(r<len){
            mp[s[r]]++;
            while(mp[s[r]]>1 && l<=r){
                mp[s[l]]--;
                l++;
            }
            res=max(res,r-l+1);
            r++;
        }
        return res;
    }
};