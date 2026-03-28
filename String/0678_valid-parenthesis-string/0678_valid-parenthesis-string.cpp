/*
 * Problem  : 678. Valid Parenthesis String
 * Difficulty: Medium
 * Topics   : String, Dynamic Programming, Stack, Greedy
 * URL      : https://leetcode.com/problems/valid-parenthesis-string/
 */

class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        int ind=0;
        int low=0;
        int high=0;
        while(ind<n){
            if(s[ind]=='('){
                low++;
                high++;
            }else if(s[ind]==')'){
                low--;
                high--;
            }else{
                low--;
                high++;
            }
            if(low<0) low=0;
            if(high<0)return false;
            ind++;
        }
        return (low==0);
    }
};