/*
 * Problem  : 2755. Extra Characters in a String
 * Difficulty: Medium
 * Topics   : Array, Hash Table, String, Dynamic Programming, Trie
 * URL      : https://leetcode.com/problems/extra-characters-in-a-string/
 */

class Solution {
public:
    int solve(string s, int ind, unordered_map<string, int> mp, unordered_map<int, int> &memo){
        if(ind==s.length()){
            return 0;
        }
        if(memo.find(ind)!=memo.end()){
            return memo[ind];
        }
        int extra=INT_MAX;
        string tmp="";

        for(int i=ind;i<s.length();i++){
            tmp+=s[i];

            if(mp.find(tmp)!=mp.end()){
                extra=min(extra, solve(s,i+1,mp,memo));
            }
        }
        extra=min(extra, 1+solve(s, ind+1,mp,memo));
        return memo[ind]=extra;

    }
    int minExtraChar(string s, vector<string>& dictionary) {
       int ind=0;
       unordered_map<string, int> mp;
       for(auto &val:dictionary){
            mp[val]++;
       }
       unordered_map<int, int> mem;

       return solve(s, ind, mp, mem);
    }
};