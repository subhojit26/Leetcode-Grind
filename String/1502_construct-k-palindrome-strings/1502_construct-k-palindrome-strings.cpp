/*
 * Problem  : 1502. Construct K Palindrome Strings
 * Difficulty: Medium
 * Topics   : Hash Table, String, Greedy, Counting
 * URL      : https://leetcode.com/problems/construct-k-palindrome-strings/
 */

class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char, int> mp;
        if(s.length()<k){
            return false;
        }
        int odd=0;
        for(int i=0;i<s.length();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.second%2==1){
                odd++;
            }
        }
        return odd>k?false:true;
    }
};