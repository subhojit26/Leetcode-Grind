/*
 * Problem  : 17. Letter Combinations of a Phone Number
 * Difficulty: Medium
 * Topics   : Hash Table, String, Backtracking
 * URL      : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution {
public:
    void solver(string digits, string res, int ind, vector<string> mapping, vector<string> &ans){
        if(ind==digits.length()){
            ans.push_back(res);
            return;
        }

        string letters=mapping[digits[ind]-'0'];
        for(char ch:letters){
            solver(digits,res+ch,ind+1,mapping,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> mapping={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        if(digits.empty()){
            return {};
        }
        solver(digits,"",0,mapping,ans);
        return ans;
    }
};