/*
 * Problem  : 139. Word Break
 * Difficulty: Medium
 * Topics   : Array, Hash Table, String, Dynamic Programming, Trie, Memoization
 * URL      : https://leetcode.com/problems/word-break/
 */

class Solution {
public:
    bool solver(int ind, string &s, vector<string> &wordDict, unordered_map<int, bool> &dp){
        if(ind==s.length()){
            return true;
        }
        if(dp.count(ind)){
            return dp[ind];
        }
        for(int i=ind;i<s.length();i++){
            string temp=s.substr(ind,i-ind+1);
            if(find(wordDict.begin(),wordDict.end(),temp)!=wordDict.end()){
                cout<<temp<<endl;
                if(solver(i+1,s,wordDict,dp)){
                    return dp[ind]=true;
                }
            }
        }
        return dp[ind]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> dp;
        return solver(0,s,wordDict,dp);
    }
};