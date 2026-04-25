/*
 * Problem  : 22. Generate Parentheses
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming, Backtracking
 * URL      : https://leetcode.com/problems/generate-parentheses/
 */

class Solution {
public:
    void solver(int o, int c, int n, string temp, vector<string> &ans){
        if(o==c && o+c==2*n){
            ans.push_back(temp);
        }
        cout<<temp<<" ";

        if(o<n){
            solver(o+1, c, n, temp+"(", ans);
        }
        if(c<o){
            solver(o,c+1,n,temp+")",ans);
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp="";
        vector<string> ans;
        solver(0,0,n,temp,ans);
        return ans;
    }
};