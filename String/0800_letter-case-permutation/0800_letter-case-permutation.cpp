/*
 * Problem  : 800. Letter Case Permutation
 * Difficulty: Medium
 * Topics   : String, Backtracking, Bit Manipulation
 * URL      : https://leetcode.com/problems/letter-case-permutation/
 */

class Solution {
public:
    void solve(int i, string s, set<string> &ans){
        if(i==s.length()){
            ans.insert(s);
            return;
        }
        if(s[i]>='a' && s[i]<='z'){
            s[i]=(char)toupper(s[i]);
        }
        else if(s[i]>='A' && s[i]<='Z'){
            s[i]=(char)tolower(s[i]);
        }
        solve(i+1,s,ans);
        if(s[i]>='a' && s[i]<='z'){
            s[i]=(char)toupper(s[i]);
        }
        else if(s[i]>='A' && s[i]<='Z'){
            s[i]=(char)tolower(s[i]);
        }
        solve(i+1,s,ans);

    }
    vector<string> letterCasePermutation(string s) {
        set<string> ans;
        vector<string> res;
        solve(0,s,ans);
        while(!ans.empty()){
            string t=*(ans.begin());
            ans.erase(t);
            res.push_back(t);
        }
        return res;
    }
};