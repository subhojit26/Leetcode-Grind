/*
 * Problem  : 131. Palindrome Partitioning
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming, Backtracking
 * URL      : https://leetcode.com/problems/palindrome-partitioning/
 */

class Solution {
public:
    bool isPalindrome(string str){
        int l=0;
        int r=str.length()-1;
        while(l<=r){
            if(str[l]!=str[r]){
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
    void solver(int ind, string s, vector<vector<string>> &ans, vector<string> temp){
        if(ind==s.length()){
            ans.push_back(temp);
            return;
        }

        for(int i=ind;i<s.length();i++){
            string res=s.substr(ind,i-ind+1);
            if(isPalindrome(res)){
                temp.push_back(res);
                solver(i+1,s,ans,temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solver(0, s, ans, temp);
        return ans;
    }
};