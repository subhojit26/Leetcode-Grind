/*
 * Problem  : 2232. Adding Spaces to a String
 * Difficulty: Medium
 * Topics   : Array, Two Pointers, String, Simulation
 * URL      : https://leetcode.com/problems/adding-spaces-to-a-string/
 */

class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans="";
        int k=0;
        for(int i=0;i<s.length();i++){
            if(k<spaces.size() && i==spaces[k]){
                ans.push_back(' ');
                k++;
            }
            ans.push_back(s[i]);
        }
        return ans;
    }
};