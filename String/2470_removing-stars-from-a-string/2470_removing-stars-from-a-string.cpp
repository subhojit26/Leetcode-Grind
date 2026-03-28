/*
 * Problem  : 2470. Removing Stars From a String
 * Difficulty: Medium
 * Topics   : String, Stack, Simulation
 * URL      : https://leetcode.com/problems/removing-stars-from-a-string/
 */

class Solution {
public:
    string removeStars(string s) {
        string res="";
        int l=s.length();
        for(int i=0;i<l;i++){
            char ch=s[i];
            if(ch!='*'){
                res.push_back(ch);
            }else{
                if(!res.empty()){
                    res.pop_back();
                }
            }
        }
        return res;
    }
};