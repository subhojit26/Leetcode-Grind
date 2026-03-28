/*
 * Problem  : 1744. Number of Ways to Form a Target String Given a Dictionary
 * Difficulty: Hard
 * Topics   : Array, String, Dynamic Programming
 * URL      : https://leetcode.com/problems/number-of-ways-to-form-a-target-string-given-a-dictionary/
 */

class Solution {
public:
    int solver(int pos, int ind, vector<string>& words, map<int, map<char, int>>& mp, string& target, int n, int len, vector<vector<int>>& dp) {
        const int MOD = 1000000007;
        if (ind == target.length()) {
            return 1;
        }
        if (pos == len) {
            return 0;
        }
        if (dp[pos][ind] != -1) {
            return dp[pos][ind];
        }
        
        char currentChar = target[ind];
        
        int take = 0;
        if (mp[pos].count(currentChar)) {
            take = (1LL * mp[pos][currentChar] * solver(pos + 1, ind + 1, words, mp, target, n, len, dp)) % MOD;
        }
        
        int skip = solver(pos + 1, ind, words, mp, target, n, len, dp);
        
        return dp[pos][ind] = (take + skip) % MOD;
    }
    
    int numWays(vector<string>& words, string target) {
        map<int, map<char, int>> mp;
        int n = words.size();
        int len = words[0].length();
        
        for (int i = 0; i < len; i++) {
            for (int j = 0; j < n; j++) {
                mp[i][words[j][i]]++;
            }
        }
        
        int targetLen = target.length();
        
        vector<vector<int>> dp(len, vector<int>(targetLen, -1));
        
        return solver(0, 0, words, mp, target, n, len, dp);
    }
};
